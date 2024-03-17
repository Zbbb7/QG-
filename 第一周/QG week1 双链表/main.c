#include <stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main() {
    struct Node *headnode=NULL;
    int temp;
    printf("1、创建新节点\n");
    printf("2、销毁链表\n");
    printf("3、删除节点\n");
    printf("4、查找\n");
    printf("5、插入一个节点\n");
    printf("6、输出链表的数据\n");
    printf("7、退出程序\n");
    int choose;
    printf("请输入功能前的序号选择要使用的功能：");
    scanf("%d",&choose);
    while(choose>=1&&choose<=7){
        switch(choose){
            case 1:
                headnode=newnode(headnode);
                break;

            case 2:
                destroylist(headnode);
                break;

            case 3:
                deletenode(headnode);
                break;

            case 4:
                temp=search(headnode);
                printf("要查找的数据在第%d个节点\n",temp);
                break;

            case 5:
                insertnode(&headnode);
                break;

            case 6:
                printlinklist(headnode);
                break;

            case 7:
                printf("退出程序\n");
                system("pause");
                return 0;

            default :
                printf("功能选择错误！\n");
                break;
        }
        printf("是否需要继续使用（输入对应序号）：");
        scanf("%d",&choose);
    }
    system("pause");
    return 0;
}

struct Node *newnode(struct Node *headnode){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("请输入新节点的数据：");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(headnode==NULL){
        ptr->pre=NULL;
        headnode=ptr;
    }
    else{
        struct Node *current=headnode;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=ptr;
        ptr->pre=current;
    }
    return headnode;
}                                                   //创建一个新节点                                 //创建新节点

int destroylist(struct Node *headnode){
    if(headnode==NULL){
        printf("已销毁！\n");
        return 0;
    }
    else{
        struct Node *ptr=headnode;
        while(ptr!=NULL){
            struct Node *next=ptr->next;
            free(ptr);
            ptr=next;

        }
        printf("已销毁\n");
        return 1;
    }
}                                                  //销毁链表

void deletenode(struct Node *headnode){
    int deletedata;
    printf("请输入要删除的数据：");
    scanf("%d",&deletedata);
    if(headnode==NULL){
        printf("链表为空！\n");
    }
    else{
        struct Node *ptr1,*ptr2;
        ptr1=ptr2=headnode;
        while(ptr1->data!=deletedata&&ptr1->next!=NULL){
            ptr2=ptr1;                                                                         //记录要删除节点的上一个节点
            ptr1=ptr1->next;
        }
        if(ptr1->data==deletedata){
            ptr2->next=ptr1->next;
            free(ptr1);
            printf("删除成功！\n");
        }
        else{
            printf("链表中无此数据！\n");
        }
    }
}                                                                 //删除节点

int search(struct Node *headnode){
    if(headnode==NULL){
        printf("链表为空！\n");
        return -1;
    }
    else {
        int position=0;
        int searchdata;
        printf("请输入要查找的数据：");
        scanf("%d",&searchdata);
        struct Node *ptr=headnode;
        while(ptr->data!=searchdata&&ptr->next!=NULL){
            ptr=ptr->next;
            position++;
        }
        if(ptr->data==searchdata){
            return position;
        }
        else {
            printf("没有在链表中找到此数据！\n");
            return 0;
        }
    }
}                               //查找数据在链表的位置

void printlinklist(struct Node *headnode){
    if(headnode==NULL){
        printf("链表为空，无法打印！\n");
        return;
    }
    else{
        struct Node *ptr=headnode;
        printf("链表数据如下：\n");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}                                                                       //打印链表数据

void insertnode(struct Node **headnode){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *current=*headnode;
    printf("请输入要插入的数据");
    scanf("%d",&ptr->data);
    int place,place2;
    printf("请选择要插入的位置：\n");
    printf("1、头部\n");
    printf("2、中间\n");
    printf("3、尾部\n");
    printf("请输入：");
    scanf("%d",&place);
    switch(place){
        case 1:
            ptr->pre=NULL;
            ptr->next=*headnode;
            (*headnode)->pre=ptr;
            *headnode=ptr;
            break;

        case 2:
            printf("请输入要插入的位置(>1)：");
            scanf("%d",&place2);
            for(int i=1;i<place2-1;i++){
                current=current->next;
            }
            ptr->next=current->next;
            ptr->pre=current;
            current->next=ptr;
            break;

        case 3:
            while(current!=NULL){
                current=current->next;
            }
            current->next=ptr;
            ptr->pre=current;
            ptr->next=NULL;
            break;

        default:
            printf("选择无效！\n");
            break;
    }
}                                                 //插入一个节点