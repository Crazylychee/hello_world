
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include "malloc.h"
#include "time.h"
#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include "string.h"
#define MAX 100
typedef int STDateType;
typedef struct Stack
{
    STDateType* a;
    STDateType top;
    int capacity;
}ST;

//��ʼ��ջ
void StackInit(ST* ps);

//����ջ
void StackDestory(ST* ps);

//��ջ
void StackPush(ST* ps, STDateType x);

//��ջ
void StackPop(ST* ps);

//ȡ��ջ��Ԫ��
STDateType StackTop(ST* ps);

//��ȡ��ǰջ��С
int StackSize(ST* ps);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ps);
void swap(int *a, int *b);
void printArr(int *b,int N);
int GetMinIndex(int* arr, int left, int right);
int get_index(int num, int dec, int order);
int maxbit(int data[], int n);
int * FileWork(int *arr,int max);
bool isSorted(int arr[],int n);
int * FileRead(int *arr) ;
void Test(int*arr,int size,int N);
void menu();
        /**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
int * CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */


#endif // QUEUE_H_INCLUDED
