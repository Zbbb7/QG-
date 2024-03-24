#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"Linkstack.h"
int main() {
    struct LinkStack stack;
    initialize(&stack);
    int result;
    while(1) {
        int temp;
        printf("��ʹ�õĹ������£�\n");
        printf("1����ʼ��ջ\n");
        printf("2���ж�ջ�Ƿ�Ϊ��\n");
        printf("3���õ�ջ��Ԫ��\n");
        printf("4�����ջ\n");
        printf("5������ջ\n");
        printf("6�����ջ����\n");
        printf("7����ջ\n");
        printf("8����ջ\n");
        printf("9����ӡջ������\n");
        printf("10���˳�����\n");
        printf("���������ѡ��ʹ�õĹ��ܣ�");
        scanf("%d", &temp);
        if(temp < 1 || temp > 10) {
            clearinputbuffer();
            printf("�����������������\n");
            continue;
        }
        switch (temp) {
            case 1:
                initialize(&stack);
                break;

            case 2:
                result=isEmptyLStack(&stack);
                if(result==-1){
                    printf("ջΪ��\n");
                }
                else printf("ջ��Ϊ�գ�\n");
                break;

            case 3:
                result = getTopLStack(&stack);
                printf("ջ��Ԫ��Ϊ��%d", result);
                break;

            case 4:
                result = clearLStack(&stack);
                if (result == 1) {
                    printf("�����\n");
                }
                break;

            case 5:
                destroyLStack(&stack);
                break;

            case 6:
                result = LStackLength(&stack);
                printf("ջ����Ϊ��%d", result);
                break;

            case 7:
                pushLStack(&stack);
                break;

            case 8:
                result=popLStack(&stack);
                printf("����������Ϊ��%d",result);
                break;

            case 9:
                printf("��ǰջ������Ϊ��");
                printlinkstack(&stack);
                break;

            case 10:
                printf("�˳���\n");
                system("pause");
                return 0;
        }
        printf("\n");
    }
}

void initialize(struct LinkStack *stack){
    stack->top=NULL;                 //��ջ��ָ���ÿ�
    stack->count=0;                  //ջ��Ԫ�س�ʼ��Ϊ0
    printf("��ʼ���ɹ���\n");
}                                                                               //��ʼ��ջ

int isEmptyLStack(struct LinkStack *stack){
    if(stack->count>0){
        return 1;
    }
    else{
        return -1;
    }
}                                                                              //�ж�ջ�Ƿ�Ϊ��

int getTopLStack(struct LinkStack *stack){
    if(isEmptyLStack(stack)==-1){
        printf("ջΪ�գ��޷���ȡջ��Ԫ�أ�\n");
        return -1;
    }
    else return stack->top->data;
}                                                                             //�õ�ջ��Ԫ��

int clearLStack(struct LinkStack *stack){
    if(stack->count==0){
        printf("ջ��ʼΪ�գ�");
        return -1;
    }
    else{
        printf("���ǰջ�����ݣ�");
        printlinkstack(stack);
        printf("\n");
        struct StackNode *current=stack->top;//����һ��ָ���ʾջ���ڵ�
        for(int i=1;i<=stack->count;i++){
            current->data=0;
            current=current->next;
        }
    }
    printf("��պ�ջ�����ݣ�");
    printlinkstack(stack);
    printf("\n");
    return 1;
}                                                                             //���ջ

int destroyLStack(struct LinkStack *stack){
    if(isEmptyLStack(stack)==-1){
        printf("ջ��ʼΪ�գ�����ɾ����\n");
        return 0;
    }
    else{
        struct StackNode *current=stack->top;
        while(current!=NULL){
            struct StackNode *temp=current;
            current=current->next;
            free(temp);
        }
        stack->top=NULL;
        stack->count=0;
        printf("�����٣�\n");
        return 1;
    }
}                                                                             //����ջ

int  LStackLength(struct LinkStack *stack){
    if(isEmptyLStack(stack)==-1){
        printf("ջΪ�գ�\n");
    }
    else return stack->count;
}                                                                            //���ջ����

void pushLStack(struct LinkStack *stack){
    struct StackNode *newnode=(struct StackNode*)malloc(sizeof(struct StackNode));
    printf("������Ҫ��������ݣ�");
    scanf("%d",&newnode->data);
    newnode->next=stack->top;
    stack->top=newnode;
    stack->count++;
}                                                                             //��ջ

int popLStack(struct LinkStack *stack){
    if(isEmptyLStack(stack)==-1){
        return -1;
    }
    else{
        struct StackNode *temp=stack->top;
        int data=temp->data;
        stack->top=temp->next;
        free(temp);
        stack->count--;
        return data;               //���ص�����ֵ
    }
}                                                                            //��ջ

void clearinputbuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);    //��������������ַ�
}                                                                            //��ֹѡ����ʱ��������ֵ�����ѭ��

void printlinkstack(struct LinkStack *stack){
    struct StackNode *current=stack->top;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}                                                                            //��ӡջ������