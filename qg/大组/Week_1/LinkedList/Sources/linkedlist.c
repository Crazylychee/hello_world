//
// Created by yc on 2023/3/23.
//
#include "linkedList.h"
//主要实现交互界面,暂时用控制台文本化界面
int main() {
    int input=0;
    ElemType b;//
    int a=0;LinkedList L;
    void (*SListprint)(ElemType) = 0;//
    LinkedList q,p;//
    test(&L);//线性链表测试
//    test_1(&L);//环状链表测试
    SListPrint(L);
//输入函数部分
//    InitList(&L);
//    L = ListTailInsert(&L);
//    *L = ListHeadInsert(*L);
//选择功能
    do
    {
        menu();
        //误输字符不会使程序奔溃
        scanf("%d", &a);
        switch ((int)a) {
            case SListPrint1:
                SListPrint(L);
                break;
            case DestroyList1:
                DestroyList(&L);
//                menu();
                break;
            case InsertList1://将q节点插入到链表的p节点之后
                q = (LNode *) malloc(NEN);
                printf("please input the number you want to insert!!\n");
                scanf("%d",&input);
                q->data=input;q->next=NULL;
                printf("please enter the node insert before\n");
                p = Findnode(L);
                if(p==NULL){
                    printf("Can not to find it in the listnode,please change the other number!!\n");
                    break;
                }
                if(InsertList(p, q))
                    printf("insert successfully!!\n");
                else printf("error");
//                menu();
                    break;

            case DeleteList1:
                printf("please input the node before the number you want to delete!!\n");
                p = Findnode(L);
                if(p==NULL) {
                    printf("Can not to find it in the listnode,please change the other number!!\n");
                    break;
                }
                if(DeleteList(p, &input))
                    printf("delete successfully!!\n");
                else printf("error");
                break;
            case TraverseList1:
                TraverseList(L, SListprint);
                break;
            case SearchList1:
                printf("please input the number you want to search !!\n");
                if(SearchList(L, b))printf("yes ,it can be found\n");
//                menu();
                break;
            case ReverseList1:
                if (ReverseList(&L)) {
                    printf("reverse successfully\n");
                } else {
                    printf("fail to reverse ");
                };
                break;
            case IsLoopList1:
                if(IsLoopList(L)){
                    printf("It is a ring!!\n");
                }else
                {
                    printf("It isn't a ring!!\n");
                };
                break;
            case ReverseEvenList1:
                ReverseEvenList(&L);
                break;
            case FindMidNode1:
                p=FindMidNode(&L);
                printf("%d\n",p->data);
                break;
            case return1:
                a = 10;
            break;
            default:
                break;
                }
        }while (a!=10);
    return 0;
}