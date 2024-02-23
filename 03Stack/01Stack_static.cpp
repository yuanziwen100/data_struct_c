/*
author:YuanZiwen
date: 2024/2/23
description:
*/
//
#define MaxSize 10

#include "stdio.h"


/**
 * 定义栈的Struct
 */
typedef struct {
    int array[MaxSize];
    int top;
} Stack;

/**
 * 初始化栈
 * @param stack
 */
void init(Stack &stack);

/**
 * 栈判空
 * @param stack
 * @return
 */
bool isEmpty(Stack stack);

/**
 * 元素入栈
 * @param stack
 * @param element
 * @return
 */
bool push(Stack &stack, int element);

/**
 * 栈顶元素出栈
 * @param stack
 * @return
 */
bool pop(Stack &stack);

/**
 * 获取栈顶元素
 * @param stack
 * @return
 */
int getTop(Stack stack);

int main() {
    Stack stack;
    init(stack);
    int i = 1;
    while (i < 20) {
        push(stack, i);
        printf("当前栈顶元素为%d\n", getTop(stack));
        i += 2;
    }

    pop(stack);
    printf("当前栈顶元素为%d\n", getTop(stack));
}


void init(Stack &stack) {
    stack.top = -1;
}


bool isEmpty(Stack stack) {
    return stack.top == -1;
}


bool push(Stack &stack, int element) {
    if (stack.top == MaxSize - 1) {
        printf("当前栈已满\n");
        return false;
    }
    stack.array[++stack.top] = element;
    printf("元素%d 入栈\n", element);
    return true;
}


bool pop(Stack &stack) {
    if (isEmpty(stack)) {
        printf("当前栈为空,无法出栈\n");
        return false;
    }
    int element = stack.array[stack.top--];
    printf("栈顶元素%d 出栈\n", element);
    return true;
}


int getTop(Stack stack) {
    if (isEmpty(stack)) {
        printf("当前栈为空,无法出栈\n");
        return false;
    }
    return stack.array[stack.top];
}