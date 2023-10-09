#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NAME_LEN 20 
#define FIND_PRESENT "找当前"
#define FIND_BEFORE "找上一个"

typedef struct link_list_node
{
    char name[NAME_LEN];
    struct link_list_node * next;

}list_node, * list_link;

list_link Create_Link_List_Node();
int     Head_Add_Link_List_Node(list_link head_node);
int Mode_Select(list_link head_node);
int Tail_Add_Link_List_Node(list_link head_node);
list_link Search_Link_List_Node(list_link head_node,char * search_mode);
int Display_Link_List_Data(list_link head_node);
int Del_Link_List_Node(list_link head_node);
int Select_Seat_Add_Link_List_Node(list_link head_node);
int Destroy_List(list_link head_node);

int Move_Link_List_Node(list_link head_node);


list_link Create_Link_List_Node()//创建节点就是申请堆空间
{
    list_link node_heap_start_p=(list_link)malloc(sizeof(list_node));

    if(node_heap_start_p==(list_link)NULL)
    {
        printf("malloc 申请失败\n");

        return (list_link)-1;
    }

    memset(node_heap_start_p, 0, sizeof(list_node));

    node_heap_start_p->next = NULL;//提高可读性


    return node_heap_start_p;//创建的堆空间的作用域是整个程序，所以常用于函数的返回值将其堆空间的首地址返回出去
}


int Mode_Select(list_link head_node)
{
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常!\n");
        return -1;
    }
    int select_num;
    while(1)
    {
        system("clear");
        printf("⚪⚪⚪⚪ 1 头插添加数据结点⚪⚪⚪⚪\n");
        printf("⚪⚪⚪⚪ 2 尾插添加数据结点⚪⚪⚪⚪\n");
        printf("⚪⚪⚪⚪ 3 指定位置添加数据⚪⚪⚪⚪\n");
        printf("⚪⚪⚪⚪ 4 删除指定数据结点⚪⚪⚪⚪\n");
        printf("⚪⚪⚪⚪ 5 检索指定数据结点⚪⚪⚪⚪\n");
        printf("⚪⚪⚪⚪ 6 移动指定数据结点⚪⚪⚪⚪\n");
        printf("⚪⚪⚪⚪ 7 遍历链表数据结点⚪⚪⚪⚪\n");
        printf("⚪⚪⚪⚪ 8 退出单向链表！！⚪⚪⚪⚪\n");

        scanf("%d",&select_num);

        switch(select_num)
        {
            case 1: Head_Add_Link_List_Node(head_node);break;
            case 2: Tail_Add_Link_List_Node(head_node);break;
            case 3: Select_Seat_Add_Link_List_Node(head_node);break;
            case 4: Del_Link_List_Node(head_node);break;
            case 5: Search_Link_List_Node(head_node,FIND_PRESENT);break;
            case 6: Move_Link_List_Node(head_node);break;
            case 7: Display_Link_List_Data(head_node);break;
            case 8: return 0;
            default: printf("指令有无，请重新输入！\n");break;
        }
        sleep(1);

    }
    return 0;
}

