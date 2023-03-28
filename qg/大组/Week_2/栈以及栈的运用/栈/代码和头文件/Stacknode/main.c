#include "LinkStack.h"
#include <stdio.h>
int main() {
    int a = 0;
    LinkStack *s=(LinkStackPtr)malloc(sizeof(StackNode));
    ElemType e, data, length;
    e=0,data=0,length=0;
    //选择功能
    do {
        menu();
        //误输字符不会使程序奔溃
        scanf("%d", &a);

        switch (a) {
            case 1:

                if (initLStack(s)) {
                    printf("Successfully!!\n");
                }else{
                    printf("Fail!!\n");
                }
                break;
            case 2:
                if (isEmptyLStack(s)) {
                    printf("is empty!!\n");
                }else{
                    printf("not empty!!\n");
                }
                break;
            case 3:
                getTopLStack(s, &e);
                printf("the top is %d\n",e);
                break;
            case 4:
                if (clearLStack(s)) {
                    printf("Successfully clear\n");
                }else{
                    printf("Fail to clear\n");
                }
                break;
            case 5:
                if (destroyLStack(s)) {
                    printf("Successfully destroy\n");
                }else{
                    printf("Fail to destroy\n");
                }
                break;
            case 6:
                LStackLength(s, &length);
                printf("The length is %d\n",length);
                break;
            case 7:
                pushLStack(s, data);
                break;
            case 8:
                popLStack(s,&e);
                break;
            case 9:
                StackTraverse(s);
                break;
            case 10:
                TestStack(&s);
                break;
            default:
                printf("error input ,please choose the number in front of the menu!!!\n");
                scanf("%d",&a);
                break;
        }
    } while (a != 0);
    return 0;
}
