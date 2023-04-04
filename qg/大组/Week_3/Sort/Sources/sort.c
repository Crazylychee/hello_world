//
// Created by yc on 2023/4/2.
//
#include "sort.h"
#define MAXSIZE 5
//n 为数组容量
//    int a[N]={2,5,4,3,5};
void insertSort(int *a, int n) {
    int i, j, tmp;
    for (i = 1; i <= n; i++) {
        int t = i - 1;
        tmp = a[i - 1];
        for (j = i; j < n; j++) {
            if (tmp > a[j]) {
                tmp = a[j];
                t = j;
            }
        }
        swap(&a[t], &a[i - 1]);
    }
}
void MergeArray(int *a, int begin, int mid, int end, int *temp) {
    int k = 0;
    int i = begin;
    int j = mid + 1;
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    if (i == mid + 1) {
        while (j <= end)
            temp[k++] = a[j++];
    }
    if (j == end + 1) {
        while (i <= mid)
            temp[k++] = a[i++];
    }
    for (j = 0, i = begin; j < k; i++, j++) {
        a[i] = temp[j];
    }
}
void MergeSort(int *a, int begin, int end, int *temp) {
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);
    MergeArray(a, begin, mid, end, temp);
}

void QuickSort_Recursion(int *a, int begin, int end) {
    int i, j;
    if (begin < end) {
        i = begin + 1;
        j = end;
        while (i < j) {
            if (a[i] > a[begin]) {
                swap(&a[i], &a[j]);
                j--;
            } else {
                i++;
            }
        }
        if (a[i] >= a[begin]) {
            i--;
        }
        swap(&a[begin], &a[i]);
        QuickSort_Recursion(a, begin, i);
        QuickSort_Recursion(a, j, end);
    }
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void QuickSort(int *a, int size) {
    ST st;
    StackInit(&st);

    //把左右区间压栈，先压右边
    StackPush(&st, size - 1);
    //后压左边
    StackPush(&st, 0);

    //只要栈不为空，就继续分割排序
    while (!StackEmpty(&st)) {
        //从栈里面取出左右区间
        int left = StackTop(&st);
        StackPop(&st);
        int right = StackTop(&st);
        StackPop(&st);

        int index = GetMinIndex(a, left, right);
        //因为我们下面的逻辑都是把第一个数作为key，
        //为了避免改动代码，这里我们直接交换就可以
        swap(&a[left], &a[index]);

        //开始单趟排序
        int begin = left;
        int end = right;
        int pivot = begin;
        int key = a[begin];

        while (begin < end) {
            //end开始找小
            while (begin < end && a[end] >= key) {
                end--;
            }
            a[pivot] = a[end];
            pivot = end;
            //begin开始找大
            while (begin < end && a[begin] <= key) {
                begin++;
            }
            a[pivot] = a[begin];
            pivot = begin;
        }
        pivot = begin;
        a[pivot] = key;

        //区间分为[left,pivot-1]pivot[pivot+1,right]
        //利用循环继续分割区间
        //先入右子区间
        if (pivot + 1 < right) {
            //说明右子区间不止一个数
            //先入右边边界
            StackPush(&st, right);
            //再入左边边界
            StackPush(&st, pivot + 1);
        }

        //再入左子区间
        if (left < pivot - 1) {
            //说明左子区间不止一个数
            //先入右边边界
            StackPush(&st, pivot - 1);
            //再入左边边界
            StackPush(&st, left);
        }
    }
    StackDestory(&st);
}

int Partition(int *a, int begin, int end) {
    if (begin < end) {
        int x = 0;
        int x1 = a[begin], x2 = a[end], x3 = a[(begin + end) >> 1];
        if (x1 <= x2 && x2 <= x3) {
            x = x2;
            swap(&a[end], &a[begin]);
        } else if (x2 <= x1 && x1 <= x3) {
            x = x1;
            swap(&a[begin], &a[begin]);
        } else {
            x = x3;
            swap(&a[(begin + end) / 2], &a[begin]);
        }
        int i = begin, j = end;
        while (i < j) {
            while (i < j && a[j] >= x)// 从右向左找第一个小于x的数
                j--;
            if (i < j)
                a[i++] = a[j];
            while (i < j && a[i] <= x)// 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        Partition(a, begin, i - 1);// 递归调用
        Partition(a, i + 1, end);
    }
}
int *CountSort(int *a, int size, int max) {
    int *B = (int *) malloc(sizeof(int) * (max + 1));
    int *C = (int *) malloc(sizeof(int) * (max + 1));
    int i;
    for (i = 0; i <= max; i++) {
        C[i] = 0;
    }
    for (i = 0; i < size; i++) {
        C[a[i]]++;
    }
    for (i = 1; i <= max; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (i = size - 1; i >= 0; i--) {
        B[C[a[i]] - 1] = a[i];
        C[a[i]]--;
    }
    *a = *B;
    return B;
}

int get_index(int num, int dec, int order) {
    int i, j, n;
    int index;
    int div;
    for (i = dec; i > order; i--) {
        n = 1;
        for (j = 0; j < dec - 1; j++)
            n *= 10;
        div = num / n;
        num -= div * n;
        dec--;
    }
    n = 1;
    for (i = 0; i < order - 1; i++)
        n *= 10;
    index = num / n;
    return index;
}
void RadixCountSort(int *a, int size) {
    int i, b[size], m = a[0], exp = 1;
    int BASE;BASE=100000;
    for (i = 1; i < size; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }

    while (m / exp > 0) {
        int bucket[BASE];

        for (i = 0; i < size; i++) {
            bucket[(a[i] / exp) % BASE]++;
        }

        for (i = 1; i < BASE; i++) {
            bucket[i] += bucket[i - 1];
        }

        for (i = size - 1; i >= 0; i--) {
            b[--bucket[(a[i] / exp) % BASE]] = a[i];
        }

        for (i = 0; i < size; i++) {
            a[i] = b[i];
        }

        exp *= BASE;
    }
}
void ColorSort(int *a, int size) {
}

//void Test(){
//    int a[5]={3,6,2,6,9};
//}

//初始化
void StackInit(ST *ps) {
    ps->a = (STDateType *) malloc(sizeof(STDateType) * 4);
    ps->top = 0;
    ps->capacity = 4;
}

//销毁栈
void StackDestory(ST *ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

//入栈
void StackPush(ST *ps, STDateType x) {
    assert(ps);
    if (ps->top == ps->capacity) {
        STDateType *tmp = (STDateType *) realloc(ps->a, ps->capacity * 2 * sizeof(STDateType));
        if (tmp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        } else {
            ps->a = tmp;
            ps->capacity *= 2;
        }
    }
    ps->a[ps->top] = x;
    ps->top++;
}


//出栈
void StackPop(ST *ps) {
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

//获取栈顶元素
STDateType StackTop(ST *ps) {
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];
}

//获取栈元素个数
int StackSize(ST *ps) {
    assert(ps);
    return ps->top;
}

//判断栈是否为空
bool StackEmpty(ST *ps) {
    assert(ps);
    return ps->top == 0;
}

int GetMinIndex(int *arr, int left, int right) {
    int mid = (left + right) >> 1;
    if (arr[left] < arr[mid]) {
        if (arr[mid] < arr[right]) {
            return mid;
        }
        if (arr[left] < arr[right] && arr[right] < arr[mid]) {
            return right;
        }
        return left;
    } else//arr[left] >= arr[mid]
    {
        if (arr[left] < arr[right]) {
            return left;
        }
        if (arr[mid] < arr[right] && arr[right] < arr[left]) {
            return right;
        }
        return mid;
    }
}
int *FileWork(int *arr, int max) {
    FILE *fp;//文件指针
    long i;

    /*文件的打开*/
    fp = fopen("data.txt", "w");//fopen打开文件，这个文件可以是当前不存在的。“w”以写入的形式打开，“r”以读的形式打开
    if (fp == NULL)             //判断如果文件指针为空
    {
        printf("File cannot open! ");
        exit(0);//在以0的形式退出，必须在文件开头有#include <stdlib.h>,stdlib 头文件即standard library标准库头文件
    }

    srand((unsigned) time(NULL));
    for (i = 0; i < max; ++i) {
        arr[i] = rand() % MAX;
        //        printf("%d", arr[i]);
    }

    //写入东西
    for (i = 0; i < max; i++) {
        fprintf(fp, "%d\t", arr[i]);//写入指针fp，写入的东西就是刚才的用户输入的d,注意这里的fp和d没有引号
    }

    //关闭文件
    fclose(fp);
    return arr;
}
bool isSorted(int arr[], int n) {
    bool flag = true;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i + 1] < arr[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}
int *FileRead(int *arr) {
    FILE *fp;//文件指针
    long i = 0;

    /*文件的打开*/
    fp = fopen("data.txt", "r");//fopen打开文件，这个文件可以是当前不存在的。“w”以写入的形式打开，“r”以读的形式打开
    if (fp == NULL)             //判断如果文件指针为空
    {
        printf("File cannot open! ");
        exit(0);//在以0的形式退出，必须在文件开头有#include <stdlib.h>,stdlib 头文件即standard library标准库头文件
    }

    while (fscanf(fp, "%d ", &arr[i]) != -1) {
        i++;
    }

    //关闭文件
    fclose(fp);
}
void Test(int *arr, int size, int N) {
    int begin = 0, end = N;
    int *temp = (int *) malloc(size);
    memcpy(temp, arr, size);
    int input = 0;
    int bit;
    menu();
    scanf("%d", &input);
    int *b;
    clock_t start_time = clock();
    {
        switch (input) {
            case 1:
                insertSort(arr, N);
                break;
            case 2:
                MergeArray(arr, begin, (begin + end) / 2, end, temp);
                break;
            case 3:
                MergeSort(&arr, begin, end, &b);
                break;
            case 4:
                QuickSort_Recursion(arr, begin, end);

                break;
            case 5:
                QuickSort(arr, N);

                break;
            case 6:
                Partition(arr, begin, end);
                break;
            case 7:
                arr = CountSort(arr, end, end);
                break;
            case 8:
                RadixCountSort(&arr[0], N);
                break;
            default:
                break;
        }
    }
    clock_t end_time = clock();
    printf("Running time is: %lfms\n", (double) (end_time - start_time) / CLOCKS_PER_SEC * 1000);
        printArr(arr,N);
    printf("%s", isSorted(arr, N) == true ? "true" : "false");
    printf("\n");
}
void menu() {
    printf("*************************************\n");
    printf("****** Please input the number ******\n");
    printf("****** 1.Insert                ******\n");
    printf("****** 2.MergeArray            ******\n");
    printf("****** 3.MergeSort             ******\n");
    printf("****** 4.QuickSort_Recursion   ******\n");
    printf("****** 5.QuickSort             ******\n");
    printf("****** 6.Partition             ******\n");
    printf("****** 7.CountSort             ******\n");
    printf("****** 8.RadixCountSort        ******\n");
    printf("*************************************\n");
}