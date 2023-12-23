//
//  main.c
//  4.Stack
//
//  Created by inncrewin on 21/12/23.
//

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int * S;
};

void createStack(struct Stack *);
void displayStack(struct Stack *);
void pushStack(struct Stack *,int);
int popStack(struct Stack *);
int peekStack(struct Stack *,int);



int main(int argc, const char * argv[]) {
    struct Stack * st;
    st = (struct Stack *)malloc(sizeof(struct Stack));
    createStack(st);
    pushStack(st, 2);
    pushStack(st, 4);
    pushStack(st, 6);
//    displayStack(st);
//    popStack(st);
//    displayStack(st);
    printf("Value is = %d\n",peekStack(st,1));
    return 0;
}

void createStack(struct Stack * stTmp){
    stTmp ->top = -1;
    printf("Enter stack size = ");
    scanf("%d",&stTmp->size);
    stTmp->S = (int  *)malloc(sizeof(stTmp->size*sizeof(int)));
}

void displayStack(struct Stack * stTmp){
    for (int i = 0; i<=stTmp->top; i++) {
        int data =stTmp->S[i];
        printf("Stack[%d] = %d\n",i,data);
    }
}



void pushStack(struct Stack * stTmp,int data){
    if(stTmp ->top == (stTmp->size - 1)){
        printf("Overflow");
        return;
    }
    stTmp ->top ++;
    stTmp->S[stTmp ->top] = data;
}


int popStack(struct Stack * stTmp){
    int data = -1;
    //check for empty condition
    if(stTmp ->top == -1){
        printf("Stack is empty");
    }else{
        data = stTmp->S[stTmp->top];
        stTmp->top --;
    }
    return  data;
}

int peekStack(struct Stack * stTmp,int pos){
    int data = -1;
    if(pos < 1 || pos > stTmp ->top + 1){
        printf("Invalid position\n");
    }else{
        int index = stTmp ->top + 1 - pos;
        data = stTmp->S[index];
    }
    return  data;
}
