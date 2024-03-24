//
// Created by XZBbb on 2024/3/24.
//

#ifndef QG_LINKQUEUE_H
#define QG_LINKQUEUE_H
struct QueueNode{
    void* data;                               //节点数据域
    struct QueueNode *next;                  //节点指针域
};


struct LinkQueue{
    struct QueueNode *head;
    struct QueueNode *tail;
};

void InitQueue(struct LinkQueue *queue);//构造
void DestroyQueue(struct LinkQueue *queue);//销毁
void EnQueue(struct LinkQueue *queue);//入队
void* DeQueue(struct LinkQueue *queue);//出队
void* ClearQueue(struct LinkQueue *queue);//清空
void* GetHeadQueue(struct LinkQueue *queue);//查看队头
int IsEmptyQueue(struct LinkQueue *queue);//判空
void LengthQueue(struct LinkQueue *queue);//队列长度
void clearinputbuffer();//清除缓冲区多余字符
#endif //QG_LINKQUEUE_H
