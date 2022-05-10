#include "question1.h"
#include <stdio.h>
#include <stdlib.h>
//初始化链表
PolyLode *poly_list_init()
{
    float x;
    int y;
    PolyLode *head = malloc(sizeof(PolyLode)); //多项式链表
    PolyLode *poly_item;
    head->next = NULL;
    poly_item = head;
    while (1)
    {
        printf("||输入回车进行下一次输入||其他字符结束输入||");
        char c = getchar();
        if (c == '\n')
        {
            poly_item->next = malloc(sizeof(PolyLode));
            poly_item = poly_item->next;
            scanf("%f%d", &x, &y);
            // fflush(stdin);
            getchar(); //清空缓存区
            poly_item->coef = x;
            poly_item->expo = y;
            poly_item->next = NULL;
        }
        else
        {
            getchar();
            break;
        }
    }
    return head;
}
//链表的长度
int poly_list_size(PolyLode *head)
{
    PolyLode *item = head;
    int x = 0;
    while (item->next != NULL)
    {
        ++x;
        item = item->next;
    }
    return x;
}
//链表的排序
void sort_list(PolyLode *head)
{
    int x = poly_list_size(head);
    // printf("list_size = %d\n", x);
    if (x < 2)
        return;
    PolyLode *h = head;
    PolyLode *p1;         //第一个节点
    PolyLode *p2;         //第二个节点
    PolyLode *end = NULL; // 尾节点
    while (1)
    {
        p1 = h->next;
        p2 = p1->next;
        if (p1->expo > p2->expo) //判断相邻节点的大小
        {
            PolyLode *temp = p2->next;
            h->next = p2;
            p2->next = p1;
            p1->next = temp;
        }
        if (h->next->next->next == end) //抵达尾部节点后的判断
        {
            end = h->next->next;
            if (end == head->next->next)
            {
                break; //所有冒泡结束 ，结束冒泡
            }
            h = head; //本轮冒泡结束，开启下一轮冒泡
            continue; //不能执行后面的代码
        }
        h = h->next; //重置
    }
}
//合并指数相同的多项式
static void remove_similar_poly(PolyLode *head)
{
    if (poly_list_size(head) < 2)
        return;
    sort_list(head);
    PolyLode *p1 = head->next;
    while (p1 != NULL)
    {
        if (p1->expo == p1->next->expo)
        {
            p1->coef = p1->coef + p1->next->coef; //合并
            PolyLode *temp = p1->next;
            p1->next = p1->next->next;
            free(temp);
        }
        p1 = p1->next;
    }
    printf("list_size = %d\n", poly_list_size(head));
}
// 2个多项式相加
PolyLode *add_poly_list(PolyLode *p1, PolyLode *p2)
{
    PolyLode *result = malloc(sizeof(PolyLode));
    result->next =NULL;
    PolyLode *h = result; //替身攻击
    PolyLode *temp;
    for (int i = 0; i < 2; i++)
    {
        if (i)
            temp = p1->next;
        else
            temp = p2->next;
        while (temp != NULL)
        {
            h->next = malloc(sizeof(PolyLode));
            h = h->next;
            h->coef = temp->coef;
            h->expo = temp->expo;
            h->next = NULL;
            temp = temp->next;
        }
    }
    remove_similar_poly(result);
    return result;
}
// 2个多项式相减
PolyLode *sub_poly_list(PolyLode *p1, PolyLode *p2)
{
    PolyLode *result = malloc(sizeof(PolyLode));
    PolyLode *h = result; //替身攻击
    PolyLode *temp;
    int flag = 1;
    for (int i = 0; i < 2; i++)
    {
        if (i)
            temp = p1->next;
        else
        {
            temp = p2->next;
            flag = -1;
        }
        while (temp != NULL)
        {
            h->next = malloc(sizeof(PolyLode));
            h = h->next;
            h->coef = temp->coef * flag;
            h->expo = temp->expo;
            h->next = NULL;
            temp = temp->next;
        }
    }
    remove_similar_poly(result);
    return result;
}

//输出链表
void show_poly_list(PolyLode *head)
{
    PolyLode *poly = head->next;
    while (poly != NULL)
    {
        //输出系数
        if (poly->expo == 0)
            printf("%g", poly->coef);
        else
        {
            if (poly->coef == 0)
                ;
            else if (poly->coef == 1)
                printf("+X");
            else if (poly->coef < 0)
                printf("%gX", poly->coef);
            else
                printf("+%gX", poly->coef);
            //输出指数
            if (poly->expo == 1)
                ;
            else
                printf("^%d", poly->expo);
        }
        poly = poly->next;
    }
    printf("\n");
}

void free_list(PolyLode *head)
{
    PolyLode *temp = head->next;
    free(head);
    while (temp != NULL)
    {
        head=temp->next;
        free(temp);
        temp = head;
    }
    printf("释放完毕");
}
