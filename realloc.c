#include <stdio.h>
#include <stdlib.h>
int main(){
    float a[]={63.2,-43.5 ,70.1,3.6};
    int n=sizeof(a)/sizeof(a[0]);
    float *p=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++){
        printf("%f ",*(a+i));
    }
    printf("\n");
    p=(float*)realloc(p,6*sizeof(float));
    p=(float*)a;
    for(int i=n;i<6;i++){
        scanf("%f",(a+i));
    }
    for(int i=0;i<6;i++){
        printf("%f ",*(a+i));
    }
   

}
