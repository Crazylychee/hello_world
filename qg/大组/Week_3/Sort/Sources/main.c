
#include "sort.h"
int main() {
    int begin=0,end =5,max;

    int input = 0;int *a;
    printf("�������������������(����1Ϊ10000��2Ϊ50000��3Ϊ200000,\n������������������������������(�������������ɳ����ϴ����ɵ�������))\n");
    scanf("%d", &input);//�û��������������
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