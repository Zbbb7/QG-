#include <stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main() {
    struct Node *headnode=NULL;
    int temp;
    printf("1�������½ڵ�\n");
    printf("2����������\n");
    printf("3��ɾ���ڵ�\n");
    printf("4������\n");
    printf("5������һ���ڵ�\n");
    printf("6��������������\n");
    printf("7���˳�����\n");
    int choose;
    printf("�����빦��ǰ�����ѡ��Ҫʹ�õĹ��ܣ�");
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
                printf("Ҫ���ҵ������ڵ�%d���ڵ�\n",temp);
                break;

            case 5:
                insertnode(&headnode);
                break;

            case 6:
                printlinklist(headnode);
                break;

            case 7:
                printf("�˳�����\n");
                system("pause");
                return 0;

            default :
                printf("����ѡ�����\n");
                break;
        }
        printf("�Ƿ���Ҫ����ʹ�ã������Ӧ��ţ���");
        scanf("%d",&choose);
    }
    system("pause");
    return 0;
}

struct Node *newnode(struct Node *headnode){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    printf("�������½ڵ�����ݣ�");
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
}                                                   //����һ���½ڵ�                                 //�����½ڵ�

int destroylist(struct Node *headnode){
    if(headnode==NULL){
        printf("�����٣�\n");
        return 0;
    }
    else{
        struct Node *ptr=headnode;
        while(ptr!=NULL){
            struct Node *next=ptr->next;
            free(ptr);
            ptr=next;

        }
        printf("������\n");
        return 1;
    }
}                                                  //��������

void deletenode(struct Node *headnode){
    int deletedata;
    printf("������Ҫɾ�������ݣ�");
    scanf("%d",&deletedata);
    if(headnode==NULL){
        printf("����Ϊ�գ�\n");
    }
    else{
        struct Node *ptr1,*ptr2;
        ptr1=ptr2=headnode;
        while(ptr1->data!=deletedata&&ptr1->next!=NULL){
            ptr2=ptr1;                                                                         //��¼Ҫɾ���ڵ����һ���ڵ�
            ptr1=ptr1->next;
        }
        if(ptr1->data==deletedata){
            ptr2->next=ptr1->next;
            free(ptr1);
            printf("ɾ���ɹ���\n");
        }
        else{
            printf("�������޴����ݣ�\n");
        }
    }
}                                                                 //ɾ���ڵ�

int search(struct Node *headnode){
    if(headnode==NULL){
        printf("����Ϊ�գ�\n");
        return -1;
    }
    else {
        int position=0;
        int searchdata;
        printf("������Ҫ���ҵ����ݣ�");
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
            printf("û�����������ҵ������ݣ�\n");
            return 0;
        }
    }
}                               //���������������λ��

void printlinklist(struct Node *headnode){
    if(headnode==NULL){
        printf("����Ϊ�գ��޷���ӡ��\n");
        return;
    }
    else{
        struct Node *ptr=headnode;
        printf("�����������£�\n");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}                                                                       //��ӡ��������

void insertnode(struct Node **headnode){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node *current=*headnode;
    printf("������Ҫ���������");
    scanf("%d",&ptr->data);
    int place,place2;
    printf("��ѡ��Ҫ�����λ�ã�\n");
    printf("1��ͷ��\n");
    printf("2���м�\n");
    printf("3��β��\n");
    printf("�����룺");
    scanf("%d",&place);
    switch(place){
        case 1:
            ptr->pre=NULL;
            ptr->next=*headnode;
            (*headnode)->pre=ptr;
            *headnode=ptr;
            break;

        case 2:
            printf("������Ҫ�����λ��(>1)��");
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
            printf("ѡ����Ч��\n");
            break;
    }
}                                                 //����һ���ڵ