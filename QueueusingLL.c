#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue* next;
};
void createQ(struct queue** front,int data){
    (*front)=(struct queue*)malloc(sizeof(struct queue));
    (*front)->data=data;
    (*front)->next=NULL;
}
void enqueue(struct queue** rear,int data){
    struct queue* temp=(struct queue*)malloc(sizeof(struct queue));
    temp->data=data;
    temp->next=NULL;
    (*rear)->next=temp;
    (*rear)=temp;
}
void dequeue(struct queue** front){
    struct queue* temp=(*front);
    (*front)=(*front)->next;
    free(temp);
}
void print(struct queue** front){
    struct queue* temp=(*front);
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct queue* front=NULL;
    printf("Enter the value to start the queue:");
    int n;
    scanf("%d",&n);
    createQ(&front,n);
    struct queue* rear=front;
    printf("How many elements you want to insert in the queue?");
    int t;
    scanf("%d",&t);
    int x;
    for(int i=0;i<t;i++){
        scanf("%d",&x);
        enqueue(&rear,x);
    }
    print(&front);
    printf("\n");
    printf("If you want to dequeue then enter 1 else 0 :");
    int d;
    scanf("%d",&d);
    if(d==1){
        dequeue(&front);
        print(&front);
        printf("\n");
        printf("Thanks for using dequeue operation");
    }
    else{
        printf("Thank you!!");
    }
    return 0;
}