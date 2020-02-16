//螺旋阵
//螺旋矩阵是指一个呈螺旋状的矩阵，它的数字由第一行开始到右边不断变大，向下变大，向左变大，向上变大，如此循环。
#include <stdio.h>
#define N 15

int main()
{
    int i, j, k, n, s;
    int ret = 1;
    int a[N][N] = {0};      //生成一个15 * 15矩阵，用0填充
    
    for(i = 0; i < N / 2; i++)
    {
        for(j = i; j < N - i - 1; j++)
            a[i][j] = ret++;        //上横排，随着循环逐排减少
        for(k = i; k < N - i - 1; k++)
            a[k][j] = ret++;        //右竖排，逐排减少
        for(n = N - i - 1; n > i; n--)
            a[k][n] = ret++;        //下横排，逐排减少
        for(s = N - i - 1; s > i; s--)
            a[s][n] = ret++;        //左竖排，逐排减少
    }

    if(N % 2 == 1)
        a[N/2][N/2] = ret;      //N为奇数时，给中心点赋值

    for(int p = 0; p < N; p++)
    {
        for(int q = 0; q < N; q++)
            printf("%5d", a[p][q]);
        printf("\n");
    }

    return 0;

}