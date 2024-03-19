//
// Created by XZBbb on 2024/3/17.
//

#ifndef QG_WEEK1_LINKEDLIST_H
#define QG_WEEK1_LINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};

// 函数原型声明
struct Node *newnode(struct Node *headnode);                   //创建新节点
int destroylist(struct Node *headnode);                        //销毁链表
void deletenode(struct Node *headnode);                        //删除节点
int search(struct Node *headnode);                    //查找节点
void insertnode(struct Node **headnode);                       //插入节点
void printlinklist(struct Node *headnode);                     //打印链表数据

#endif //QG_WEEK1_LINKEDLIST_H
