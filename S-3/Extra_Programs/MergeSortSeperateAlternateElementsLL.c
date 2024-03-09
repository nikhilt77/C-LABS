#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*head1=NULL,*head2=NULL,*current;
void add(struct node**head,int data){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    if(*head==NULL){
        *head=current=newnode;
    }
    else{
        current->next=newnode;
        current=newnode;
    }
}
void merge(int A[],int lb,int mid,int ub){
    int n1=mid-lb+1;
    int n2=ub-mid;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;++i)
    L[i]=A[lb+i];
    for(int j=0;j<n2;++j)
    R[j]=A[mid+1+j];
    int i=0,j=0,k=lb;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(A,lb,mid);
        mergeSort(A,mid+1,ub);
        merge(A,lb,mid,ub);
    }
}
void display(struct node**h){
    while((*h)->next!=NULL){
        printf("%d->",(*h)->data);
        *h=(*h)->next;
    }
    printf("%d\n",(*h)->data);
}
void main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int l=0;
    int u=n-1;
    mergeSort(A,l,u);
    printf("Sorted Array:");
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
    }
    printf("\n");
    for(int i=0;i<n;i+=2){
        add(&head1,A[i]);
    }
    for(int i=1;i<n;i+=2){
        add(&head2,A[i]);
    }
    display(&head1);
    display(&head2);
}
