#ifndef DATA_STRUCT_C_QUEUE_H
#define DATA_STRUCT_C_QUEUE_H

#endif //DATA_STRUCT_C_QUEUE_H


#include "stdlib.h"
#include "stdio.h"
#include "iostream"

#define  MaxSize 10


/**
 * 普通队列
 */
typedef struct {
    int data[MaxSize];

    int front, rear;
} CQueue;

/**
 * 带size的队列
 */
typedef struct {
    /**
     * 数据数组
     */
    int data[MaxSize];

    /**
     * 队头下标 队尾下标 队列长度
     */
    int front, rear, size;
} SQueue;

/**
 * 带tag的队列
 */
typedef struct {
    int data[MaxSize];

    int front, rear, tag;
} TQueue;