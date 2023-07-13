#include<stdio.h>
#include<stdlib.h>
struct stack{
   int size;
   int top;
   int *arr;
};
void push(struct stack* ptr, int val){
    
    
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d",ptr->arr[ptr->top]);
    
}
int peek(struct stack *sp,int i){
    int x=sp->top-i+1;
    if(x<0){
        printf("Not a valid position");
        return -1;
    }
    else{
        return sp->arr[x];
    }
}
void pop(struct stack* ptr){
    
    
        int val = ptr->arr[ptr->top];
        ptr->top--;
       
    
}
int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
\
int main(){
    struct stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    push(s,67);
    push(s,78);
    push(s,78);
    pop(s);
    push(s,90);
    return 0;
}