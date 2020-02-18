//进制转换
#include <stdio.h>

//字符转数字
int char2num(char ch)
{
    if(ch >= '0' && ch <= '9')  //数字char
        return ch - '0';        
    else                        //字母char，+10是因为大于十进制的进制，10以上的数字用字母表示，a = 11 。。。
        return ch - 'a' + 10;          
}

//数字转字符
char num2char(int num)
{
    if(num >= 0 && num <= 9)
        return num + '0';
    else
        return num - 10 + 'a';
}

//转化为目标进制
long source2decimal(char tmp[], int source)
{
    int len = 0;
    int num = 0;
    for(;tmp[len] != '\0'; len++)
    {
        num = num * source;
        num += char2num(tmp[len]);
    }
    return num;
}

//取余存放在数组里
int decimal2obj(char tmp[], long decimal, int obj)
{
    int len = 0;
    int rem;

    while(decimal)
    {
        rem = decimal % obj;
        tmp[len++] = num2char(rem);
        decimal = decimal / obj;
    }
    tmp[len] = '\0';

    return len;
}

void output(char tmp[], int len)
{
    int i;
    for(i = len - 1; i >= 0; i--)
        printf("%c", tmp[i]);
    printf("\n");
}

int main()
{
    char tmp[100];
    int source;
    int obj;
    int flag = 1;
    int dec_num;
    int len;
    while(flag)
    {
        printf("input a number:\n");
        scanf("%s", tmp);
        printf("input source:\n");
        scanf("%d", &source);
        printf("input object:\n");
        scanf("%d", &obj);

        dec_num = source2decimal(tmp, source);
        len = decimal2obj(tmp, dec_num, obj);
        output(tmp, len);

        printf("countinue?(1/0):\n");
        scanf("%d", &flag);
    }

    return 0;
}
