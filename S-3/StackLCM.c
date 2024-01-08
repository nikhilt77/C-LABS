#include<stdio.h>
#include<stdlib.h>
#define max 2
int stack[max];
int top=-1;

void push(int data){
    if(top==max-1){
        printf("Stack overflow\n");
    }
    else{
        top++;
        stack[top]=data;
    }
}

int pop(){
    if(top==-1){
        printf("Nothing to pop\n");
        return -1;
    }
    else{
        int data = stack[top];
        top--;
        return data;
    }
}
int HCF(int a,int b){ 
    int temp; 
    if(a<b){ 
        while(a!=0){ 
            temp=a; 
            a=b%a;
            b=temp; 
            
        } return b; 
        
    } else{ 
        while(b!=0){
            temp=b; 
            b=a%b; 
            a=temp; 
            
        } return a; 
        
    }
}

void main(){
    int data1,data2,hcf;
    printf("Enter Datas to find LCM of:");
    scanf("%d %d",&data1,&data2);
    hcf=HCF(data1,data2);
    push(hcf);
    printf("LCM of numbers:%d",(data1*data2)/pop());
    
}
