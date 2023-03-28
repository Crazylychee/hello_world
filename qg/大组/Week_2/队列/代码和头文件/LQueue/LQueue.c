#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
    Q->front = Q->rear = (Node *) malloc(sizeof(Node));
    Q->front->next = NULL;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {
    if (Q) {
        free(Q);
    }
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data) {
    //�������û���������
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {
    Q->rear = Q->front;
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q) {
    LQueue *t = (LQueue *) q;
    Node *p = t->front->next; //����ָ��
    if (t->front == t->rear) {//�ж϶����Ƿ�Ϊ��
        printf("����Ϊ�գ�\n");
        return;
    }
    printf("��ǰ����Ϊ��\n");
    while (p != NULL) {
        if (!(t->front->data)) return;
        printf("%d\t", *(int*)(p->data));
        p = p->next;//����ָ�����
    }
    printf("\n");
    return;
};
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED
