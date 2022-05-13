#include <stdio.h>
#include <stdlib.h>
typedef struct jjjj
{
    int x;
    char k;
} jj[2];

void k1()
{

    jj j = {{1, 'j'}, {2, 'h'}};
    printf("%d\t%d", j[0].x, j[1].x);

    struct jjjj x1 = {1, 'h'};
    jj x;
    x[0] = x1;

    struct jjjj q[2];
    q[0] = x1;
}
int ff()
{
    int x = ff();
    return x;
}
int main()
{
    ff();
}