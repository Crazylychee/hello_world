//
// Created by yc on 2023/3/31.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include "stdio.h"
#include "stdlib.h"
typedef struct node//ѹջ�ͳ�ջ����ջ������(�����ջ��ָǰһ��)
{
    char value;//����
    struct node* next;//ָ��
}pnode;
typedef struct seqstack
{
    int size;//��¼ջ�Ĵ�С
    pnode* top;//ָ��ջ��Ԫ��
}phead;
//�·�Ϊ�����׺���ʽ��Ҫ�ĺ���
typedef struct node1//�����ջ������ջ
{
    int val;//����
    struct node1* next;//ָ��
}pnode1;
typedef struct seqstack1
{
    int size;//��¼ջ�Ĵ�С
    pnode1* top;//ָ��ջ��Ԫ��
}phead1;
phead*  initstack();
int isempty(phead* istack);
void seqstack_push(phead* istack,char x);
pnode *seqstack_top(phead *istack);
pnode* seqstack_pop(phead* istack);
void char_put(char ch);
int priority(char ch);
int is_number(char ch);
int is_operator(char ch);
int is_left(char ch);
int is_right(char ch);
int transform(char str[]);
phead1*  initstack1();
int isempty1(phead1* istack);
int seqstack_top1(phead1* istack);
int seqstack_pop1(phead1* istack);
void seqstack_push1(phead1* istack,int x);
int express(int left,int right,char op);
int getsize(phead1* stack);
int calculate(char str[]);
int start();














#endif//CALCULATOR_CALCULATOR_H
