#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};
void createhead(struct node** head,int data){
    (*head)=(struct node*)malloc(sizeof(struct node));
    (*head)->data=data;
    (*head)->next=NULL;
    (*head)->prev=NULL;
}
void insertathead(struct node** head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    (temp)->data=data;
    (temp)->next=NULL;
    (temp)->prev=NULL;
    temp->next=(*head);
    (*head)->prev=temp;
    (*head)=temp;
}
void insertattail(struct node** tail,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    (temp)->data=data;
    (temp)->next=NULL;
    (temp)->prev=NULL;
    (*tail)->next=temp;
    temp->prev=(*tail);
    (*tail)=temp;
}
void insertatpos(struct node** head,int data,int pos){
    struct node* prevv=(*head);
    int c=1;
    while(c<pos-1){
        prevv=prevv->next;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    temp->next=prevv->next;
    prevv->next->prev=temp;
    temp->prev=prevv;
    prevv->next=temp;
}
void deleteathead(struct node** head){
    struct node* temp=(*head);
    (*head)=(*head)->next;
    free(temp);
}
void deleteattail(struct node** tail){
    struct node* temp=(*tail);
    (*tail)=(*tail)->prev;
    (*tail)->next=NULL;
    free(temp);
}
void deleteatpos(struct node** head,int pos){
    int c=1;
    struct node* temp=(*head);
    struct node* tempp=(*head)->next;
    while(c<pos-1){
        temp=temp->next;
        tempp=tempp->next;
    }
    temp->next=tempp->next;
    tempp->next->prev=temp;
    free(tempp);
}
void printlist(struct node** head){
    struct node* temp=(*head);
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct node* head=NULL;
    createhead(&head,87);
    struct node* tail=head;
    // insertathead(&head,90);
    // insertattail(&tail,76);
    // insertatpos(&head,43,2);
    // printlist(&head);
    // printf("\n");
    // deleteatpos(&head,2);
    // printlist(&head);
    // printf("\n");
    // deleteathead(&head);
    // printlist(&head);
    // printf("\n");
    // deleteattail(&tail);
    // printlist(&head);
    for(int i=0;i<5;i++){
        int n;
        scanf("%d",&n);
        insertathead(&head,n);
    }
    return 0; 
}