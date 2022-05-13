#include "../headfile/question2.h"
#include <stdio.h>
#include <stdlib.h>

LoopSqueue *init_squeue()
{
    LoopSqueue *sq = malloc(sizeof(LoopSqueue));
    sq->front = 0;
    sq->rear = 0;
    return sq;
}
//判断是否为满
int is_full(LoopSqueue *sq)
{
    int x =(sq->rear+1)%MaxSize;
    if (x == sq->front)
    {
        printf("队列已满\n");
        return 1;
    }
    return 0;
}
// 元素个数
int squ_size(LoopSqueue* sq)
{
    int begin =sq->front;
    int size =0;
    for (; begin != sq->rear; begin++)
    {
        if(begin>(MaxSize-1))
            begin=0;
        size++;
    }
    return size;
}
//判断是否为空
int is_empty(LoopSqueue *sq)
{
    if (sq->front == sq->rear)
    {
        sq->front = 0;
        sq->rear = 0;
        printf("队列为空\n");
        return 1;
    }
    return 0;
}
//入队
int push_back_(LoopSqueue *sq, char c)
{
    if (is_full(sq))
    {
        return 0;
    }
    else
    {
        sq->data[sq->rear]=c;
        sq->rear=(sq->rear+1)%MaxSize;
        return 1;
    }

}
//出列
int pop_front(LoopSqueue *sq)
{
    if (is_empty(sq))
    {
        return 0;
    }
    else
    {
        char c = sq->data[sq->front];
        printf("出列元素是：%c\n", c);
        sq->front = (sq->front + 1) % MaxSize;
        return 1;
    }
}

void show_squ(LoopSqueue *sq)
{
    if (is_empty(sq))
    {
        return;
    }
    int begin = sq->front;
    for (; begin != sq->rear; begin++)
    {
        if(begin>(MaxSize-1))
            begin=0;
        printf("%c\t", sq->data[begin]);

    }
    printf("\n");
}