int    Head_Add_Link_List_Node(list_link head_node)
{
    if(head_node ==(list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    
    list_link new_node = Create_Link_List_Node();
    if(new_node == (list_link)-1)
    {
        printf("Error\n");
        return -1;
    }

    printf("请输入要添加的数据：");
    //strcpy(new_node->name,"A");
    scanf("%s",new_node->name);
    while(getchar() != '\n');


    
        //不需要备份旧的老二
        new_node->next = head_node->next;
        head_node->next = new_node;

        //需要备份旧的老二
        //list_link tmp_node = head_node->next;
        //head_node->next = new_node;
        //new_node->next = temp_node;
    

    return 0;

}

int  Tail_Add_Link_List_Node(list_link head_node) {
    // 创建新节点
    if(head_node ==(list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    
    list_link new_node = Create_Link_List_Node();
    if(new_node == (list_link)-1)
    {
        printf("Error\n");
        return -1;
    }
    printf("请输入要添加的数据：");
    scanf("%s",new_node->name);
    while(getchar() != '\n');
    //遍历直接找尾结点
    list_link tmp_node;
    for (tmp_node = head_node;tmp_node->next !=NULL;tmp_node=tmp_node->next);
    {

    }
    tmp_node->next = new_node;




        //方法二
        // if (head_node == (list_link)NULL) 
        // {
        //     // 如果链表为空，将新节点设置为头节点
        //     head_node = new_node;
        // } else {
        //     // 查找链表尾部节点
        //     list_link tail_node = head_node;
        //     while (tail_node->next != NULL) {
        //         tail_node = tail_node->next;
        //     }
        //     // 将新节点插入到链表尾部
        //     tail_node->next = new_node;
        // }
    return 0;
}

int Del_Link_List_Node(list_link head_node)
{
    
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    else if(head_node->next == NULL)
    {
        printf("空链表无需输出\n");
        return 0;
    }
    else
    {
        list_link del_node_bef = Search_Link_List_Node(head_node,FIND_BEFORE);
        if(del_node_bef == (list_link)-1)
        {
            printf("链表异常，检索删除失败！\n");
            return -1;
        }
        else if(del_node_bef == (list_link)0)
        {
            printf("没有该节点，无法删除！\n");
            return 0;
        }
        else
        {
            list_link del_node =del_node_bef->next;

            //删除的尾节点不是最后一个节点
            del_node_bef->next =del_node->next;
            del_node->next = NULL;
            free(del_node);


        }
    }
    return 0;
}

list_link Search_Link_List_Node(list_link head_node,char * search_mode)//添加查找模式，当前或上一个
{
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    else if(head_node->next == NULL)
    {
        printf("空链表无需输出\n");
        return 0;
    }
    else
    {
        char obj_data[NAME_LEN];
        memset(obj_data, 0, NAME_LEN);

        printf("请输入要查找的数据\n");
        scanf("%s",obj_data);
        while(getchar() != '\n');

        //找上一个，从头的下一个开始找
        //找当前，从头的下一个开始找
        for(list_link obj_node = head_node;obj_node->next !=NULL;obj_node = obj_node->next)
        {
            if(strcmp(obj_node->next->name , obj_data)==0)
            {
                printf("击中目标：%s\n",obj_node->next->name);
                if(strcmp(search_mode,FIND_BEFORE)==0)
                    return obj_node;

                if(strcmp(search_mode,FIND_PRESENT)==0)
                return obj_node->next;
            }
        }
    }

    printf("没有目标节点\n");
    return (list_link)0;
}

int Select_Seat_Add_Link_List_Node(list_link head_node)
{
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    else if(head_node->next == NULL)
    {
        //空链表默认头插
        if(Head_Add_Link_List_Node(head_node)== -1)
        {
            printf("头插节点失败!\n");
            return -1;
        }

    }
    else
    {
        list_link obj_node = Search_Link_List_Node(head_node,FIND_PRESENT);
        if(obj_node ==(list_link)-1)
        {
            printf("检索链表节点异常！无法指定位置添加！\n");
            return -1;
        }
        else if(obj_node ==(list_link)0)
        {
            printf("没有该结点，无法指定位置添加！\n");
            return 0;
        }
        else 
        {
            list_link new_node=Create_Link_List_Node(head_node);
            if(new_node == (list_link)-1)
            {
                printf("创建结点失败！\n");
                return -1;
            }

            printf("请输入要添加的数据：\n");
            scanf("%d",&new_node->name);

            new_node->next = obj_node->next;
            obj_node->next = new_node;
            

        }
    }
    return 0;
}

int Move_Link_List_Node(list_link head_node)
{
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    else if(head_node->next == NULL|| head_node->next == NULL)
    {
        printf("只有一个节点，无法移动！\n");
        return 0;
    }
    else 
    {
        list_link obj_seat_node = Search_Link_List_Node(head_node,FIND_PRESENT);
        if(obj_seat_node == (list_link)-1)
        {
            printf("链表异常，无法移动！\n");
            return -1;
        }
        else if(obj_seat_node == (list_link)0)
        {
            printf("无法移动到该位置！\n");
            return 0;
        }
        else 
        {
            list_link moved_node_bef = Search_Link_List_Node(head_node,FIND_PRESENT);
            if(moved_node_bef == (list_link)-1)
            {
                printf("链表异常，无法移动!\n");
                return -1;
            }
            else if(moved_node_bef == (list_link)0)
            {
                printf("无法移动到该位置！\n");
                return 0;
            }
            else 
            {
                list_link move_node = moved_node_bef->next;
                if(move_node == obj_seat_node) 
                {
                    printf("ERROR!\n");
                    return 0;
                }

                moved_node_bef->next = move_node->next;
                move_node->next =NULL;

                move_node->next =obj_seat_node->next;
                obj_seat_node->next =move_node;
            }
        }
    }

    return 0;
}


int Destroy_List(list_link head_node)
{
    
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    else if(head_node->next == NULL)
    {
        printf("空链表直接释放节点\n");
        free(head_node);
        return 0;
    }
    else
    {
       //循环一直删除并且释放头的下一个，直到头结点的下一个等于空的时候，把头结点也释放即可
            while(head_node->next != NULL)
            {
                list_link del_node = head_node->next;
                head_node->next    = del_node->next;
                del_node->next     = NULL;
                free(del_node);
                printf("----\n");
            }


            //free(head_node)
    }

    return 0;
    
}

int Display_Link_List_Data(list_link head_node)
{
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常\n");
        return -1;
    }
    else if(head_node->next == NULL)
    {
        printf("空链表无需输出\n");
        return 0;
    }
    else
    {
        for(list_link tmp_node = head_node->next;tmp_node!=NULL;tmp_node = tmp_node->next)
        {
            printf("%s\n",tmp_node->name);
        }

        return 0;
    }
}

int main()
{
    list_link head_node = Create_Link_List_Node();
    if(head_node == (list_link)-1)
    {
        printf("创建链表头节点堆空间失败！\n");

        return -1;
    }

    Mode_Select(head_node);


    Destroy_List(head_node);
    
  
    return 0;
}