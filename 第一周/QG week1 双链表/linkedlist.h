//
// Created by XZBbb on 2024/3/17.
//

#ifndef QG_WEEK1_双链表_LINKEDLIST_H
#define QG_WEEK1_双链表_LINKEDLIST_H

struct Node{
    int data;
    struct Node *pre;                        //前指针
    struct Node *next;                       //后指针
};

struct Node *newnode(struct Node *headnode);         //创建一个新节点
int destroylist(struct Node *headnode);             //销毁链表
void deletenode(struct Node *headnode);             //删除节点
int search(struct Node *headnode);                 //查找数据所在的节点位置
void printlinklist(struct Node *headnode);         //打印链表的数据
void insertnode(struct Node **headnode);           //插入一个节点

#endif //QG_WEEK1_双链表_LINKEDLIST_H
