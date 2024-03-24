//
// Created by XZBbb on 2024/3/24.
//

#ifndef CACULATOR_CALCULATOR_H
#define CACULATOR_CALCULATOR_H


struct stacknode{
    char data;
    struct stacknode *next;
};

struct linkstack{
    struct stacknode *top;
    int count;
};

void initialize(struct linkstack *stack);//初始化栈
void pushstack(struct linkstack *stack,char value);//操作符入栈
char popstack(struct linkstack *stack);//操作符出栈
char operator(char c);//判断运算符
char getTopLStack(struct linkstack *stack);//获取栈顶的运算符
int prioroperator(char c);//判断运算符的优先级
void trans(char *str);//转换为后缀表达式
int isempty(struct linkstack *stack);//判断栈是否为空
#endif //CACULATOR_CALCULATOR_H
