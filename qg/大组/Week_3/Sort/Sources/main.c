
#include "sort.h"
int main() {
    int begin=0,end =5,max;

    int input = 0;int *a;
    printf("请输入测试用数据量：(输入1为10000，2为50000，3为200000,\n或是输入任意数以生成任意数据量(输入数据量不可超过上次生成的数据量))\n");
    scanf("%d", &input);//用户输入测试数据量
    switch (input) {
        case 1:
            max=20000;
            break;
        case 2:
            max=50000;
            break;
        case 3:
            max =200000;
            break;
        default:
            max =input;
    }
    int N=max;
    int arr[N];
    int size =sizeof (arr);

//    int a[N]={2,5,4,3,5};
    if(input>3){
        a = FileRead(arr);
    }else{
        a =FileWork(arr,max);
    }

    Test(arr,size,N);
    return 0;
}
void printArr(int *b,int N){
    for(int i=0;i<=N-1;i++) {
        printf("%d\t", b[i]);
    }
}