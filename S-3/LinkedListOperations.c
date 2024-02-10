#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node*next;
}*newnode,*head=NULL,*current,*prev=NULL,*next,*set;
int temp,count=0,sum=0,avg,max,min;
struct node*create(int data){
    newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    return newnode;
}
void insert(int data){
    newnode=create(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    //return head;
}
void deleteFront(){
    if(head==NULL){
        printf("Nothing to delete\n");
    }
    else{
        current=head;
        head=head->next;
        free(current);
    }
}
void deleteEnd(){
    current=head;
    if(head==NULL){
        printf("Nothing to delete\n");
    }
    else{
        while(current->next->next!=NULL){
            current=current->next;
        }
        set=current->next;
        current->next=NULL;
        free(set);
    }
}
void sort(){
    current=head;
    if(head==NULL){
        printf("Nothing to sort\n");
    }
    else{
       for(struct node*i=head;i!=NULL;i=i->next){
           for(struct node*j=i->next;j!=NULL;j=j->next){
           if(i->data>j->data){
               temp=i->data;
               i->data=j->data;
               j->data=temp;
           }
        }
       }    
    }
}
void display(){
    current=head;
    while(current!=NULL){
        printf("%d",current->data);
        current=current->next;
    }
    printf("\n");
}
void average(){
    current=head;
    if(head==NULL){
        printf("Nothing to find\n");
    }
    else{
        while(current!=NULL){
            sum=sum+current->data;
            count++;
            current=current->next;
        }
        avg=sum/count;
    }
    printf("Average:%d",avg);
}
void maximum(){
    current=head;
    max=current->data;
    while(current!=NULL){
        if(current->data>max){
            max=current->data;
        }
        current=current->next;
    }
    printf("Maximum:%d\n",max);
}
void minimum(){
    current=head;
    min=current->data;
    while(current!=NULL){
        if(current->data<min){
            min=current->data;
        }
        current=current->next;
    }
    printf("Minimum:%d\n",min);
}
struct node*reverse(){
    current=head;
    next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void main(){
    int ch,key;
    while(true){
        printf("1.Insert\n2.Sort\n3.Display\n4.Average\n5.Reverse\n6.Maximum\n7.Minimum\n8.Delete from Front\n9.Delete from End\n10.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                    scanf("%d",&key);
                    insert(key);
                    break;
            case 2:sort();
                    break;
            case 3:display();
                    break;
            case 4:average();
                    break;
            case 5:head=reverse();
                    break;
            case 6: maximum();
                    break;
            case 7:minimum();
                    break;
            case 8:deleteFront();
                    break;
            case 9:deleteEnd();
                    break;
            case 10:exit(0);
                    break;        
            default:printf("Invalid\n");        
            
        }
    }
}

