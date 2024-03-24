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
        printf("可使用的功能如下：\n");
        printf("1、初始化栈\n");
        printf("2、判断栈是否为空\n");
        printf("3、得到栈顶元素\n");
        printf("4、清空栈\n");
        printf("5、销毁栈\n");
        printf("6、检测栈长度\n");
        printf("7、入栈\n");
        printf("8、出栈\n");
        printf("9、打印栈的数据\n");
        printf("10、退出程序\n");
        printf("请输入序号选择使用的功能：");
        scanf("%d", &temp);
        if(temp < 1 || temp > 10) {
            clearinputbuffer();
            printf("输入错误，请重新输入\n");
            continue;
        }
        switch (temp) {
            case 1:
                initialize(&stack);
                break;

            case 2:
                result=isEmptyLStack(&stack);
                if(result==-1){
                    printf("栈为空\n");
                }
                else printf("栈不为空！\n");
                break;

            case 3:
                result = getTopLStack(&stack);
                printf("栈顶元素为：%d", result);
                break;

            case 4:
                result = clearLStack(&stack);
                if (result == 1) {
                    printf("已清空\n");
                }
                break;

            case 5:
                destroyLStack(&stack);
                break;

            case 6:
                result = LStackLength(&stack);
                printf("栈长度为：%d", result);
                break;

            case 7:
                pushLStack(&stack);
                break;

            case 8:
                result=popLStack(&stack);
                printf("弹出的数据为：%d",result);
                break;

            case 9:
                printf("当前栈的数据为：");
                printlinkstack(&stack);
                break;

            case 10:
                printf("退出！\n");
                system("pause");
                return 0;
        }
        printf("\n");
    }
}

void initialize(struct LinkStack *stack){
    stack->top=NULL;                 //将栈顶指针置空
    stack->count=0;                  //栈内元素初始化为0
    printf("初始化成功！\n");
}                                                                               //初始化栈

int isEmptyLStack(struct LinkStack *stack){
    if(stack->count>0){
        return 1;
    }
    else{
        return -1;
    }
}                                                                              //判断栈是否为空

int getTopLStack(struct LinkStack *stack){
    if(isEmptyLStack(stack)==-1){
        printf("栈为空，无法获取栈顶元素！\n");
        return -1;
    }
    else return stack->top->data;
}                                                                             //得到栈顶元素

int clearLStack(struct LinkStack *stack){
    if(stack->count==0){
        printf("栈初始为空！");
        return -1;
    }
    else{
        printf("清空前栈的数据：");
        printlinkstack(stack);
        printf("\n");
        struct StackNode *current=stack->top;//设置一个指针表示栈顶节点
        for(int i=1;i<=stack->count;i++){
            current->data=0;
            current=current->next;
        }
    }
    printf("清空后栈的数据：");
    printlinkstack(stack);
    printf("\n");
    return 1;
}                                                                             //清空栈

int destroyLStack(struct LinkStack *stack){
    if(isEmptyLStack(stack)==-1){
        printf("栈初始为空，无需删除！\n");
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
        printf("已销毁！\n");
        return 1;
    }
}                                                                             //销毁栈

int  LStackLength(struct LinkStack *stack){
    if(isEmptyLStack(stack)==-1){
        printf("栈为空！\n");
    }
    else return stack->count;
}                                                                            //检测栈长度

void pushLStack(struct LinkStack *stack){
    struct StackNode *newnode=(struct StackNode*)malloc(sizeof(struct StackNode));
    printf("请输入要加入的数据：");
    scanf("%d",&newnode->data);
    newnode->next=stack->top;
    stack->top=newnode;
    stack->count++;
}                                                                             //入栈

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
        return data;               //返回弹出的值
    }
}                                                                            //出栈

void clearinputbuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);    //清除缓冲区多余字符
}                                                                            //防止选择功能时输入非数字导致死循环

void printlinkstack(struct LinkStack *stack){
    struct StackNode *current=stack->top;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}                                                                            //打印栈的数据