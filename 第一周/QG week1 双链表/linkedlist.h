//
// Created by XZBbb on 2024/3/17.
//

#ifndef QG_WEEK1_˫����_LINKEDLIST_H
#define QG_WEEK1_˫����_LINKEDLIST_H

struct Node{
    int data;
    struct Node *pre;                        //ǰָ��
    struct Node *next;                       //��ָ��
};

struct Node *newnode(struct Node *headnode);         //����һ���½ڵ�
int destroylist(struct Node *headnode);             //��������
void deletenode(struct Node *headnode);             //ɾ���ڵ�
int search(struct Node *headnode);                 //�����������ڵĽڵ�λ��
void printlinklist(struct Node *headnode);         //��ӡ���������
void insertnode(struct Node **headnode);           //����һ���ڵ�

#endif //QG_WEEK1_˫����_LINKEDLIST_H
