/*
author:YuanZiwen
date: 2024/2/23
description:
*/

#define Maxsize 50

#include "stdio.h"

/**
 * 共享栈帧
 * 定义栈的Struct
 */
typedef struct {
    /**
     * 栈数组
     */
    int array[Maxsize];
    /**
     * 底部栈指针
     */
    int top0;

    /**
     * 顶部栈指针
     */
    int top1;
} ShareStack;


///**
// * 初始化栈
// * @param ShareStack
// */
//void init(ShareStack &ShareStack);
//
///**
// * 栈判空
// * @param ShareStack
// * @return
// */
//bool isEmpty(ShareStack ShareStack);
//
///**
// * 元素入栈
// * @param ShareStack
// * @param element
// * @return
// */
//bool push(ShareStack &ShareStack, int element);
//
///**
// * 栈顶元素出栈
// * @param ShareStack
// * @return
// */
//bool pop(ShareStack &ShareStack);
//
///**
// * 获取栈顶元素
// * @param ShareStack
// * @return
// */
//int getTop(ShareStack ShareStack);
//
//int main() {
//    ShareStack ShareStack;
//    init(ShareStack);
//    int i = 1;
//    while (i < 20) {
//        push(ShareStack, i);
//        printf("当前栈顶元素为%d\n", getTop(ShareStack));
//        i += 2;
//    }
//
//    pop(ShareStack);
//    printf("当前栈顶元素为%d\n", getTop(ShareStack));
//}
//
//
//void init(ShareStack &ShareStack) {
//    ShareStack.top0 = -1;
//    ShareStack.top1 = Maxsize;
//}
//
//
//bool isEmpty(ShareStack ShareStack) {
//    return ShareStack.top0 == -1||  ShareStack.top1 == Maxsize;
//}
//
//
//bool push(ShareStack &ShareStack, int element) {
//    if (ShareStack.top == MaxSize - 1) {
//        printf("当前栈已满\n");
//        return false;
//    }
//    ShareStack.array[++ShareStack.top] = element;
//    printf("元素%d 入栈\n", element);
//    return true;
//}
//
//
//bool pop(ShareStack &ShareStack) {
//    if (isEmpty(ShareStack)) {
//        printf("当前栈为空,无法出栈\n");
//        return false;
//    }
//    int element = ShareStack.array[ShareStack.top--];
//    printf("栈顶元素%d 出栈\n", element);
//    return true;
//}
//
//
//int getTop(ShareStack ShareStack) {
//    if (isEmpty(ShareStack)) {
//        printf("当前栈为空,无法出栈\n");
//        return false;
//    }
//    return ShareStack.array[ShareStack.top];
//}
