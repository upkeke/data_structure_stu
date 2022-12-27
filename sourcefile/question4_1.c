#include "../headfile/question4.h"
//#include "../headfile/question2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

graph_matrix *ctor_gra_matr(int length)
{
    graph_matrix *target = malloc(sizeof(graph_matrix));
    target->length = length;
    //开辟字符数组的空间
    target->c_arr = malloc(sizeof(char) * length);
    memset(target->c_arr,0,sizeof(char) * length);
    //开辟二维数组的空间
    target->row_col = malloc(sizeof(int *) * length);
    for (int i = 0; i < length; i++)
    {
        target->row_col[i] = malloc(sizeof(int) * length);
        memset(target->row_col[i], 0, sizeof(int) * length); //数组默认全部设置为0
    }
    //初始状态设置所有的顶点不相邻
    target->bian = 0;
    return target;
}
void build_gra_matr(graph_matrix *top, char *c_arr, int (*row_col)[7])
{
    //拷贝c_arr
    memcpy(top->c_arr, c_arr, sizeof(char) * top->length);
    //拷贝row_col
    //拷贝方案1，虽然能够拷贝，但是拷贝过程中不会读取值，无法检索到值为1的元素个数
    // for (int i = 0; i < top->length; i++)
    // {
    //     memcpy(top->row_col[i], row_col, sizeof(int) * (top->length));
    //     row_col++;
    // }

    //拷贝方案二
    for (int i = 0; i < top->length; i++)
    {
        for (int j = 0; j < top->length; j++)
        {
            if (row_col[i][j] == 1)
                top->bian++;
            top->row_col[i][j] = row_col[i][j];
        }
    }
}
//--------------矩阵图DFS 深度遍历 实现-------------
// hasvisited是一个数组 0-7对应ABCDEFG每个顶点，如果元素值为1，表示访问过
static int *hasvisited = NULL;
//矩阵图DFS 前期准备
static void prev_dfs_gra(graph_matrix *top)
{
    hasvisited = malloc(sizeof(int) * top->length);
    memset(hasvisited, 0, sizeof(int) * top->length); //初始设置为0
}
static void ing_dfs_gra(graph_matrix *top, int vis_index)
{
    printf("%c\t", top->c_arr[vis_index]);
    hasvisited[vis_index] = 1;
    for (int i = 0; i < top->length; i++)
    {
        if (top->row_col[vis_index][i] != 1)
        {
            continue;
        }
        else
        {
            if (hasvisited[i] == 0)
            {
                // vis_index =i;
                ing_dfs_gra(top, i);
            }
        }
    }
}
//进入遍历
void dfs_gra_matr(graph_matrix *top, int vis_index)
{
    prev_dfs_gra(top);
    ing_dfs_gra(top, vis_index);
    free(hasvisited);
    hasvisited = NULL;
}
//--------------矩阵图BFS 广度优先遍历 实现-------------
// static LoopSqueue *squ = NULL;
//建立squeue
static int *squ = NULL;
static int front = 0;
static int rear = 0;

static int pop_front()
{
    int vis_index = squ[front];
    front++;
    return vis_index;
}
static void push_back(int vis_index)
{
    squ[rear] = vis_index;
    //开始是出队的时候，标注为访问过，有bug，顶点A与B、C相连，
    //B、C先入队， B出队A入队，C出队，这是这时候，A还在队中，还没出队，
    //所以没有被标记为访问过，A再次入队，bug
    //更改为入队的时候就标记为访问过
    hasvisited[vis_index]=1; //表示这个顶点访问过了
    rear++;
}
static void prev_bfs_gra(graph_matrix *top, int vis_index)
{
    prev_dfs_gra(top);
    squ = malloc(sizeof(int) * top->length);
    memset(squ, 0, sizeof(int) * top->length); //初始设置为0
    front = 0;
    rear = 0;
    push_back(vis_index);
}
static void ing_bfs_gra(graph_matrix *top)
{
    if (front == rear)
        return;
    int vis_index = pop_front();
    printf("%c\t",top->c_arr[vis_index]);
    for (int i = 0; i < top->length; i++)
    {
        if (top->row_col[vis_index][i] == 1 && hasvisited[i] == 0)
        {
            push_back(i); //如果这个顶点没有被访问过 入队
        }
    }
    ing_bfs_gra(top); //出队
}
void bfs_gra_matr(graph_matrix *top,int vis_index)
{
    prev_bfs_gra(top, vis_index);
    ing_bfs_gra(top);
    free(squ);
    squ = NULL;
    free(hasvisited);
    hasvisited = NULL;
}

void free_gra_matr(graph_matrix* gra_matr)
{
    for (size_t i = 0; i < gra_matr->length; i++)
    {
        free(gra_matr->row_col[i]);
    }
    free(gra_matr->row_col);
    free(gra_matr->c_arr);
}