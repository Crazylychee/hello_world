//
// Created by yc on 2023/3/19.
//
#include "linkedList.h"
void menu()
{
    printf("*************************************\n");
    printf("****** Please input the number ******\n");
    printf("****** 0.SListPrint            ******\n");//
    printf("****** 1.DestroyList           ******\n");//
    printf("****** 2.InsertList            ******\n");//
    printf("****** 3.DeleteList            ******\n");//
    printf("****** 4.TraverseList          ******\n");//
    printf("****** 5.SearchList            ******\n");//
    printf("****** 6.ReverseList           ******\n");//
    printf("****** 7.IsLoopList            ******\n");//判断时候
    printf("****** 8.ReverseEvenList       ******\n");//
    printf("****** 9.FindMidNode          ******\n");
    printf("****** 10.Exit                ******\n");
    printf("*************************************\n");
}
//头插法建立单链表:只需两个指针
LinkedList ListHeadInsert(LinkedList p){
    LinkedList p1;
    int input=0,cnt=0;
    printf("(输入999999结束)请输入链表数字: \n");
    scanf("%d",&input);
    while(input!=999999){
        p1 = (LinkedList) malloc(NEN);
        //这里头插法的步骤相当于是打开瓶盖放水,每次都是动头节点.
        //第一次加入把NULL也看作是一个节点就好理解了
        //1.制作添加节点(加入了数据)
        p1->data = input;
        //2.链接新节点到头节点之后,并计数器加一
        p1->next = p->next;
        cnt++;
        //断开头节点,并重新把头节点接到新节点的头头
        p->next = p1;
        //最后再添加下一个数据
        scanf("%d",&input);
    }
    p->data=cnt;
    return p;
}
//尾插法建立单链表:需要三个指针
LinkedList ListTailInsert(LinkedList p){
    LinkedList p2;
    LinkedList p1= p2 = p;
    int input=0,cnt=0;
    printf("(输入999999结束)请输入链表数字: \n");
    scanf("%d",&input);

    while(input!=999999){
        p1 = (LinkedList) malloc(NEN);
        //这里尾插法的步骤相当于是打开瓶盖放水,每次都是动头节点.
        //第一次加入把NULL也看作是一个节点就好理解了
        //1.制作添加节点(加入了数据)
        p1->data = input;
        //2.链接新节点到头节点之后,并计数器加1
        p2->next = p1;
        cnt++;
        p2=p1;//p2指向新的表尾节点(永远保持p2指向最后一个节点)
        //最后再添加下一个数据
        scanf("%d",&input);
    }
    p2->next=NULL;
    p->data=cnt;
    return p;
}
Status InitList(LinkedList *L)
{
    (*L)= (LinkedList)malloc(NEN);
    if(L==NULL){
        printf("error!!\n");
        return OVERFLOW;
    }
    (*L)->next=NULL;(*L)->data = 0;
    return SUCCESS;
}

void DestroyList(LinkedList *L)
{
    assert(L!=NULL);
    LinkedList p = *L;
    while(p)
    {
        p = p->next;
        free(*L);
        *L = p;
    }
    printf("destroy successfully!!\n");
}

Status InsertList(LNode *p, LNode *q)
{
    //就是将新节点链接到p之后
    if(p==NULL||q == NULL)
        return ERROR;
    q->next = p->next;
    p->next = q;

    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e)
{
    //排除不可取的情况,链表为空,
    assert(p!=NULL);
    //排除为最后一个数的情况
    if(p->next==NULL)
    {
        *e=p->data;
        p=NULL;
    }
    LinkedList cur;
    cur = p->next;
    *e=cur->data;
    p->next=cur->next;
    free(cur);
    return SUCCESS;
}
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    SListPrint(L);
}
Status SearchList(LinkedList L, ElemType e)
{
    LinkedList p;
//    if(L->next == NULL) return ERROR;
    p = Findnode(L);
    if(p==NULL){
        printf("can not find the number!!\n");
        return ERROR;
    }
    return SUCCESS;
}
Status ReverseList(LinkedList *L){
    assert(*L!=NULL);
    //边界条件:如果是只有一个节点,或是空链表就不用操作
    LinkedList cur = (*L);
    LinkedList newhead = NULL;
    while(cur){
        LinkedList next = cur->next;
        //头插法
        cur->next = newhead;
        newhead = cur;

        //迭代往后走
        cur =next;
    }
    (*L)=newhead;
    return SUCCESS;
}
Status IsLoopList(LinkedList L)
{
    assert(L!=NULL);
    if(L->next == NULL)
        return ERROR;
    LinkedList fast,slow;
    fast = slow = L;
    fast = fast ->next->next;
    slow = slow ->next;
    while(1){
        if(!fast||!slow)
            return ERROR;
        if(fast == slow)
            return SUCCESS;
        else{
            fast = fast->next->next;
            slow = slow->next;
        }
    }
}
LNode* ReverseEvenList(LinkedList *L)
{
    assert(*L!=NULL);
    if((*L) == NULL||(*L)->next==NULL)
        return (*L);
    LinkedList q,p,o;
    p=(*L)->next;(*L)->next =NULL;
    q = o =NULL;
    while(p){
        q=p->next;
        p->next=o;
        o=p;
        p=q;
    }
    (*L)->next = o;
    return L;
}
LNode* FindMidNode(LinkedList *L)
{
    assert(*L!=NULL);
    LinkedList slow,fast;
    slow = fast= *L;
    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void test(LinkedList *L){
    LinkedList n1 = (LinkedList) malloc(NEN);
    LinkedList n2 = (LinkedList) malloc(NEN);
    LinkedList n3 = (LinkedList) malloc(NEN);
    LinkedList n4 = (LinkedList) malloc(NEN);
    LinkedList n5 = (LinkedList) malloc(NEN);
    LinkedList n6 = (LinkedList) malloc(NEN);

    n1->data = 3;
    n2->data = 5;
    n3->data = 2;
    n4 ->data = 8;
    n5->data = 6;
    n6->data = 7;
    n1->next=n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;

    *L = n1;
    return;
}
void SListPrint(LinkedList phead){
    LinkedList cur = phead;
    while(cur !=NULL){
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

LinkedList Findnode(const LinkedList L){
    assert(L!=NULL);
    int input=0;
    scanf("%d",&input);
    LinkedList newnode;
    newnode = L;
    while(newnode->data!=input&&newnode->next!=NULL){
        newnode = newnode->next;
    }
    if(newnode->data==input)
    return newnode;
    else return NULL;
}
LinkedList InitList_1(int n)
{
    LinkedList  L= (LinkedList)malloc(NEN);
    if(L==NULL){
        printf("error!!\n");
        exit(1);
    }
    L->next=NULL;L->data = n;
    return  L;
}
void test_1(LinkedList *L){
    LinkedList n1 = (LinkedList) malloc(NEN);
    LinkedList n2 = (LinkedList) malloc(NEN);
    LinkedList n3 = (LinkedList) malloc(NEN);
    LinkedList n4 = (LinkedList) malloc(NEN);
    LinkedList n5 = (LinkedList) malloc(NEN);
    LinkedList n6 = (LinkedList) malloc(NEN);

    n1->data = 3;
    n2->data = 5;
    n3->data = 2;
    n4 ->data = 8;
    n5->data = 6;
    n6->data = 7;
    n1->next=n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n1;

    *L = n1;
    return;
}