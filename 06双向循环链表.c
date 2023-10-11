#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NAME_LEN 50
#define FIND_PRESENT "找当前"
#define FIND_BEFORE "找上一个"

typedef struct link_list_node
{
    char name[NAME_LEN];
    struct link_list_node * next;
    struct link_list_node* prev;    

}list_node, * list_link;

list_link Create_Link_List_Node();
int     Head_Add_Link_List_Node(list_link head_node);
int Mode_Select(list_link head_node);
int Tail_Add_Link_List_Node(list_link head_node);
list_link Search_Link_List_Node(list_link head_node);
int Display_Link_List_Data(list_link head_node);
int Del_Link_List_Node(list_link head_node);
int Select_Seat_Add_Link_List_Node(list_link head_node);
int Destroy_List(list_link head_node);
int Move_Link_List_Node(list_link head_node);

list_link Create_Link_List_Node()
{
    list_link new_node= (list_link)malloc(sizeof(list_node));
    if(new_node ==(list_link)NULL)
    {
        printf("创建节点失败！\n");
        return (list_link)-1;
    }

    memset(new_node,0,sizeof(list_node));

    new_node->next =new_node;
    new_node->prev =new_node;

    return new_node;

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
            case 5: Search_Link_List_Node(head_node);break;
            case 6: Move_Link_List_Node(head_node);break;
            case 7: Display_Link_List_Data(head_node);break;
            case 8: return 0;
            default: printf("指令有无，请重新输入！\n");break;
        }
        sleep(1);

    }
    return 0;
}

int     Head_Add_Link_List_Node(list_link head_node)
{
    if(head_node ==(list_link)-1)
    {
        printf("头节点异常！\n");
        return -1;
    }
    else 
    {
        list_link new_node =Create_Link_List_Node();
        if(new_node ==(list_link)-1)
        {
            printf("创建节点失败！\n");
            return -1;
        }
        else 
        {
            printf("请输入你想输入的数据：\n");
            scanf("%s",new_node->name);
            while(getchar()!='\n');

            
            new_node->next = head_node->next;
            head_node->next->prev = new_node;
            head_node->next = new_node;
            new_node->prev = head_node;
            
           
        }
    }
    return 0;
}

int Tail_Add_Link_List_Node(list_link head_node)
{
    if(head_node ==(list_link)-1)
    {
        printf("头节点异常！\n");
        return -1;
    }
    else
    {
        list_link new_node =Create_Link_List_Node();
        if(new_node ==(list_link)-1)
        {
            printf("创建新节点失败！\n");
            return -1;
        }
        else
        {
            printf("请输入你想插入的数据：\n");
            scanf("%s",new_node->name);
            while(getchar()!= '\n');

            new_node->next = head_node;
            head_node->prev->next = new_node;
            new_node->prev =head_node->prev;
            head_node->prev = new_node;
            

        }

    }
    return 0;
}

list_link Search_Link_List_Node(list_link head_node)
{
    if(head_node ==(list_link)-1)
    {
        printf("头节点异常！\n");
        return (list_link)-1;
    }
    else if(head_node->next ==NULL)
    {
        printf("空链表无法检索！\n");
        return (list_link)0;
    }
    else
    {
        char obj_data[NAME_LEN];
        printf("请输入要检索的数据：\n");
        scanf("%s",obj_data);
        while(getchar() !='\n');

        for(list_link obj_node = head_node->next;obj_node != head_node;obj_node = obj_node->next)
        {
            if(strcmp(obj_data,obj_node->name) == 0)
            {
                printf("击中目标！:%s\n",obj_node->name);
                return obj_node;
            }
        }
    }
    //printf("抱歉！表中没有你要找的数据！\n");
    return (list_link)0;
}

int Del_Link_List_Node(list_link head_node)
{
    if(head_node ==(list_link)-1)
    {
        printf("头节点异常！\n");
        return -1;
    }
    else if(head_node->next ==NULL)
    {
        printf("空链表！\n");
        return 0;
    }
    else 
    {
        list_link del_node =Search_Link_List_Node(head_node);
        if(del_node == (list_link)-1)
        {
            printf("链表异常！\n");
            return -1;
        }
        else if(del_node == (list_link)0)
        {
            printf("无所查找目标！\n");
            return 0;
        }
        else
        {
            
            del_node->prev->next =del_node->next;
            del_node->next->prev =del_node->prev; 
            
            del_node->prev = NULL;
            del_node->next = NULL;
            
            free(del_node);
        }
    }
}

