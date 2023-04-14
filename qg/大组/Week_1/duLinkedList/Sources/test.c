//
// Created by yc on 2023/3/19.
//
#include "duLinkedList.h"
void menu()
{
    printf("*************************************\n");
    printf("****** Please input the number ******\n");
    printf("****** 1.InitList_DuL          ******\n");//
    printf("****** 2.DestroyList_DuL       ******\n");//
    printf("****** 3.InsertBeforeList_DuL  ******\n");//
    printf("****** 4.InsertAfterList_DuL   ******\n");//
    printf("****** 5.DeleteList_DuL        ******\n");//
    printf("****** 6.TraverseList_DuL      ******\n");//
    printf("****** 7.create a test list    ******\n");//创建一个测试用链表
    printf("*************************************\n");//

}
Status InitList_DuL(DuLinkedList *L){
    DuLNode *phead=(DuLNode*) malloc(DEN);
    if(!phead)
    {
        return OVERFLOW;
    }
    phead->next = phead;
    phead->prior = phead;
    *L=phead;
    printf("Successfully initialize a DuLinkedList!\n");
    return SUCCESS;
}
void DestroyList_DuL(DuLinkedList *L){
    while(*L!=NULL){
        *L=(*L)->next;
    }
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
    int x=0;
    x=q->data;
    ListInsert(p,x);
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
    DuLinkedList pnext = p;
    int i = 1;
    int n;

    while((i<n) && (pnext != NULL))
    {
        i++;
        pnext = pnext->next;

    }

    if(pnext == NULL)
    {
        return ERROR;
    }
    else
    {
        q->next = pnext->next;
        if(n = 0)
        {
            pnext->next = q;
            q->next = NULL;
        }
        else
        {
            pnext->next = q;
            pnext->next->prior = q;
            q->prior = pnext;
        }
    }
    return SUCCESS;

}

Status DeleteList_DuL(DuLNode *p, ElemType *e){
    if(p==NULL)return ERROR;
    *e=p->next->data;
    ListErase(p->next);
    return SUCCESS;
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
    ListPrint(L);
}
void ListPrint(DuLNode *phead)
{
    assert(phead);

    DuLNode *cur = phead->next;
    if(cur!=phead) {
        while (cur != phead) {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }else{
        printf("please init a headnode!!\n");
    }
}
//删除pos
void ListErase(DuLNode*pos)
{
    assert(pos);

   DuLNode *posprev =pos->prior;
   DuLNode *posNext = pos->next;

   posprev->next = posNext;
   posNext->prior = posprev;
   free(pos);
   pos = NULL;
}

//pos之前插入
void ListInsert(DuLNode*pos,ElemType x)
{
    assert(pos);
    DuLNode * posPrev = pos->prior;
    DuLNode *newnode = BuyListNode(x);

    posPrev->next = newnode;
    newnode->prior = posPrev;
    newnode->next = pos;
    pos->prior = newnode;

}
DuLNode *BuyListNode(ElemType x){
    DuLNode *newnode = (DuLNode*) malloc(DEN);
    newnode->data = x;
    newnode->next = NULL;
    newnode->prior = NULL;
    return newnode;
}
void ListPushBack(DuLNode* phead,ElemType x)
{
    assert(phead);
    DuLNode *tail = phead->prior;
    DuLNode *newnode = (DuLNode*)malloc(DEN);
    newnode->data = x;

    //phead
    tail->next=newnode;
    newnode->prior = tail;
    newnode->next = phead;
    phead->prior = newnode;
}
DuLNode * ListFind(DuLNode * phead){
    assert(phead->next!=NULL);
    int x=0;
    scanf("%d",&x);
    DuLNode *cur= phead->next;
    while(cur!=phead){
        if(cur->data==x){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void test(DuLNode**L){
    DuLNode *F;
    InitList_DuL(&F);
    ListPushBack(F,6);
    ListPushBack(F,4);
    ListPushBack(F,3);
    ListPushBack(F,9);
    ListPushBack(F,8);
    *L=F;
}