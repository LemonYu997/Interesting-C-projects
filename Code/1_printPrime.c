//输出前500个素数
#include <stdio.h>
#include <math.h>       //使用gcc时 要在 **.c 和 -o 之间加上 -lm 才能进行编译
#define N 500

int isPrime1(int x);
int isPrime2(int x);
int ThePrime(int n);
void printPrime();

int main()
{
    printPrime();

    return 0;
}

//判断是否为素数
//思路1：判断一个整数m是否是素数，只需把 m 被 2 ~ m-1 之间的每一个整数去除，如果都不能被整除，那么 m 就是一个素数。

//思路2：简化方法。m 不必被 2 ~ m-1 之间的每一个整数去除，只需被 2 ~ sqrt(m) 之间的每一个整数去除就可以了。
//如果 m 不能被 2 ~ sqrt(m) 间任一整数整除，m 必定是素数。例如判别 17 是是否为素数，只需使 17 被 2~4 之间的每一个整数去除，由于都不能整除，可以判定 17 是素数。

//原因：因为如果 m 能被 2 ~ m-1 之间任一整数整除，其二个因子必定有一个小于或等于 sqrt(m)，另一个大于或等于 sqrt(m)。
//例如 16 能被 2、4、8 整除，16=2*8，2 小于 4，8 大于 4，16=4*4，4= sqrt(16)，因此只需判定在 2~4 之间有无因子即可。

//思路1代码
int isPrime1(int x)
{   
    //ret是返回值，1 表示是素数， 0 表示不是素数
    int i, ret = 1;

    for(i = 2; i < x; i++)
    { 
        //只要出现能整除的情况，就说明这个数不是素数
        if(x % i == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}
//思路2代码
int isPrime2(int x)
{
    int i, ret = 1;

    //sqrt 函数是平方根计算(Square Root Calculations)
    for(i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

//求第 n 个素数
int ThePrime(int n)
{
    int num = 0;        //素数的个数
    int cur = 2;        //当前数
    while(num < n)
    {
        if(isPrime2(cur))
            num++;
        cur++;
    }     
    //当num = n时cur又++了一次，此时再--就是num = n时对应的cur
    cur--;

    return cur;
}

//打印前N个素数
void printPrime()
{
    int i;
    for(i = 1; i < N + 1; i++)
    {   
        //从第1个素数开始打印
        printf("%6d", ThePrime(i));
        if (i % 10 == 0)
            printf("\n");       //每10个数换1行
    }
}

