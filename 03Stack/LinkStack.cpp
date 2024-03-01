
#include "stdio.h"
#include "stdlib.h"
#include "iostream"

typedef struct LinkStackNode {
    int data;
    LinkStackNode *next;
} LinkedStackNode, *LinkedStack;


bool initLinkedStack(LinkedStack &list);

bool push(LinkedStack &list, int e);

LinkedStackNode *pop(LinkedStack &list);

void printList(LinkedStack list);


int main() {
    int equation[100] = {15,7,1,1,};
    return 0;
}


bool isEmpty(LinkedStack stack) {
    return stack == nullptr;
}


bool initLinkedStack(LinkedStack &stack) {
    stack = nullptr;
    printf("栈初始化成功\n");
    return true;
}


bool push(LinkedStack &stack, int e) {
    LinkedStackNode *s = (LinkedStackNode *) malloc(sizeof(LinkedStackNode));
    if (s == nullptr) {
        printf("内存不足\n");
        return false;
    }
    s->next = stack;
    s->data = e;
    stack = s;
    return true;
}


LinkedStackNode *pop(LinkedStack &stack) {
    if (isEmpty(stack)) {
        printf("链栈不可为空\n");
        return nullptr;
    }
    LinkedStackNode *s = stack;
    stack = stack->next;
    return s;
}










