#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct data_node
{
    int int_data;
    struct data_node * next;
}data_struct,* data_pointer;

typedef struct ctrl_stack
{
    struct data_node * top;

    unsigned int size;
}CS,*P_CS;

P_CS Init_Link_Stack();
int Enter_Stack(P_CS p_cs);
int Pop_Link_Stack(P_CS p_cs);
int Ergodic_Stack(P_CS p_cs);
int Destroy_Link_Stack(P_CS p_cs);

int Mode_Select(P_CS p_cs)
{
    int select_num;
    while(1)
    {
        system("clear");
        printf("****1 压  栈！****\n");
        printf("****2 出  栈！****\n");
        printf("****3 遍历栈！****\n");
        printf("****4 摧毁栈！****\n");

        scanf("%d",&select_num);

        switch(select_num)
        {
            case 1:Enter_Stack(p_cs);break;
            case 2:Pop_Link_Stack(p_cs);break;
            case 3:Ergodic_Stack(p_cs);break;
            case 4:return 0;
            default:printf("指令错误！请重新输入！\n");break;
        }
        sleep(1);
    }
    return 0;
}

P_CS Init_Link_Stack()
{
    P_CS p_cs = (P_CS)malloc(sizeof(CS));
    if(p_cs ==(P_CS)NULL)
    {
        printf("申请链式栈控制结构体堆空间失败！\n");
        return (P_CS)-1;
    }

    memset(p_cs, 0, sizeof(CS));

    p_cs->top = NULL;
    p_cs->size = 0;

    return p_cs;
}

int Enter_Stack(P_CS p_cs)//入栈  头插
{
    if(p_cs == (P_CS)NULL)
    {
        printf("栈异常！\n");
        return -1;
    }

    data_pointer new_data_node = (data_pointer)malloc(sizeof(data_struct));
    if(new_data_node == (data_pointer)NULL)
    {
        printf("申请数据节点失败！\n");
        return -1;
    }

    memset(new_data_node,0,sizeof(data_struct));

    new_data_node->next = NULL;

    printf("请输入要入栈的数据：");
    scanf("%d",&(new_data_node->int_data));

    new_data_node->next = p_cs->top;
    p_cs->top = new_data_node;

    p_cs->size++;
    return 0;


}

int Ergodic_Stack(P_CS p_cs)
{
    if(p_cs == (P_CS)NULL)
    {
        printf("栈异常！\n");
        return -1;
    }
    else if(p_cs == (P_CS)0)
    {
        printf("空链表！无需遍历！\n");
        return 0;
    }
    else 
    {
        data_pointer tmp_node = p_cs->top;

        for(int i=0;i<p_cs->size;i++)
        {
            printf("%d\n",tmp_node->int_data);
            tmp_node = tmp_node->next;
        }

    }
    return 0;
}

int Pop_Link_Stack(P_CS p_cs)
{
    if(p_cs == (P_CS)NULL)
    {
        printf("栈异常！\n");
        return -1;
    }
    else if(p_cs->top == NULL)
    {
        printf("空栈，无需弹出！\n");
        return 0;

    }
    else 
    {
        data_pointer pop_node = p_cs->top;
        printf("数据%d已出栈\n",pop_node->int_data);
        p_cs->top = pop_node->next;
        pop_node->next = NULL;
        free(pop_node);
        p_cs->size--;

    }
    return 0;
}

int Destroy_Link_Stack(P_CS p_cs)
{
    if(p_cs ==(P_CS)NULL)
    {
        printf("栈异常！\n");
        return -1;
    }
    else if(p_cs->top ==NULL)
    {
        printf("空栈！直接释放控制节点！\n");
        free(p_cs);
        return 0;
    }
    else 
    {
        data_pointer del_node = p_cs->top;
        for(del_node;p_cs->size!=0;p_cs->size--)
        {
            p_cs->top = del_node->next;
            del_node->next = NULL;
            printf("----\n");

        }
        free(del_node);
    }
    free(p_cs);
}

int main()
{
    P_CS p_cs = Init_Link_Stack();
    if(p_cs ==(P_CS)NULL)
    {
        printf("初始化链式栈失败！\n");
        return -1;
    }

    Mode_Select(p_cs);
    Destroy_Link_Stack(p_cs);
    return 0;
}