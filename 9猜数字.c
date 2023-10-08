#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
    printf("***********************\n");
    printf("******* 1.paly ********\n");
    printf("******* 0.exit ********\n");
    printf("***********************\n");
}


void game()
{
    int guess =0;
    srand((unsigned int)time(NULL));//生成随机时间戳
    int ret=rand()%100+1;//生成随机数，范围0-32767
    while(1)
    {
        printf("请猜数字:>");
        scanf("%d",&guess);
        if(guess>ret)
        {
            printf("猜大了\n");
        }
        else if(guess<ret)
        {
            printf("猜小了\n");
        }
        if(guess==ret)
        {
            printf("猜对了\n");
            break;
        }

    }
    
}
int main()
{
    int input=0;
    srand((unsigned int)time(NULL));//生成随机时间戳//设置一次就行
    do
    {
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch(input)
        {
            case 1: 
                game(); break;
            case 0:
                printf("退出游戏\n"); break;
            default:
                printf("选择错误，重新选择\n"); break;
                
        }
    }while(input);

    return 0;
    
}