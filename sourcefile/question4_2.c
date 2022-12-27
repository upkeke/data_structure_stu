#include "../headfile/question4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//
//边节点的初始化
edgeNode *ctor_edge(int index, edgeNode *edge)
{
    edgeNode *node = malloc(sizeof(edgeNode));
    node->index = index;
    node->next = edge;
    return node;
}
//顶点节点数组的初始化 返回值是数组的首地址 （本次数组大小固定为7）
void build_vertex_list(vertex *begin, int size)
{
    char value = 'A';
    for (int i = 0; i < size; i++)
    {
        begin[i].value = value;
        begin[i].edgeList = NULL;
        value++;
    }
    //与A相邻 E:4 -> B:1
    edgeNode *edge1 = ctor_edge(4, NULL);
    edgeNode *edge2 = ctor_edge(1, edge1);
    begin[0].edgeList = edge2;

    //与B相邻 A:0
    edge1 = ctor_edge(0, NULL);
    begin[1].edgeList = edge1;

    //与C相邻 E:4 -> D:3
    edge1 = ctor_edge(4, NULL);
    edge2 = ctor_edge(3, edge1);
    begin[2].edgeList = edge2;

    //与D相邻 F:5 -> C:2
    edge1 = ctor_edge(5, NULL);
    edge2 = ctor_edge(2, edge1);
    begin[3].edgeList = edge2;

    //与E相邻 G:6-> F:5 -> C:2-> A:0
    edge1 = ctor_edge(6, NULL);
    edge2 = ctor_edge(5, edge1);
    edgeNode *edge3 = ctor_edge(2, edge2);
    edgeNode *edge4 = ctor_edge(0, edge3);
    begin[4].edgeList = edge4;

    //与F相邻 E:4 -> D:3
    edge1 = ctor_edge(4, NULL);
    edge2 = ctor_edge(3, edge1);
    begin[5].edgeList = edge2;

    //与G相邻 E:4
    edge1 = ctor_edge(4, NULL);
    begin[6].edgeList = edge1;
}

//邻接链表图DFS ------------------------------
static bool hasVisitedDFS[7] = {0}; // false代表没有访问过
static void dfs_vertex(vertex *arr_ver, int index)
{
    if (!hasVisitedDFS[index])
    {
        hasVisitedDFS[index] = true; //变为访问
        printf("%c\t", arr_ver[index].value);
        edgeNode *edge = arr_ver[index].edgeList;
        while (edge != NULL)
        {
            index = edge->index;
            dfs_vertex(arr_ver, index);
            edge = edge->next;
        }
    }
}
void dfs_gra_vertex(vertex *arr_ver, int index)
{
    memset(hasVisitedDFS, 0, sizeof(hasVisitedDFS)); //归零
    dfs_vertex(arr_ver, index);
}
//邻接链表图BFS ------------------------------
// 0 代表没有被访问、 1代表被访问，或者被打印过、 3代表 被访问且被打印过
static bool *hasVisitedBFS = NULL; //数组首地址 //是否被访问过
static bool *hasPrintedBFS = NULL; //数组首地址 //是否被打印过
static void bfs_vertex(vertex *arr_ver, int index)
{
    if (!hasVisitedBFS[index])
    {
        hasVisitedBFS[index] = true; //变为访问
        edgeNode *edge = arr_ver[index].edgeList;
        edgeNode *temp = edge;
        while (edge != NULL)
        {
            if ((!hasVisitedBFS[edge->index]) && (!hasPrintedBFS[edge->index]))
            {
                hasPrintedBFS[edge->index] = true; //打印 访问过的元素一定被打印过，但是打印过的元素不一定访问过
                printf("%c\t", arr_ver[edge->index].value);
            }
            edge = edge->next;
        }
        while (temp != NULL)
        {
            bfs_vertex(arr_ver, temp->index);
            temp = temp->next;
        }
    }
}
void bfs_gra_vertex(vertex *arr_ver, int size, int index)
{
    hasVisitedBFS = malloc(sizeof(bool) * size);
    hasPrintedBFS = malloc(sizeof(bool) * size);
    memset(hasVisitedBFS, 0, sizeof(bool) * size);
    memset(hasPrintedBFS, 0, sizeof(bool) * size);
    printf("%c\t", arr_ver[index].value);
    hasPrintedBFS[index] = true;
    bfs_vertex(arr_ver, index);
    free(hasVisitedBFS);
    free(hasPrintedBFS);
}

void free_gra_vertex(vertex *arr_ver,int size)
{
    for (size_t i = 0; i < size; i++)
    {
        edgeNode *edge = arr_ver[i].edgeList;
        edgeNode *temp=NULL;
        printf("%c:\t", arr_ver[i].value);
        while (edge!= NULL)
        {
            printf("%c\t", arr_ver[edge->index].value);
            temp =edge;
            edge=edge->next;
            free(temp);
        }
        printf("\n");
    }
    
}