//汉诺塔
//汉诺塔（又称河内塔）问题是源于印度一个古老传说的益智玩具。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。
//大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。
#include <stdio.h>

//汉诺塔运行函数，x, y, z表示三个塔
void hanoi(int n, char x, char y, char z);
//数字移动
void move(char x, int n, char y);

int main()
{
    hanoi(4, 'a', 'b', 'c');
}

void hanoi(int n,char x, char y, char z)
{
    if (n == 1)
        move(x, 1, z);
    else
    {
        hanoi(n - 1, x, z, y);
        move(x, n, z);
        hanoi(n - 1, y, x, z);
    }
}

void move(char x, int n, char y)
{
    printf("%c->%c\n", x, y);
}