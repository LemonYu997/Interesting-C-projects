//猜数游戏
//猜1个一百以内的整数，共5次机会
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand((unsigned)time(0));       //设置种子
    int num;
    int guess;      //玩家猜的数
    int right;      //正确答案
    int count;      //已猜次数
    while(1)
    {
        count = 0;
        right = 0;
        num = rand() % 100;         //创建随机数
        printf("Please guess a number:\n");
        while(count++ < 5)          //只能猜5次
        {
            scanf("%d", &guess);
            if (guess == num)
            {
                right = 1;
                printf("You are win!\n");
                break;
            }
            else if(guess > num)
                printf("Too big.\n");
            else
                printf("Too small.\n");
        }
        if(right == 0)
            printf("5 times, game over!");
        
        printf("Angin?(y/n)\n");
        int c;
//      fflush(stdin);              //WINDOWS下清空缓冲区
        setbuf(stdin, NULL);        //LINUX下清空缓冲区
        c = getchar();
        if (c == 'n' || c == 'N')
            break;
    }
    return 0;
}