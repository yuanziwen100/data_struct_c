#ifndef DATA_STRUCT_C_LINKQUEUE_H
#define DATA_STRUCT_C_LINKQUEUE_H

#endif //DATA_STRUCT_C_LINKQUEUE_H


#include "stdio.h"
#include "stdlib.h"
#include "iostream"

/**
 * 链表队列节点
 */
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode, *LinkNodeP;

typedef struct {
    /**
     * 头指针;尾指针
     */
    LinkNode *front, *rear;
    /**
     * 长度
     */
    int length;
} LinkQueue;




int size(LinkQueue queue) {
    return queue.length;
}