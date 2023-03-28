#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
    Q->front = Q->rear = (Node *) malloc(sizeof(Node));
    Q->front->next = NULL;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
    if (Q) {
        free(Q);
    }
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
    if (Q->length == 0)
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e) {
    if(Q->front->next==NULL) {
//        printf("Don't you even want to input a single number ??\n");
        return FALSE;
    }
    printf("%d", Q->front->next->data);
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data) {
    //链表队列没有最大容量
    //    if (IsEmptyLQueue(Q)) {
    //        return FALSE;
    //    }
    Node *t=Q->front;
    Node *p = (Node *) malloc(sizeof(Node));
    p->data=data;p->next=NULL;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=p;
    Q->length += 1;
    Q->rear=t;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
    if (IsEmptyLQueue(Q)) {
        printf("Error! The queue is empty! \n");
        return FALSE;
    }
    Q->front=Q->front->next;
    Q->length -= 1;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
    Q->rear = Q->front;
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)) {
    if(Q->front->next==NULL)
        printf("NULL\n");
    else
    {
        foo(Q);
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q) {
    LQueue *t = (LQueue *) q;
    Node *p = t->front->next; //工作指针
    if (t->front == t->rear) {//判断队列是否为空
        printf("队列为空！\n");
        return;
    }
    printf("当前队列为：\n");
    while (p != NULL) {
        if (!(t->front->data)) return;
        printf("%d\t", *(int*)(p->data));
        p = p->next;//工作指针后移
    }
    printf("\n");
    return;
};
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED
