//
// Created by XZBbb on 2024/3/23.
//

#ifndef QG_LINKSTACK_H
#define QG_LINKSTACK_H

struct StackNode{
    int data;
    struct StackNode *next;
};                                      //定义栈节点结构

struct LinkStack{
    struct StackNode *top;              //定义栈顶指针
    int count;                          //代表链栈中元素个数
};                                      //定义栈顶结构

void initialize(struct LinkStack *stack);//初始化栈
int isEmptyLStack(struct LinkStack *stack);//判断栈是否为空
int getTopLStack(struct LinkStack *stack);//得到栈顶元素
int clearLStack(struct LinkStack *stack);//清空栈
int destroyLStack(struct LinkStack *stack);//销毁栈
int  LStackLength(struct LinkStack *stack);//检测栈长度
void pushLStack(struct LinkStack *stack);//入栈
int popLStack(struct LinkStack *stack);//出栈
void printlinkstack(struct LinkStack *stack);//打印栈的数据
void clearinputbuffer();//防止选择功能时输入非数字导致死循环

#endif //QG_LINKSTACK_H
