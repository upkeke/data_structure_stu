#include "..\headfile\question1.h"
#include "..\headfile\question2.h"
#include "..\headfile\question3.h"
#include "..\headfile\question4.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void question1()
{
    printf("第一个多项式\n");
    PolyLode *p1 = poly_list_init();
    printf("打印第一个多项式\n");
    show_poly_list(p1);

    printf("第二个多项式\n");
    PolyLode *p2 = poly_list_init();
    printf("打印第二个多项式\n");
    show_poly_list(p2);

    printf("排序第一个多项式\n");
    sort_list(p1);
    show_poly_list(p1);

    printf("排序第二个多项式\n");
    sort_list(p2);
    show_poly_list(p2);

    printf("相加\n");
    PolyLode *add_p = add_poly_list(p1, p2);
    printf("打印和\n");
    show_poly_list(add_p);

    printf("相减\n");
    PolyLode *sub_p = sub_poly_list(p1, p2);
    printf("打印差\n");
    show_poly_list(sub_p);

    free_list(p1);
    free_list(p2);
    free_list(add_p);
    free_list(sub_p);
    // free(p1);
}
void k2()
{
    printf("第一个多项式\n");
    PolyLode *p1 = poly_list_init();
    printf("打印第一个多项式\n");
    show_poly_list(p1);
    printf("个数%d", poly_list_size(p1));
    free_list(p1);
}
void k3()
{
    PolyLode x5 = {2, 3, NULL};
    PolyLode x4 = {-6, 2, &x5};
    PolyLode x3 = {2.1, 2, &x4};
    PolyLode x1 = {-3, 3, &x3};
    PolyLode x;
    x.next = &x1;
    PolyLode *h1 = &x;
    show_poly_list(h1);

    remove_similar_poly(h1);
    show_poly_list(h1);
    // PolyLode y3={-3,2,NULL} ;
    // PolyLode y2 ={15.,4,&y3};
    // PolyLode y1 ={7,3,&y2} ;
    // PolyLode y ;
    // y.next =&y1;
    // PolyLode *h2 = &y;

    // PolyLode* z=add_poly_list(h1,h2);
    // remove_similar_poly(z);
    // show_poly_list(z);
}
void k4()
{
    PolyLode *h1 = malloc(sizeof(PolyLode));
    PolyLode *p1 = malloc(sizeof(PolyLode));
    h1->next = p1;
    p1->coef = 2,
    p1->expo = 2,
    p1->next = malloc(sizeof(PolyLode));
    PolyLode *p2 = p1->next;
    p2->coef = 3.1;
    p2->expo = 3;
    p2->next = malloc(sizeof(PolyLode));
    PolyLode *p3 = p2->next;
    p3->coef = -1;
    p3->expo = 2;
    p3->next = NULL;
    show_poly_list(h1);
    remove_similar_poly(h1);
    show_poly_list(h1);

    // PolyLode *h2 = malloc(sizeof(PolyLode));
    // h2->next = NULL;
    // PolyLode *q1 = malloc(sizeof(PolyLode));
    // q1->coef = -1,
    // q1->expo = 2,
    // q1->next = malloc(sizeof(PolyLode));
    // PolyLode *q2 = p1->next;
    // q2->coef=7;
    // q2->expo=3;
}
void k5()
{
    ;
    // PolyLode *p1 =malloc(sizeof(PolyLode)){2.0,3,NULL};

    PolyLode *p1 = malloc(sizeof(PolyLode));
    p1->coef = 2.0;
    p1->expo = 3;
    p1->next = NULL;
    // printf("%d,%f",p1->expo,p1->coef);
}
void k6()
{
    int *x = malloc(sizeof(int) * 3);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x++;
    int a = *x;
    printf("%d\n", a);
    //     void * p1 =(int*)x-4;
    //     int *p = (int*)p1;
    //     *p=10;
    //     printf("%d",*p);
}
void k7()
{
    LoopSqueue sq;
    sq.front = 1;
    LoopSqueue *sqp = &sq;
    sqp->front++;
    printf("front = %d", sqp->front);
}
void question2()
{
    //初始化
    LoopSqueue *sq = init_squeue();
    //判断是否为空
    is_empty(sq);
    //入队
    for (int i = 65;; i++)
    {
        if (is_full(sq))
            break;
        push_back_(sq, i);
    }

    show_squ(sq);
    //出队
    pop_front(sq);
    for (int i = 0; i < 5; ++i)
        pop_front(sq);
    //输出元素格数
    printf("元素个数：%d\n", squ_size(sq));

    //入队4个元素
    for (int i = '1', j = 0; j < 4; i++, j++)
    {
        printf("%c\t", i);
        push_back_(sq, i);
    }
    //输出队列
    printf("\n");
    show_squ(sq);
}
void question3()
{
    treeNode *node = build_tree();
    printf("先序遍历:\t");
    each_root_left_right(node);
    printf("\n中序遍历:\t");
    each_left_root_right(node);
    printf("\n后序遍历:\t");
    each_left_right_root(node);
    printf("\n层次遍历:\t");
    init_each_treesque(node);
    printf("深度:\t%d\n", get_depth(node));
    printf("输出树的叶子:\t");
    show_tree_leaf(node);
    printf("\n输出树的非叶子:\t");
    noshow_tree_leaf(node);
    printf("\n二叉树的深拷贝target\n");
    treeNode *target = deep_copy_tree(node);
    printf("target层次遍历:\t");
    init_each_treesque(target);
    printf("析构树node:\t");
    free_tree(node);
    printf("\n析构树target:\t");
    free_tree(target);
}
void k8()
{
    treeNode *t1 = malloc(sizeof(treeNode));
    // treeNode *t2 = malloc(sizeof(t2));
    // treeNode *t3 = malloc(sizeof(char));
    // treeNode *t4 = malloc(sizeof(double));
    // t2->left= ctor_tnode('a',NULL,NULL);
    // t2->right=NULL;

    printf("t1指向的空间大小%d", (int)sizeof(*t1));
    // printf("t3指向的空间大小%llu,\nt4指向的空间大小%llu,", sizeof(*t3), sizeof(*t4));
}
void k9()
{
    int x[10][10];
    int num = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            x[i][j] = num;
            num++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // int *begin = (int *)(&x[0][0]); //方法1
    int *begin = (int *)x; //方法二，和上面等价

    printf("%d\t%d", *(begin + 52), x[5][2]);
}
void k10()
{
    // int *x =malloc(sizeof(int)*10);
    // printf("\t%d",__SIZEOF_POINTER__);

    // memset(x,0,size(x));
    // memset(x+4,3,5);
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d\t",x[i]);
    // }
    int x[5] = {1, 2, 3, 4, 5};
    int y[5] = {0};
    memcpy(y, x, sizeof(x));
    // printf("%s\t",typeid)
    int *z = y; //把 y 从 void* 转回int*
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d\t", z[i]);
    }
}
void k11()
{
    int x[7][7] = {
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    int length =7;
    int **target=malloc(sizeof(int*)*length);
    for (int i = 0; i < length; i++)
    {
        target[i]=malloc(sizeof(int)*length);
        memset(target[i],0,sizeof(int)*length);//数组默认全部设置为0
    }

    for (int i = 0; i < length; i++)
    {
        memcpy(target[i],x[i],sizeof(int)*(length));
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d\t",target[i][j]);
        }
        printf("\n");
    }
    
}
void k12()
{
    int x[7][7] = {
        {0, 1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    int length =7;
    char c[7]={'A'};
    for (int i = 1; i < length; i++)
        c[i]=c[i-1]+1;
    graph_matrix* target =ctor_gra_matr(length);
    build_gra_matr(target,c,x);
    //int visit[7]={0};
    printf("矩阵图DFS 深度遍历\t");
    dfs_gra_matr(target,2);
    printf("\n");
    printf("矩阵图BFS 广度遍历\t");
    bfs_gra_matr(target,2);
}


int main()
{
    
    printf("我对付苏联飞机案例");
    // question3();
    return 0;
}