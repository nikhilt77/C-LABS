#include<stdio.h>

struct poly{
    int coeff;
    int exp;
};

struct poly p1[20],p2[20];

int main(){
    int n1,n2,i=0,j=0;
    printf("Enter number of terms of first polynomial:");
    scanf("%d",&n1);
    printf("Enter number of terms of second polynomial:");
    scanf("%d",&n2);
    printf("Enter terms of first:");
    for(i=0;i<n1;i++){
        printf("Enter coefficient and exponent of term %d:",i+1);
        scanf("%d",&p1[i].coeff);
        scanf("%d",&p1[i].exp);
    }
    printf("Enter terms of second:");
    for(i=0;i<n2;i++){
        printf("Enter coefficient and exponent of term %d:",i+1);
        scanf("%d",&p2[i].coeff);
        scanf("%d",&p2[i].exp);
    }
    i=0; j=0; // Reset i and j
    while(i<n1 && j<n2){
        if(p1[i].exp==p2[j].exp){
            printf("+%dx^%d",p1[i].coeff+p2[j].coeff,p1[i].exp);
            i++;
            j++;
        }
        else if(p1[i].exp>p2[j].exp){
            printf("+%dx^%d",p1[i].coeff,p1[i].exp);
            i++;
        }
        else{
            printf("+%dx^%d",p2[j].coeff,p2[j].exp);
            j++;
        }
    }
    while(i<n1){
        printf("+%dx^%d",p1[i].coeff,p1[i].exp);
        i++;
    }
    while(j<n2){
        printf("+%dx^%d",p2[j].coeff,p2[j].exp);
        j++;
    }
    return 0;
}
