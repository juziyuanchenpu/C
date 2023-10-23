#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define ONCE_INPUT_DATA_LEN  20
#define EXIT "exit"


int Keybroad_Input_Data_To_File(char * obj_file);
int Keybroad_Input_Data_To_File(char * obj_file)
{
    umask(0000);
    int fd = open(obj_file, O_WRONLY|O_TRUNC,0777);
    if(fd == -1)
    {
        perror("打开失败！");
        return -1;
    }

    char file_data_buf[ONCE_INPUT_DATA_LEN];
    char new_data_buf[ONCE_INPUT_DATA_LEN];
    while(1)
    {
        memset(file_data_buf,0,ONCE_INPUT_DATA_LEN);
        memset(new_data_buf,0,ONCE_INPUT_DATA_LEN);
        printf("请输入要写入的数据：");
        scanf("%s",file_data_buf);
        while(getchar() != '\n');
        

        if(strcmp(file_data_buf,EXIT) == 0)
        {
            perror("写入数据完成！\n");
            break;
        }

        //sprintf(new_data_buf, "%s%s", file_data_buf, "\r");
       
        strcat(file_data_buf, "\r");//, sizeof(file_data_buf) - strlen(file_data_buf) - 1);


        if(write(fd,file_data_buf,strlen(file_data_buf)) == -1)
        {
            perror("写入数据失败！");
            return -1;
        }
       

    } 
    if(close(fd) == -1)
        {   
            perror("关闭文件失败！\n");
            return -1;
        }
    return 0;
}

int main (int argc, char * argv[])
{
    if(argc != 2)
    {
        printf("输入的参数有误！\n");
        return -1;
    }

    if(Keybroad_Input_Data_To_File(argv[1]) == -1)
    {
        printf("demo 运行失败！\n");
        return -1;
    }
}