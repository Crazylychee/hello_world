
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

//初始化栈
void StackInit(ST* ps);

//销毁栈
void StackDestory(ST* ps);

//入栈
void StackPush(ST* ps, STDateType x);

//出栈
void StackPop(ST* ps);

//取出栈顶元素
STDateType StackTop(ST* ps);

//获取当前栈大小
int StackSize(ST* ps);

//判断栈是否为空
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
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
int * CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */


#endif // QUEUE_H_INCLUDED
