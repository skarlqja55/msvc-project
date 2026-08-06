#include<stdio.h>
void swap(int *ptr1, int *ptr2){
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}
int main(int argc, char const *argv[])
{


    int a=1,b=2;
    swap(&a,&b);

    printf("a:%d,b:%d",a,b);
    return 0;
}
