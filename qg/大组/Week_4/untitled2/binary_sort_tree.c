//
// Created by yc on 2023/4/10.
//
#include "binary_sort_tree.h"

Status BST_init(BinarySortTreePtr BST) {
    Node *p = BST->root;
    ElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
        p = NULL;
    else {
        p = (NodePtr) malloc(sizeof(Node));
        if (!p) {
            exit(-1);
        }
        p->value = ch;
        BSTinit(&p->left);
        BSTinit(&p->right);
    }
}
void BSTinit(NodePtr *T) {
    ElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
        *T = NULL;
    else {
        *T = (NodePtr) malloc(sizeof(Node));
        if (!*T)
            exit(-1);
        (*T)->value = ch;
        BSTinit((*T)->left);
        BSTinit((*T)->right);
    }
}
Status BST_insert(BinarySortTreePtr BST, ElemType e) {
    Node *Tr =BST->root;
    BST->root=Insert(e,Tr);

    return succeed;
}


Node *BST_delete(BinarySortTreePtr BST, ElemType X) {
    Node *BT = BST->root;
    if (!BT) {
        //���գ�ֱ�ӷ��ؿ�
        return NULL;
    }
    else if (X < BT->value) {
        //С�����������ݹ�ɾ��
        BT->left = BST_delete(BT->left, X);
    }
    else if (X > BT->value) {
        //�������������ݹ�ɾ��
        BT->right = BST_delete(BT->right, X);
    }
    else {
        //�ҵ�Ҫɾ���Ľ�㣬���������
        if (!BT->left && !BT->right) {
            //ɾ��Ҷ���,�ÿգ�����ָ�뽫���Զ��ͷ��ڴ�
            BT = NULL;
        }
        else if(BT->left && !BT->right) //ֻ���������������������ɾ�����
        {
            BT = BT->left;
        }
        else if(!BT->left && BT->right) //ֻ���������������������ɾ�����
        {
            BT = BT->right;
        }
        else //ͬʱ������������
        {
            //��������������СԪ��������ߵ������������Ԫ�������ұߵ�������
            //����ʹ��ɾ���������������Ԫ�������ɾ�����
            Node *p = BT->left;
            //�ҵ������������Ԫ��
            while (p->right)
            {
                p = p->right;
            }
            BT->value = p->value;
            //ɾ�������������Ԫ�ؽ��
            BT->left = BST_delete(BT->left, BT->value);
        }
    }
    return BT;
}

Status BST_search(BinarySortTreePtr BST, ElemType) {

}

Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
}

Status BST_preorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    NodePtr p = BST->root;
    if (p == NULL)
        return false;
    visit(p);
}

Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    Node *t = BST->root;
    struct BiTNode *st[MAXLENG];//����ָ��ջ
    int top = 0;                //�ÿ�ջ
    do {
        while (t)//��ָ��t��ʾ��Ϊ�ǿն�����
        {
            if (top == MAXLENG) exit(failed);//ջ����,�˳�
            st[top++] = t;                   //��ָ���ջ
            t = t->left;                     //t����������
        }                                    //ѭ��������ʾ��ջ��Ԫ�ص�ָ��Ϊ�����Ķ�����
                                             //����������������
        if (top)                             //Ϊ�ǿ�ջ
        {
            t = st[--top];     //������ָ��
            printf("%c", t->value);//���ʸ����
                    t = t->right;  //����������
        }
    } while (top || t);//�����δ���ʣ���������δ����
}

Status BST_inorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    NodePtr p = BST->root;
    if (p == NULL)
        return false;
    visit(p);
}

Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    Node *p = BST->root, *r = NULL;
    LinkStack *s = (LinkStack*) malloc(sizeof (LinkStack));

    while (p || !isEmptyLStack(s)) {
        if (p) {//�ߵ������
            pushLStack(s,p->value);
            p = p->left;
        }
        else {
            p->value = getTopLStack(s);
            if (p->right && p->right != r)//���������ڣ�δ������
                p = p->right;
            else {
                popLStack(s,&p->value);
                visit(p);
                r = p;//��¼������ʹ��Ľڵ�
                p = NULL;//�ڵ�����������pָ��
            }
        }//else
    }//while
}

Status BST_postorderR(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
    NodePtr p = BST->root;
    if (p == NULL)
        return false;
    visit(p);
}

Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) {


}
void PreOrderTraverse(NodePtr T) {
    if (T == NULL)
        return;
    printf("%c", T->value);
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}
void InOrderTraverse(NodePtr T) {
    if (T == NULL)
        return;
    InOrderTraverse(T->left);
    printf("%c", T->value);
    InOrderTraverse(T->right);
}
void PostOrderTraverse(NodePtr T) {
    if (T == NULL)
        return;
    PostOrderTraverse(T->left);
    PostOrderTraverse(T->right);
    printf("%d", T->value);
}
Status initLStack(LinkStack *s) {
    s->top = (LinkStackPtr) malloc(sizeof(StackNode));
    if (s->top == NULL) return failed;
    s->top = NULL;
    s->count = 0;
    return succeed;
}
Node *Insert(int X,Node *BST)
{
    if(!BST)//��ԭ��Ϊ�գ����ɲ�����һ��ֻ��һ�����Ķ�����һ��
    {
        BST=malloc(sizeof(struct Node));//�����⣡����
        BST->value = X;
        BST->left=NULL;
        BST->right=NULL;
    }
    else if(X < BST->value)
    {
        BST->left = Insert(X,BST->left);//����Ϊreturn Insert(X,BST->left);�������ڲ���

    }
    else if(X > BST->value)
    {
        BST->right = Insert(X,BST->right);
    }
    return BST;
}
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
int getTopLStack(LinkStack *s) {
    int e=0;
    if (s->top == NULL)
        return ERROR;
    else
        e = s->top->data;
    return e;
}