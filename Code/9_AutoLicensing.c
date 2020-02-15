//自动发牌程序
#include <stdio.h>
#include <stdlib.h>

int comp(const void *j, const void *i);
void p(int b[], char n[]);

int main()
{
    static char n[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int a[53], b1[13], b2[13], b3[13], b4[13];
    int b11, b22, b33, b44, m, flag, i, t = 1;
    b11 = b22 = b33 = b44 = 0;

    while(t <= 52)      //控制发52张牌
    {
        m = rand()%52;  //产生0~52的随机数
        for(flag = 1, i = 1; i <= t && flag; i++)   //查找新产生的随机数是否已存在
        {
            if(m == a[i])
                flag = 0;       //flag = 1表示产生的是新的随机数，flag = 0表示新产生的随机数已存在
        }
        if(flag)
        {
            a[t++] = m;         //如果产生了新的随机数，就存入数组
            //根据t的模值，判断当前的牌应存入哪个数组中
            if(t % 4 == 0)
                b1[b11++] = a[t - 1];
            else if(t % 4 == 1)
                b2[b22++] = a[t - 1];
            else if(t % 4 == 2)
                b3[b33++] = a[t - 1];
            else if(t % 4 == 3)
                b4[b44++] = a[t - 1];
        }
    }

    //将每个人的牌排序
    qsort(b1, 13, sizeof(int), comp);
    qsort(b2, 13, sizeof(int), comp);
    qsort(b3, 13, sizeof(int), comp);       
    qsort(b4, 13, sizeof(int), comp);
    //分别打印每个人的牌
    p(b1, n);
    p(b2, n);
    p(b3, n);
    p(b4, n);

    return 0;
}

//打印函数
void p(int b[], char n[])
{
    int i;
    printf("\nSpade\t");       //打印黑桃标记
    for(i = 0; i < 13; i++) //将数组中的值转换为相应的花色
    {
        if(b[i] / 13 == 0)  //找到该花色对应的牌
            printf("%c ", n[b[i] % 13]);
    }
    printf("\nHeart\t");       //打印红桃标记
    for(i = 0; i < 13; i++) 
    {
        if(b[i] / 13 == 1)  
            printf("%c ", n[b[i] % 13]);
    }
    printf("\nDiamond\t");       //打印方块标记
    for(i = 0; i < 13; i++) 
    {
        if(b[i] / 13 == 2)  
            printf("%c ", n[b[i] % 13]);
    }
    printf("\nClub\t");       //打印梅花标记
    for(i = 0; i < 13; i++) 
    {
        if(b[i] / 13 == 3 || b[i] / 13 == 4)  
            printf("%c ", n[b[i] % 13]);
    }

    printf("\n");
}

//qsort调用的排序函数
int comp(const void *j, const void *i)
{
    return (*(int*)i - *(int*)j);
}