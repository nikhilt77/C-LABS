#include <stdio.h>
struct poly{
    int coeff;
    int exp;
};
struct poly p1[20],p2[20],p3[20];
void main(){
    int a,b,max;
    printf("Enter highest degree of polynomial 1: ");
    scanf("%d",&a);
    printf("Enter highest degree of polynomial 2: ");
    scanf("%d",&b);
   
    for(int i=a;i>=0;i--){
        printf("Enter coefficient of x^%d: ",i);
        scanf("%d",&p1[i].coeff);
        p1[i].exp=i;
    }
    for(int i=b;i>=0;i--){
        printf("Enter coefficients of x^%d: ",i);
        scanf("%d",&p2[i].coeff);
        p1[i].exp=i;
    }
     if(a>=b){
        max=a;
    }
    else{
        max=b;
    }

    for(int i=max;i>=0;i--){
        if(p1[i].exp==p2[i].exp){
            printf("+%dx^%d",p1[i].coeff+p2[i].coeff,i);
        }
        else if(max<=a){
            printf("+%dx^%d",p1[i].coeff,p1[i].exp); 
            }
        else if(max<=b){
            printf("+%dx^%d",p2[i].coeff,p2[i].exp);
        }
    }
}
