//4种方法打印九九乘法表
#include <stdio.h>

void print1();
void print2();
void print3();
void print4();

int main()
{
    print1();
    printf("\n");
    print2();
    printf("\n");
    print3();
    printf("\n");
    print4();
    printf("\n");

    return 0;
}

//左下正三角输出
void print1()
{
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j < i + 1; j++)
        {
            printf("%d*%d=%2d ", i, j, i * j);
        }
        printf("\n");
    }
}

//右上倒三角输出
void print2()
{
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(j < i)
            {
                printf("       ");      //8个空格字符，对齐
                continue;
            }

            printf("%d*%d=%2d ", i, j, i * j);
        }
        printf("\n");
    }
}

//左上倒三角输出
void print3()
{
    for(int i = 1; i < 10; i++)
    {
        for(int j = 9; j >= i; j--)
            printf("%d*%d=%2d ", i, j, i*j);
        
        printf("\n");
    }
}

//右下正三角输出
void print4()
{
    for(int i = 1; i < 10; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            if(j <= 9 - i)
                printf("       ");
            else
                printf("%d*%d=%2d ", i, j, i*j);
        }
        printf("\n");
    }
}