int Select_Seat_Add_Link_List_Node(list_link head_node)
{
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常!\n");
        return -1;
    }
    else if(head_node->next == NULL)
    {
        printf("空链表，默认头插！\n");
        if(Head_Add_Link_List_Node(head_node)==-1)
        {
            printf("头插法失败！\n");
            return 0;
        }
    }
    else 
    {
        list_link obj_node = Search_Link_List_Node(head_node);
        if(obj_node == (list_link)-1)
        {
            printf("链表异常！\n");
            return -1;
        }
        else if(obj_node == (list_link)0)
        {
            printf("没有该位置，无法指定位置添加！\n");
            return 0;
        }
        else 
        {
            list_link new_node = Create_Link_List_Node();
            if(new_node == (list_link)-1)
            {
                printf("创建新节点失败！\n");
                return 0;
            }

            printf("请输入要添加的数据！\n");
            scanf("%s",new_node->name);
            while(getchar()!='\n');

            
            new_node->next = obj_node->next;
            obj_node->next->prev = new_node;

            obj_node->next = new_node;
            new_node->prev = obj_node;
            
        }

    }
    return 0;
}

int Move_Link_List_Node(list_link head_node)
{
    if(head_node == (list_link)NULL)
    {
        printf("头节点异常！\n");
        return 0;
    }
    else if(head_node->next == (list_link)  NULL)
    {
        printf("空链表，无法选择移动！\n");
        return 0;
    }
    else 
    {
        // list_link obj_node = Search_Link_List_Node(head_node);
        // if(obj_node == (list_link)NULL)
        // {
        //     printf("链表异常！\n");
        //     return -1;
        // }
        // else if(obj_node == (list_link)0)
        // {
        //     printf("没有该节点！\n");
        //     return 0;
        // }
        // else 
        // {
            // list_link move_node = Search_Link_List_Node(head_node);
            // if(move_node == (list_link)NULL)
            // {
            //     printf("链表异常！\n");
            //     return -1;
            // }
            // else if(move_node == (list_link)0)
            // {
            //     printf("未找到该节点！\n");
            //     return 0;
            // }
            // else
            // {
                
                
            //         move_node->prev->next=move_node->next;
            //         move_node->next->prev = move_node->prev;

            //         move_node->next = NULL;
            //         move_node->prev =NULL;
                

                
            //         obj_node->next->prev =move_node;
            //         move_node->next =obj_node->next;

            //         obj_node->next =move_node;
            //         move_node->prev = obj_node;
                
            // }
    

            list_link move_node = Search_Link_List_Node(head_node);
            list_link obj_node = Search_Link_List_Node(head_node);
            if(move_node == (list_link)-1||obj_node == (list_link)-1)
            {
                printf("链表异常！\n");
                return -1;
            }
            else if(move_node == (list_link)0||obj_node == (list_link)0)
            {
                printf("未找到该节点！\n");
                return 0;
            }
            else 
            {
                move_node->prev->next=move_node->next;
                    move_node->next->prev = move_node->prev;

                    move_node->next = NULL;
                    move_node->prev =NULL;
                

                
                    obj_node->next->prev =move_node;
                    move_node->next =obj_node->next;

                    obj_node->next =move_node;
                    move_node->prev = obj_node;
            }

        
    }
    return 0;
}

int Display_Link_List_Data(list_link head_node)
{
    if(head_node ==(list_link)-1)
    {
        printf("头节点异常！\n");
        return -1;
    }
    else if(head_node->next ==NULL)
    {
        printf("空链表无需输出！\n");
        return 0;
    }
    else 
    {
        for(list_link tmp_node = head_node->next;tmp_node!=head_node;tmp_node = tmp_node->next)
        {
            printf("%s\n",tmp_node->name);
            sleep(1);
        }
    }

    return 0;
}

int Destroy_List(list_link head_node)
{
    if(head_node == (list_link)NULL)
    {
        printf("链表异常！\n");
        return -1;
    }
    else if(head_node->next ==(list_link)NULL)
    {
        printf("空链表，直接释放头节点！\n");
        free(head_node);
    }
    else 
    {
        list_link del_node =head_node->next;
        while(head_node->next != head_node)
        {
            
            
                del_node =head_node->next;
                del_node->next->prev =head_node;
                head_node->next =del_node->next;

                del_node->prev =NULL;
                del_node->next = NULL;
                printf("----\n");

               
            
             free(del_node);

        }
        free(head_node);
    }
     
    return 0;

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