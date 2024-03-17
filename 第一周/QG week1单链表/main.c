#include <stdio.h>
#include<stdlib.h>
#include"linkedList.h"
#include<windows.h>
int main() {
    int position;
    struct Node *headnode=NULL;
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
                position=search(headnode);
                printf("要查找的数据在第%d个节点\n",position);
                break;

            case 5:
                insertnode(&headnode);
                break;

            case 6:
                printlinklist(headnode);
                break;

            case 7:
                printf("退出程序");
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
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("请输入新节点的数据：");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (headnode== NULL) {
        headnode = newnode;
    }
    else {
        struct Node *current = headnode;
        while (current->next != NULL) {
            current = current->next;                                         //找到链表的最后一个节点
        }
        current->next = newnode;
        newnode->next=NULL;
    }
    return headnode;
}                                                                                //创建新节点

int destroylist(struct Node *headnode){
    if(headnode==NULL){
        printf("已销毁！\n");
        return 0;
    }
    struct Node *ptr;
    while(headnode!=NULL){
        ptr=headnode->next;
        free(headnode);
        headnode=ptr;
    }
    printf("已销毁！\n");
    return 1;                                                                    //销毁链表
}

void deletenode(struct Node *headnode){
    int num;
    printf("请输入想要删除的数据：");
    scanf("%d",&num);
    struct Node *ptr1,*ptr2;      //1为当前节点的上一个节点，2为当前节点
    if(headnode==NULL){
        printf("当前链表为空，无法删除！\n");
        return;
    }
    ptr1=ptr2=headnode;
    while(ptr1->data!=num&&ptr1->next!=NULL){
        ptr2=ptr1;
        ptr1=ptr1->next;
    }
    if(ptr1->data==num){
        if(ptr1==headnode){
            headnode=ptr1->next;
        }
        else {
            ptr2->next=ptr1->next;
        }
        free(ptr1);
    }
    else {
        printf("链表中无该数据！\n");
    }
}                                                                    //删除节点

int search(struct Node *headnode){
    printf("请输入要查找的数据：");
    int position=0;
    int num;
    scanf("%d",&num);
    if(headnode==NULL){
        printf("当前链表为空！\n");
        return -1;
    }
    else{
        struct Node *ptr=headnode;
        while(ptr!=NULL){
        if(ptr->data==num){
            return position;
        }
        else{
            ptr=ptr->next;
            position++;
        }
    }
        printf("没有在链表中找到要查询的结果！\n");
        return -1;
    }
}                                                                      //查找节点

void insertnode(struct Node **headnode){                        //temp为要插入的数据
    int temp;
    printf("请输入要插入的数据");
    scanf("%d",&temp);
    int place,place2;
    struct Node *current=*headnode;
    struct Node *insertnode=(struct Node*)malloc(sizeof(struct Node));
    insertnode->data=temp;
    printf("选择要插入的位置：\n");
    printf("1、头部\n");
    printf("2、中间\n");
    printf("3、尾部\n");
    printf("请选择：");
    scanf("%d",&place);

    switch(place){
        case 1:
        insertnode->data = temp;
        insertnode->next = *headnode;
        *headnode = insertnode;
        break;

        case 2:
            printf("请输入要插入的节点位置：");
            scanf("%d",&place2);
            struct Node *ptr1=*headnode;
            for(int i=1;i<place2&&ptr1!=NULL;i++){
                ptr1=ptr1->next;
            }
            if(ptr1==NULL){
                printf("插入失败！\n");//无法找到要插入位置的前一个节点
                return;
            }
            insertnode->data = temp;
            insertnode->next = *headnode;
            *headnode = insertnode;
            break;

        case 3:
            while(current->next!=NULL){
                current=current->next;
            }                                                              //找到最末尾的节点
            insertnode->data = temp;
            insertnode->next = *headnode;
            *headnode = insertnode;
            break;

        default:
            printf("输入错误！\n");
            break;
    }
}

void printlinklist(struct Node *headnode){
    struct Node *ptr=headnode;
    printf("链表数据如下：\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}