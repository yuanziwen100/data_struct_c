


#include "stdio.h"
#include "stdlib.h"


typedef struct LinkStackNode {
    int data;
    LinkStackNode *next;
} LinkedStackNode, *LinkedStack;

bool isEmpty(LinkedList list) {
    return list == NULL;
}


bool initLinkedStack(LinkedList &list);

bool push(LinkedList &list, int e);

LinkNode *pop(LinkedList &list);

void printList(LinkedList list);

int main() {
    setbuf(stdout, NULL);
    LinkedList list;
    //初始化
    initLinkedStack(list);
    int i = 1;
    while (i <= 10) {
        //栈顶插入元素
        push(list, i++);
    }

    printList(list);
    LinkNode *pNode = pop(list);
    printf("出栈元素%d\n", pNode->data);
    printList(list);

    return 0;
}


bool initLinkedStack(LinkedList &list) {
    list = NULL;
    printf("链表初始化成功\n");
    return true;
}


bool push(LinkedList &list, int e) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    if (s == NULL) {
        printf("内存不足\n");
        return false;
    }
    s->next = list;
    s->data = e;
    list = s;
    return true;
}


LinkNode *pop(LinkedList &list) {
    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return NULL;
    }
    LinkNode *s = list;
    list = s->next;
    return s;
}


void printList(LinkedList list) {
    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return;
    }

    LinkNode *p = list;
    int i = 1;
    while (p != NULL) {
        printf("第[%d]位的元素为%d\n", i, p->data);
        p = p->next;
        i++;
    }
}

