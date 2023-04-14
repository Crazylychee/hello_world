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
        //树空，直接返回空
        return NULL;
    }
    else if (X < BT->value) {
        //小于则左子树递归删除
        BT->left = BST_delete(BT->left, X);
    }
    else if (X > BT->value) {
        //大于则右子树递归删除
        BT->right = BST_delete(BT->right, X);
    }
    else {
        //找到要删除的结点，按情况处理
        if (!BT->left && !BT->right) {
            //删除叶结点,置空，智能指针将会自动释放内存
            BT = NULL;
        }
        else if(BT->left && !BT->right) //只有左子树，用左子树替代删除结点
        {
            BT = BT->left;
        }
        else if(!BT->left && BT->right) //只有右子树。用右子树替代删除结点
        {
            BT = BT->right;
        }
        else //同时存在左右子树
        {
            //二叉搜索树的最小元素在最左边的左子树，最大元素在最右边的右子树
            //这里使用删除结点的左子树最大元素来替代删除结点
            Node *p = BT->left;
            //找到左子树中最大元素
            while (p->right)
            {
                p = p->right;
            }
            BT->value = p->value;
            //删除左子树中最大元素结点
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
    struct BiTNode *st[MAXLENG];//定义指针栈
    int top = 0;                //置空栈
    do {
        while (t)//根指针t表示的为非空二叉树
        {
            if (top == MAXLENG) exit(failed);//栈已满,退出
            st[top++] = t;                   //根指针进栈
            t = t->left;                     //t移向左子树
        }                                    //循环结束表示以栈顶元素的指向为根结点的二叉树
                                             //的左子树遍历结束
        if (top)                             //为非空栈
        {
            t = st[--top];     //弹出根指针
            printf("%c", t->value);//访问根结点
                    t = t->right;  //遍历右子树
        }
    } while (top || t);//父结点未访问，或右子树未遍历
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
        if (p) {//走到最左边
            pushLStack(s,p->value);
            p = p->left;
        }
        else {
            p->value = getTopLStack(s);
            if (p->right && p->right != r)//右子树存在，未被访问
                p = p->right;
            else {
                popLStack(s,&p->value);
                visit(p);
                r = p;//记录最近访问过的节点
                p = NULL;//节点访问完后，重置p指针
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
    if(!BST)//若原树为空，生成并返回一个只有一个结点的二叉树一个
    {
        BST=malloc(sizeof(struct Node));//有问题！！！
        BST->value = X;
        BST->left=NULL;
        BST->right=NULL;
    }
    else if(X < BST->value)
    {
        BST->left = Insert(X,BST->left);//若改为return Insert(X,BST->left);则类似于查找

    }
    else if(X > BST->value)
    {
        BST->right = Insert(X,BST->right);
    }
    return BST;
}
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
int getTopLStack(LinkStack *s) {
    int e=0;
    if (s->top == NULL)
        return ERROR;
    else
        e = s->top->data;
    return e;
}