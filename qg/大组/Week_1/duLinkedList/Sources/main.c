#include "duLinkedList.h"
//主要实现交互界面,暂时用控制台文本化界面
int main() {
    char a=0;DuLNode *L;
    void (*b)(ElemType) = 0;
    void (*e)(ElemType) = 0;
    DuLNode *q,*p;

    //选择功能
    do
    {
        menu();
        //误输字符不会使程序奔溃
        scanf("%d", &a);

        switch ((int)a) {
            case 1:
                if (!InitList_DuL(&L))printf("内存不足,无法分配空间");
//                menu();
                break;
            case 2:
                system("cls");
                DestroyList_DuL(L);
//                menu();
                break;
            case 3:
                system("cls");
                q = (DuLNode *) malloc(DEN);
                if (q == NULL) {
                    printf("内存不足,请稍后再试!!");
                    return OVERFLOW;
                }
                printf("please input the number you want to insert\n");
                scanf("%d",&a);
                q->data=a;
                printf("please input the node inserted before!!\n");
                p= ListFind(L);
                InsertBeforeList_DuL(p, q);
//                menu();
                break;
            case 4:
                q = (DuLNode *) malloc(DEN);
                if (q == NULL) {
                    printf("内存不足,请稍后再试!!");
                    return OVERFLOW;
                }
                printf("please input the number you want to insert\n");
                scanf("%d",&a);
                q->data=a;
                printf("please input the node inserted before!!\n");
                p= ListFind(L);
                InsertAfterList_DuL(p, q);
                break;
            case 5:
                printf("please input the number before the node you want to delete\n");
                p = ListFind(L);
                if(DeleteList_DuL(p, &e))
                    printf("Successfully delete node!\n");
                else printf("Fail to delete!!\n");
                break;
            case 6:
//                TraverseList_DuL(L, b);
//                menu();
                ListPrint(L);
                break;
            case 7:
                test(&L);
//                menu();
                break;
            default:
                printf("error input ,please choose the number in front of the menu!!!\n");
                getchar();
                scanf("%d",&a);
                break;
        }
    }
    while (a!=10);
    return 0;
}
