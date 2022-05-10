#include"question1.h"
#include<stdlib.h>
#include<stdio.h>
void k1()
{
    printf("第一个多项式\n");
    PolyLode* p1 =poly_list_init();
    printf("打印第一个多项式\n");
    show_poly_list(p1);

    printf("第二个多项式\n");
    PolyLode* p2 =poly_list_init();
    printf("打印第二个多项式\n");
    show_poly_list(p2);

    printf("排序第一个多项式\n");
    sort_list(p1);
    show_poly_list(p1);

    printf("排序第二个多项式\n");
    sort_list(p2);
    show_poly_list(p2);

    printf("相加\n");
    PolyLode* add_p=add_poly_list(p1,p2);
    printf("打印和\n");
    show_poly_list(add_p);

    printf("相减\n");
    PolyLode* sub_p=sub_poly_list(p1,p2);
    printf("打印差\n");
    show_poly_list(sub_p);

    free_list(p1);
    free_list(p2);
    free_list(add_p);
    free_list(sub_p);
    //free(p1);
}
void k2()
{
    printf("第一个多项式\n");
    PolyLode* p1 =poly_list_init();
    printf("打印第一个多项式\n");
    show_poly_list(p1);
    printf("个数%d",poly_list_size(p1));
    free_list(p1);
}
int main()
{
    k2();
    return 0;
}