#include <stdio.h>
#include<stdlib.h>
#include"linkqueue.h"
#include<windows.h>
int main() {
    struct LinkQueue queue;
    queue.head=queue.tail=NULL;
    void* result;
    while(1){
        int temp;
        printf("��ʹ�õĹ������£�\n");
        printf("1���������\n");
        printf("2�����ٶ���\n");
        printf("3�����\n");
        printf("4������\n");
        printf("5����ն���\n");
        printf("6���鿴��ͷ\n");
        printf("7���п�\n");
        printf("8�����г���\n");
        printf("9���˳�����\n");
        printf("������ѡ�õĹ��ܣ�");
        scanf_s("%d",&temp);
        if(temp < 1 || temp > 9) {
            clearinputbuffer();
            printf("�����������������\n");
            continue;
        }
        switch (temp) {
            case 1:
                InitQueue(&queue);
                break;

            case 2:
                DestroyQueue(&queue);
                break;

            case 3:
                EnQueue(&queue);
                break;

            case 4:
                result=DeQueue(&queue);
                printf("���н��Ϊ��%d\n",*(int*)result);//��ûѧ����ô�жϲ�ͬ����Ȼ���������������
                break;

            case 5:
                ClearQueue(&queue);
                break;

            case 6:
                GetHeadQueue(&queue);
                break;

            case 7:
                IsEmptyQueue(&queue);
                break;

            case 8:
                LengthQueue(&queue);
                break;

            case 9:
                printf("�˳���\n");
                system("pause");
                return 0;
        }
        printf("\n");
    }
}


void InitQueue(struct LinkQueue *queue){
    queue->head=queue->tail=NULL;
    printf("��ʼ���ɹ���\n");
}                                          //��ʼ������

void DestroyQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("��ǰ������Ϊ�գ��������٣�\n");
        return;
    }
    while(queue->head!=NULL) {
        struct QueueNode *current = queue->head;
        queue->head=queue->head->next;
        free(current);
    }
    queue->tail=NULL;
    printf("���ٳɹ���");
}//���ٶ���

void EnQueue(struct LinkQueue *queue){
    int i=0;
    char ch;
    char a[300]={0};
    struct QueueNode *newnode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    while(1){
        printf("��ѡ���������������\n");
        printf("1������\n");
        printf("2���ַ���\n");
        printf("3��������\n");
        printf("4���ַ���\n");
        printf("��ѡ��");
        int type;
        scanf_s("%d",&type);
        if(type < 1 || type > 4) {
            clearinputbuffer();
            printf("�����������������\n");
            continue;
        }
        else {
            switch(type){
                case 1:
                    newnode->data=malloc(sizeof(int));
                    printf("������һ���������ݣ�");
                    scanf_s("%d",(int*)newnode->data);
                    break;

                case 2:
                    newnode->data=malloc(sizeof(char));
                    printf("������һ���ַ�����:");
                    *(char*)newnode->data=getchar();
                    break;

                case 3:
                    newnode->data=malloc(sizeof(float));
                    printf("������һ������������:");
                    scanf_s("%f",(float*)newnode->data);
                    break;

                case 4:
                    while((ch=getchar())!='\n'){
                        a[i]=ch;
                        i++;
                    }
                    a[i]='\0';
                    strcpy_s((char*)newnode->data,sizeof(a),a);
                    break;

                default:
                    break;
            }
        }
        break;
    }

    if(IsEmptyQueue(queue)==-1){
        queue->head=queue->tail=newnode;
        newnode->next=NULL;
    }
    else{
        queue->tail->next=newnode;
        queue->tail=newnode;
        newnode->next=NULL;
    }
}//����

void *DeQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("��ǰ����Ϊ�գ�\n");
        return NULL;
    }
    struct QueueNode *temp=queue->head;
    queue->head=queue->head->next;
    return temp->data;
}//����

void* ClearQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("��ǰ����Ϊ�գ�\n");
        return NULL;
    }
    struct QueueNode *current=queue->head;
    while(current->next!=NULL){
        *(int*)(current->data)=0;
        current=current->next;
    }
}//��ն���

void* GetHeadQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("��ǰ��ͷΪ�գ�\n");
        return NULL;
    }
    else return queue->head->data;
}//�鿴��ͷ

int IsEmptyQueue(struct LinkQueue *queue){
    if(queue->head==NULL){
        return -1;
    }
    else {
        return 1;
    }
}//�п�

void LengthQueue(struct LinkQueue *queue){
    int count=1;
    if(IsEmptyQueue(queue)==-1){
        printf("��ǰ����Ϊ�գ�����Ϊ0\n");
        return;
    }
    else{
        struct QueueNode *current=queue->head;
        while(current->next!=NULL){
            count++;
            current=current->next;
        }
    }
    printf("��ǰ���г���Ϊ��%d",count);

}//���г���

void clearinputbuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);    //��������������ַ�
}