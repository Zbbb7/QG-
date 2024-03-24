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
        printf("可使用的功能如下：\n");
        printf("1、构造队列\n");
        printf("2、销毁队列\n");
        printf("3、入队\n");
        printf("4、出队\n");
        printf("5、清空队列\n");
        printf("6、查看队头\n");
        printf("7、判空\n");
        printf("8、队列长度\n");
        printf("9、退出程序\n");
        printf("请输入选用的功能：");
        scanf_s("%d",&temp);
        if(temp < 1 || temp > 9) {
            clearinputbuffer();
            printf("输入错误，请重新输入\n");
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
                printf("出列结果为：%d\n",*(int*)result);//还没学会怎么判断不同类型然后输出，做不完了
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
                printf("退出！\n");
                system("pause");
                return 0;
        }
        printf("\n");
    }
}


void InitQueue(struct LinkQueue *queue){
    queue->head=queue->tail=NULL;
    printf("初始化成功！\n");
}                                          //初始化队列

void DestroyQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("当前队列已为空，无需销毁！\n");
        return;
    }
    while(queue->head!=NULL) {
        struct QueueNode *current = queue->head;
        queue->head=queue->head->next;
        free(current);
    }
    queue->tail=NULL;
    printf("销毁成功！");
}//销毁队列

void EnQueue(struct LinkQueue *queue){
    int i=0;
    char ch;
    char a[300]={0};
    struct QueueNode *newnode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
    while(1){
        printf("请选择输入的数据类型\n");
        printf("1、整型\n");
        printf("2、字符型\n");
        printf("3、浮点型\n");
        printf("4、字符串\n");
        printf("请选择：");
        int type;
        scanf_s("%d",&type);
        if(type < 1 || type > 4) {
            clearinputbuffer();
            printf("输入错误，请重新输入\n");
            continue;
        }
        else {
            switch(type){
                case 1:
                    newnode->data=malloc(sizeof(int));
                    printf("请输入一个整型数据：");
                    scanf_s("%d",(int*)newnode->data);
                    break;

                case 2:
                    newnode->data=malloc(sizeof(char));
                    printf("请输入一个字符数据:");
                    *(char*)newnode->data=getchar();
                    break;

                case 3:
                    newnode->data=malloc(sizeof(float));
                    printf("请输入一个浮点型数据:");
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
}//入列

void *DeQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("当前队列为空！\n");
        return NULL;
    }
    struct QueueNode *temp=queue->head;
    queue->head=queue->head->next;
    return temp->data;
}//出列

void* ClearQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("当前队列为空！\n");
        return NULL;
    }
    struct QueueNode *current=queue->head;
    while(current->next!=NULL){
        *(int*)(current->data)=0;
        current=current->next;
    }
}//清空队列

void* GetHeadQueue(struct LinkQueue *queue){
    if(IsEmptyQueue(queue)==-1){
        printf("当前队头为空！\n");
        return NULL;
    }
    else return queue->head->data;
}//查看队头

int IsEmptyQueue(struct LinkQueue *queue){
    if(queue->head==NULL){
        return -1;
    }
    else {
        return 1;
    }
}//判空

void LengthQueue(struct LinkQueue *queue){
    int count=1;
    if(IsEmptyQueue(queue)==-1){
        printf("当前队列为空，长度为0\n");
        return;
    }
    else{
        struct QueueNode *current=queue->head;
        while(current->next!=NULL){
            count++;
            current=current->next;
        }
    }
    printf("当前队列长度为：%d",count);

}//队列长度

void clearinputbuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);    //清除缓冲区多余字符
}