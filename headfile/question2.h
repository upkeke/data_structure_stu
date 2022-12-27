#ifndef QUESTION2
#define QUESTION2

#define MaxSize 15
// 循环队列
// front 对应首个元素位置
// rear 对应插入元素的位置，当当前最后一个元素的下一位
//
typedef struct
{
    char data[MaxSize];
    int front;
    int rear;
} LoopSqueue;

LoopSqueue* init_squeue();
//判断是否为满
int is_full(LoopSqueue* sq);
// 元素个数
int squ_size(LoopSqueue* sq);
//判断是否为空
int is_empty(LoopSqueue* sq);
//入队
int push_back_(LoopSqueue* sq,char c);
//出列
int pop_front(LoopSqueue* sq);

void show_squ(LoopSqueue *sq);

#endif