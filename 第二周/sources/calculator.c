#include <stdio.h>
#include"calculator.h"
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main() {
    char str[250];
    printf("请输入一个算术表达式（长度不超过200个字符，中间不要有空格）：\n");
    scanf("%s",str);
    printf("后缀表达式为：");
    trans(str);
    printf("\n算术表达式的结果为：");
    system("pause");
    return 0;
}

void initialize(struct linkstack *stack){
    stack->top=NULL;                 //将栈顶指针置空
    stack->count=0;                  //栈内元素初始化为0
}//初始化栈

void pushstack(struct linkstack *stack,char value){
    struct stacknode *newnode=(struct stacknode*)malloc(sizeof(struct stacknode));
    newnode->next=stack->top;
    stack->top=newnode;
    newnode->data=value;
    stack->count++;
}//操作符入栈

char popstack(struct linkstack *stack){
    if(stack->top==NULL){
        printf("栈为空，无法出栈！\n");
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
}//操作符出栈

int isempty(struct linkstack *stack){
   return stack->top==NULL;
}

char operator(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/');
}//判断是否为运算符

char getTopLStack(struct linkstack *stack){
    if(stack->top==NULL){
        return -1;
    }
    else return stack->top->data;
}//获取栈顶的运算符

int prioroperator(char c){
    if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else return -1;//非运算符
}//判断预算符的优先级

void trans(char *str){               //中缀表达式转后缀表达式
    struct linkstack stack;             //创建一个栈保存运算符
    initialize(&stack);
    int len=strlen(str);                //字符串的长度
    for(int i=0;i<=len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            printf("%c ",str[i]);
        }                               //数字直接输出
        else if(str[i]=='('){
            pushstack(&stack,str[i]);
        }                             //左括号，直接入栈
        else if(str[i]==')'){
           while(!isempty(&stack)&&getTopLStack(&stack)!='('){
               printf("%c ",popstack(&stack));//右括号，将栈顶的运算符出栈直到左括号。
           }
        }
        else if(operator(str[i])){
            while(!isempty(&stack)&&prioroperator(str[i])<=prioroperator(stack.top->data)){
                printf("%c ",popstack(&stack));
            }//运算符小于等于栈顶的运算符，将栈顶运算符弹出并输出，再比较新的栈顶运算符，直到大于
            pushstack(&stack,str[i]);
        }
    }
    while(!isempty(&stack)){
        printf("%c",stack.top->data);
        popstack(&stack);
    }//一并输出堆栈中残留的运算符
}