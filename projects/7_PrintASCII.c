//打印ASCII码可见字符
#include <stdio.h>

int main()
{
    int c;
    printf("\tCharacter Code\n");
    int i = 0;
    for(c = 33; c <= 126; c++)
    {
        if(i % 4 == 0)
            printf("\n");       //4 个字符就换行
        printf("\t%c\t%d", c, c);
        i++;
    }
    printf("\n");

    return 0;
}