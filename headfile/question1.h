//多项式结构体定义的
// typedef struct
// {
//     float coef; //系数
//     int expo; //指数
// } polynomial;

typedef struct polynomial
{
    float coef; //系数
    int expo;   //指数
    struct polynomial *next;
} PolyLode;

//链表的建立
PolyLode *poly_list_init();
//链表的长度
int poly_list_size(PolyLode *head);
//链表的排序
void sort_list(PolyLode *head);
//合并指数相同的多项式 针对重复输入相同的指数的情况
void remove_similar_poly(PolyLode *head);
//2个多项式相加
PolyLode * add_poly_list(PolyLode *p1,PolyLode *p2);
//2个多项式相减
PolyLode * sub_poly_list(PolyLode *p1,PolyLode *p2);
//链表的遍历
void show_poly_list(PolyLode *head);
//释放内存
void free_list(PolyLode *head);