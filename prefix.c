#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    int* arr;
};
int prefix(char *su,struct stack* s){
    for(int i=strlen(su);i>=0;i--){
        if(su[i]>='0'&&su[i]<='9'){
            s->top++;
            s->arr[s->top]=(su[i]-'0');
        }
        else{
            int op1=s->arr[s->top];
            s->top--;
            int op2=s->arr[s->top];
            s->top--;
            
            switch(su[i]){
                case '+':
                s->arr[s->top]=op1+op2;
                break;
                case '-':
                s->arr[s->top]=op1-op2;
                break;
                case '*':
                s->arr[s->top]=op1*op2;
                break;
                case '/':
                s->arr[s->top]=op1/op2;
                break;
            }
        }
    }
    return s->arr[s->top];
}

int main(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    char su[]="-+7*45+20";
    int d=prefix(su,s);
    printf("%d",d);
    return 0;
}