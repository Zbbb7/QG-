#include <stdio.h>
#include"calculator.h"
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main() {
    char str[250];
    printf("������һ���������ʽ�����Ȳ�����200���ַ����м䲻Ҫ�пո񣩣�\n");
    scanf("%s",str);
    printf("��׺���ʽΪ��");
    trans(str);
    printf("\n�������ʽ�Ľ��Ϊ��");
    system("pause");
    return 0;
}

void initialize(struct linkstack *stack){
    stack->top=NULL;                 //��ջ��ָ���ÿ�
    stack->count=0;                  //ջ��Ԫ�س�ʼ��Ϊ0
}//��ʼ��ջ

void pushstack(struct linkstack *stack,char value){
    struct stacknode *newnode=(struct stacknode*)malloc(sizeof(struct stacknode));
    newnode->next=stack->top;
    stack->top=newnode;
    newnode->data=value;
    stack->count++;
}//��������ջ

char popstack(struct linkstack *stack){
    if(stack->top==NULL){
        printf("ջΪ�գ��޷���ջ��\n");
        return -1;
    }
    else{
        struct stacknode *temp=stack->top;
        char tempdata=temp->data;
        stack->top=temp->next;
        free(temp);
        stack->count--;
        return tempdata;
    }
}//��������ջ

int isempty(struct linkstack *stack){
   return stack->top==NULL;
}

char operator(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/');
}//�ж��Ƿ�Ϊ�����

char getTopLStack(struct linkstack *stack){
    if(stack->top==NULL){
        return -1;
    }
    else return stack->top->data;
}//��ȡջ���������

int prioroperator(char c){
    if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else return -1;//�������
}//�ж�Ԥ��������ȼ�

void trans(char *str){               //��׺���ʽת��׺���ʽ
    struct linkstack stack;             //����һ��ջ���������
    initialize(&stack);
    int len=strlen(str);                //�ַ����ĳ���
    for(int i=0;i<=len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            printf("%c ",str[i]);
        }                               //����ֱ�����
        else if(str[i]=='('){
            pushstack(&stack,str[i]);
        }                             //�����ţ�ֱ����ջ
        else if(str[i]==')'){
           while(!isempty(&stack)&&getTopLStack(&stack)!='('){
               printf("%c ",popstack(&stack));//�����ţ���ջ�����������ջֱ�������š�
           }
        }
        else if(operator(str[i])){
            while(!isempty(&stack)&&prioroperator(str[i])<=prioroperator(stack.top->data)){
                printf("%c ",popstack(&stack));
            }//�����С�ڵ���ջ�������������ջ�������������������ٱȽ��µ�ջ���������ֱ������
            pushstack(&stack,str[i]);
        }
    }
    while(!isempty(&stack)){
        printf("%c",stack.top->data);
        popstack(&stack);
    }//һ�������ջ�в����������
}