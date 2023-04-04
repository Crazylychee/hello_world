//
// Created by yc on 2023/4/2.
//
#include "sort.h"
#define MAXSIZE 5
//n Ϊ��������
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

    //����������ѹջ����ѹ�ұ�
    StackPush(&st, size - 1);
    //��ѹ���
    StackPush(&st, 0);

    //ֻҪջ��Ϊ�գ��ͼ����ָ�����
    while (!StackEmpty(&st)) {
        //��ջ����ȡ����������
        int left = StackTop(&st);
        StackPop(&st);
        int right = StackTop(&st);
        StackPop(&st);

        int index = GetMinIndex(a, left, right);
        //��Ϊ����������߼����ǰѵ�һ������Ϊkey��
        //Ϊ�˱���Ķ����룬��������ֱ�ӽ����Ϳ���
        swap(&a[left], &a[index]);

        //��ʼ��������
        int begin = left;
        int end = right;
        int pivot = begin;
        int key = a[begin];

        while (begin < end) {
            //end��ʼ��С
            while (begin < end && a[end] >= key) {
                end--;
            }
            a[pivot] = a[end];
            pivot = end;
            //begin��ʼ�Ҵ�
            while (begin < end && a[begin] <= key) {
                begin++;
            }
            a[pivot] = a[begin];
            pivot = begin;
        }
        pivot = begin;
        a[pivot] = key;

        //�����Ϊ[left,pivot-1]pivot[pivot+1,right]
        //����ѭ�������ָ�����
        //������������
        if (pivot + 1 < right) {
            //˵���������䲻ֹһ����
            //�����ұ߽߱�
            StackPush(&st, right);
            //������߽߱�
            StackPush(&st, pivot + 1);
        }

        //������������
        if (left < pivot - 1) {
            //˵���������䲻ֹһ����
            //�����ұ߽߱�
            StackPush(&st, pivot - 1);
            //������߽߱�
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
            while (i < j && a[j] >= x)// ���������ҵ�һ��С��x����
                j--;
            if (i < j)
                a[i++] = a[j];
            while (i < j && a[i] <= x)// ���������ҵ�һ�����ڵ���x����
                i++;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        Partition(a, begin, i - 1);// �ݹ����
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

//��ʼ��
void StackInit(ST *ps) {
    ps->a = (STDateType *) malloc(sizeof(STDateType) * 4);
    ps->top = 0;
    ps->capacity = 4;
}

//����ջ
void StackDestory(ST *ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

//��ջ
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


//��ջ
void StackPop(ST *ps) {
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

//��ȡջ��Ԫ��
STDateType StackTop(ST *ps) {
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];
}

//��ȡջԪ�ظ���
int StackSize(ST *ps) {
    assert(ps);
    return ps->top;
}

//�ж�ջ�Ƿ�Ϊ��
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
    FILE *fp;//�ļ�ָ��
    long i;

    /*�ļ��Ĵ�*/
    fp = fopen("data.txt", "w");//fopen���ļ�������ļ������ǵ�ǰ�����ڵġ���w����д�����ʽ�򿪣���r���Զ�����ʽ��
    if (fp == NULL)             //�ж�����ļ�ָ��Ϊ��
    {
        printf("File cannot open! ");
        exit(0);//����0����ʽ�˳����������ļ���ͷ��#include <stdlib.h>,stdlib ͷ�ļ���standard library��׼��ͷ�ļ�
    }

    srand((unsigned) time(NULL));
    for (i = 0; i < max; ++i) {
        arr[i] = rand() % MAX;
        //        printf("%d", arr[i]);
    }

    //д�붫��
    for (i = 0; i < max; i++) {
        fprintf(fp, "%d\t", arr[i]);//д��ָ��fp��д��Ķ������Ǹղŵ��û������d,ע�������fp��dû������
    }

    //�ر��ļ�
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
    FILE *fp;//�ļ�ָ��
    long i = 0;

    /*�ļ��Ĵ�*/
    fp = fopen("data.txt", "r");//fopen���ļ�������ļ������ǵ�ǰ�����ڵġ���w����д�����ʽ�򿪣���r���Զ�����ʽ��
    if (fp == NULL)             //�ж�����ļ�ָ��Ϊ��
    {
        printf("File cannot open! ");
        exit(0);//����0����ʽ�˳����������ļ���ͷ��#include <stdlib.h>,stdlib ͷ�ļ���standard library��׼��ͷ�ļ�
    }

    while (fscanf(fp, "%d ", &arr[i]) != -1) {
        i++;
    }

    //�ر��ļ�
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