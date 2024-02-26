
#include "stdio.h"
#include "stdlib.h"
#include <iostream>

/**
 * 定义一个链表(节点)
 */
typedef struct Node {
    int data;
    Node *next;
} Node, *LinkedList;


/**
 * 链表打印
 * @param list
 */
void printList(LinkedList list);

/**
 * 链表判空
 * @param list
 * @return
 */
bool isEmpty(LinkedList list);
