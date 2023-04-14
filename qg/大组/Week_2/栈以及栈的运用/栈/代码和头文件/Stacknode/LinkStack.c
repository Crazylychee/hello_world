#include "LinkStack.h"
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s) {
    s->top = (LinkStackPtr) malloc(sizeof(StackNode));
    if (s->top == NULL) return ERROR;
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s) {
    if (s->count == 0)
        return SUCCESS;
    else
        return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s, ElemType *e) {
    if (s->top == NULL)
        return ERROR;
    else
        *e = s->top->data;
    return SUCCESS;
}

//���ջ
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

//����ջ
Status destroyLStack(LinkStack *s) {
}

//���ջ����
Status LStackLength(LinkStack *s, int *length) {
    return s->count;
}

//��ջ
Status pushLStack(LinkStack *s, ElemType data) {
    //�����½��temp
    LinkStackPtr temp = (LinkStackPtr) malloc(sizeof(StackNode));
    //��ֵ
    temp->data = data;
    //�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��
    temp->next = s->top;
    //���½��temp ��ֵ��ջ��ָ��
    s->top = temp;
    s->count++;
    return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s, ElemType *data) {
    LinkStackPtr p;
    if (isEmptyLStack(s)) {
        return ERROR;
    }

    //��ջ��Ԫ�ظ�ֵ��*e
    *data = s->top->data;
    //��ջ����㸳ֵ��p
    p = s->top;
    //ʹ��ջ��ָ������һλ, ָ���һ���.
    s->top = s->top->next;
    //�ͷ�p
    free(p);
    //����--
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
