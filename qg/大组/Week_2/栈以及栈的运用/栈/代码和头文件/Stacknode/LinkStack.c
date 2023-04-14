#include "LinkStack.h"
//链栈

//初始化栈
Status initLStack(LinkStack *s) {
    s->top = (LinkStackPtr) malloc(sizeof(StackNode));
    if (s->top == NULL) return ERROR;
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s) {
    if (s->count == 0)
        return SUCCESS;
    else
        return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s, ElemType *e) {
    if (s->top == NULL)
        return ERROR;
    else
        *e = s->top->data;
    return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s) {
    LinkStackPtr p, q;
    p = s->top;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    s->count = 0;
    return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s) {
}

//检测栈长度
Status LStackLength(LinkStack *s, int *length) {
    return s->count;
}

//入栈
Status pushLStack(LinkStack *s, ElemType data) {
    //创建新结点temp
    LinkStackPtr temp = (LinkStackPtr) malloc(sizeof(StackNode));
    //赋值
    temp->data = data;
    //把当前的栈顶元素赋值给新结点的直接后继
    temp->next = s->top;
    //将新结点temp 赋值给栈顶指针
    s->top = temp;
    s->count++;
    return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s, ElemType *data) {
    LinkStackPtr p;
    if (isEmptyLStack(s)) {
        return ERROR;
    }

    //将栈顶元素赋值给*e
    *data = s->top->data;
    //将栈顶结点赋值给p
    p = s->top;
    //使得栈顶指针下移一位, 指向后一结点.
    s->top = s->top->next;
    //释放p
    free(p);
    //个数--
    s->count--;

    return SUCCESS;
}

//
void TestStack(LinkStack **s) {
    initLStack(*s);

    pushLStack(*s, 6);
    pushLStack(*s, 5);
    pushLStack(*s, 3);
    pushLStack(*s, 9);
    pushLStack(*s, 5);
    pushLStack(*s, 7);
}

Status StackTraverse(LinkStack *s) {
    LinkStackPtr p;
    p = s->top;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return SUCCESS;
}
void menu() {
    printf("*************************************\n");
    printf("****** Please input the number ******\n");
    printf("****** 1.initLStack            ******\n");//
    printf("****** 2.isEmptyLStack         ******\n");//
    printf("****** 3.getTopLStack          ******\n");//
    printf("****** 4.clearLStack           ******\n");//
    printf("****** 5.destroyLStack         ******\n");//
    printf("****** 6.LStackLength          ******\n");//
    printf("****** 7.pushLStack            ******\n");//
    printf("****** 8.popLStack             ******\n");//
    printf("****** 9.StackTraverse         ******\n");//
    printf("****** 10.TestStack            ******\n");//
    printf("*************************************\n");//
    printf("****** input the '0'shut up    ******\n");//
}

//#endif
