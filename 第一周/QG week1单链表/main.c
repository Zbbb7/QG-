#include <stdio.h>
#include<stdlib.h>
#include"linkedList.h"
#include<windows.h>
int main() {
    int position;
    struct Node *headnode=NULL;
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
                position=search(headnode);
                printf("Ҫ���ҵ������ڵ�%d���ڵ�\n",position);
                break;

            case 5:
                insertnode(&headnode);
                break;

            case 6:
                printlinklist(headnode);
                break;

            case 7:
                printf("�˳�����");
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
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    printf("�������½ڵ�����ݣ�");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (headnode== NULL) {
        headnode = newnode;
    }
    else {
        struct Node *current = headnode;
        while (current->next != NULL) {
            current = current->next;                                         //�ҵ���������һ���ڵ�
        }
        current->next = newnode;
        newnode->next=NULL;
    }
    return headnode;
}                                                                                //�����½ڵ�

int destroylist(struct Node *headnode){
    if(headnode==NULL){
        printf("�����٣�\n");
        return 0;
    }
    struct Node *ptr;
    while(headnode!=NULL){
        ptr=headnode->next;
        free(headnode);
        headnode=ptr;
    }
    printf("�����٣�\n");
    return 1;                                                                    //��������
}

void deletenode(struct Node *headnode){
    int num;
    printf("��������Ҫɾ�������ݣ�");
    scanf("%d",&num);
    struct Node *ptr1,*ptr2;      //1Ϊ��ǰ�ڵ����һ���ڵ㣬2Ϊ��ǰ�ڵ�
    if(headnode==NULL){
        printf("��ǰ����Ϊ�գ��޷�ɾ����\n");
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
        printf("�������޸����ݣ�\n");
    }
}                                                                    //ɾ���ڵ�

int search(struct Node *headnode){
    printf("������Ҫ���ҵ����ݣ�");
    int position=0;
    int num;
    scanf("%d",&num);
    if(headnode==NULL){
        printf("��ǰ����Ϊ�գ�\n");
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
        printf("û�����������ҵ�Ҫ��ѯ�Ľ����\n");
        return -1;
    }
}                                                                      //���ҽڵ�

void insertnode(struct Node **headnode){                        //tempΪҪ���������
    int temp;
    printf("������Ҫ���������");
    scanf("%d",&temp);
    int place,place2;
    struct Node *current=*headnode;
    struct Node *insertnode=(struct Node*)malloc(sizeof(struct Node));
    insertnode->data=temp;
    printf("ѡ��Ҫ�����λ�ã�\n");
    printf("1��ͷ��\n");
    printf("2���м�\n");
    printf("3��β��\n");
    printf("��ѡ��");
    scanf("%d",&place);

    switch(place){
        case 1:
        insertnode->data = temp;
        insertnode->next = *headnode;
        *headnode = insertnode;
        break;

        case 2:
            printf("������Ҫ����Ľڵ�λ�ã�");
            scanf("%d",&place2);
            struct Node *ptr1=*headnode;
            for(int i=1;i<place2&&ptr1!=NULL;i++){
                ptr1=ptr1->next;
            }
            if(ptr1==NULL){
                printf("����ʧ�ܣ�\n");//�޷��ҵ�Ҫ����λ�õ�ǰһ���ڵ�
                return;
            }
            insertnode->data = temp;
            insertnode->next = *headnode;
            *headnode = insertnode;
            break;

        case 3:
            while(current->next!=NULL){
                current=current->next;
            }                                                              //�ҵ���ĩβ�Ľڵ�
            insertnode->data = temp;
            insertnode->next = *headnode;
            *headnode = insertnode;
            break;

        default:
            printf("�������\n");
            break;
    }
}

void printlinklist(struct Node *headnode){
    struct Node *ptr=headnode;
    printf("�����������£�\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}