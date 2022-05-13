#include "../headfile/question3.h"
#include <stdio.h>
#include <stdlib.h>

// theeNode 构造
treeNode *ctor_tnode(char v, treeNode *l, treeNode *r)
{
    treeNode *traget = malloc(sizeof(treeNode));
    traget->left = l;
    traget->right = r;
    traget->value = v;
    return traget;
}

//二叉树建立 15个节点
treeNode *build_tree()
{
    treeNode *n_n = ctor_tnode('N', NULL, NULL);
    treeNode *n_h = ctor_tnode('H', n_n, NULL);
    treeNode *n_d = ctor_tnode('D', NULL, n_h);

    treeNode *n_o = ctor_tnode('O', NULL, NULL);
    treeNode *n_j = ctor_tnode('J', NULL, n_o);
    treeNode *n_i = ctor_tnode('I', NULL, NULL);
    treeNode *n_e = ctor_tnode('E', n_i, n_j);

    treeNode *n_b = ctor_tnode('B', n_d, n_e);

    treeNode *n_k = ctor_tnode('K', NULL, NULL);
    treeNode *n_f = ctor_tnode('F', NULL, n_k);

    treeNode *n_l = ctor_tnode('L', NULL, NULL);
    treeNode *n_m = ctor_tnode('M', NULL, NULL);
    treeNode *n_g = ctor_tnode('G', n_l, n_m);

    treeNode *n_c = ctor_tnode('C', n_f, n_g);

    treeNode *n_a = ctor_tnode('A', n_b, n_c);
    return n_a;
}
//先序遍历 根左右
void each_root_left_right(treeNode *top)
{
    if (top == NULL)
        return;
    // 先遍历根节点
    printf("%c\t", top->value);
    // 遍历左节点
    each_root_left_right(top->left);
    // 遍历右节点
    each_root_left_right(top->right);
}
//中序遍历 左根右
void each_left_root_right(treeNode *top)
{
    if (top == NULL)
        return;
    // 遍历左节点
    each_left_root_right(top->left);
    // 先遍历根节点
    printf("%c\t", top->value);
    // 遍历右节点
    each_left_root_right(top->right);
}
//后序遍历 左右根
void each_left_right_root(treeNode *top)
{
    if (top == NULL)
        return;
    // 遍历左节点
    each_left_right_root(top->left);
    // 遍历右节点
    each_left_right_root(top->right);
    // 先遍历根节点
    printf("%c\t", top->value);
}
//--------------层次遍历的实现--------------
static treeNode *treeque[15] = {NULL};
static int front = 0;
static int rear = 0;
//入队
static void push_tree(treeNode *top)
{
    if (top == NULL)
        return;
    treeque[rear] = top;
    rear++;
}
//出队
static treeNode *pop_tree()
{
    treeNode *q = treeque[front];
    printf("%c\t", q->value);
    front++;
    return q;
}
//内部 层次遍历
static void each_squeue()
{
    if (front == rear)
        return;
    treeNode *q = pop_tree(); //出队 马上子类入队
    push_tree(q->left);
    push_tree(q->right);
    each_squeue();
}
// 初始化以及层次遍历
void init_each_treesque(treeNode *top)
{
    // treeNode *treeque[15] = {NULL};
    // int front = 0;
    // int rear = 0;
    front = 0;
    rear = 0;
    push_tree(top); //启动
    each_squeue();
    printf("\n");
}
//--------------层次遍历的实现完毕--------------
//深度T
int get_depth(treeNode *top)
{
    if (top == NULL)
        return 0;
    int ld = get_depth(top->left);
    int rd = get_depth(top->right);
    return ld > rd ? ld + 1 : rd + 1;
}
//输出树的叶子
void show_tree_leaf(treeNode *top)
{
    if (top == NULL)
        return;
    int x = (top->left == NULL && top->right == NULL);
    if (x)
    {
        printf("%c\t", top->value);
        return;
    }
    else
    {
        show_tree_leaf(top->left);
        show_tree_leaf(top->right);
    }
}
//输出树的叶子
void noshow_tree_leaf(treeNode *top)
{
    if (top == NULL)
        return;
    int x = (top->left == NULL && top->right == NULL);
    if (x)
        return;
    else
    {
        printf("%c\t", top->value);
        noshow_tree_leaf(top->left);
        noshow_tree_leaf(top->right);
    }
}
// theeNode 深拷贝  //mater: 被拷贝的对象
treeNode *deep_copy_tree(treeNode *mater)
{
    if (mater == NULL)
        return NULL;
    treeNode *target = malloc(sizeof(treeNode));
    target->value = mater->value;
    // 深拷贝左节点
    target->left = deep_copy_tree(mater->left);
    // 深拷贝右节点
    target->right = deep_copy_tree(mater->right);
    return target;
}
// 二叉树的 析构
void free_tree(treeNode *top)
{
    if (top == NULL)
        return;
    // 释放左节点
    free_tree(top->left);
    // 释放右节点
    free_tree(top->right);
    // 释放根节点
    printf("释放 %c\t",top->value);
    free(top);
}