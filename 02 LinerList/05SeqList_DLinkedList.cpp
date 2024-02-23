
#include "ins.h"


/**
 * 定义双向链表(节点)
 * @return
 */
typedef struct DNode {
    int e;
    DNode *prior, *next;
} DNode, *DLinkedList;

/**
 * 初始化双向链表
 * @param list
 * @return
 */
bool init(DLinkedList &list);

/**
 * 双向链表判空
 * @param list
 * @return
 */
bool isEmpty(DLinkedList list);

/**
 * 在指定节点后插入后继节点
 * @param node 指定节点
 * @param nextNode 后继节点
 * @return
 */
bool insertNextNode(DNode *node, DNode *nextNode);

/**
 * 在指定节点前插入前驱节点
 * @param node 指定节点
 * @param priorNode  前驱节点
 * @return
 */
bool insertPriorNode(DNode *node, DNode *priorNode);

/**
 *
 * @param node  删除指定节点
 * @return
 */
bool deleteNextNode(DNode *node);

/**
 * 销毁表
 * @param list
 * @return
 */
bool destroyList(DLinkedList &list);

/**
 * 遍历表
 * @param list 
 * @return 
 */
bool printDList(DLinkedList list);

int main() {
    DLinkedList list;
    init(list);
    int i = 1;
    DNode *temp = list;
    while (i <= 10) {
        DNode *s = (DNode *) malloc(sizeof(DNode));
        s->e = i;
        s->next = nullptr;
        s->prior = nullptr;
        insertNextNode(temp, s);
        temp = temp->next;
        i++;
    }

    printDList(list);

    destroyList(list);

    return 0;
}

bool init(DLinkedList &list) {
    list = (DLinkedList) malloc(sizeof(DNode));
    if (list == nullptr) {
        printf("内存不足\n");
        return false;
    }
    //将前置节点设置为NULL 永远为NULL
    list->prior = nullptr;
    //将后继节点暂时设置为NULL
    list->next = nullptr;
    return true;
}

bool isEmpty(DLinkedList list) {
    if (list == nullptr) {
        return true;
    }
    return list->next == nullptr;
}


bool insertNextNode(DNode *node, DNode *nextNode) {
    //非空校验
    if (nextNode == nullptr || node == nullptr) {
        printf("入参节点不可为空");
        return false;
    }
    nextNode->next = node->next;
    //如果被操作有后继节点则修改后继节点的前驱结点
    if (node->next != nullptr) {
        node->next->prior = nextNode;
    }

    node->next = nextNode;
    nextNode->prior = node;
    return true;
}


bool insertPriorNode(DNode *node, DNode *priorNode) {
    //非空校验
    if (priorNode == nullptr || node == nullptr) {
        printf("入参节点不可为空");
        return false;
    }

    priorNode->next = node;
    priorNode->prior = node->prior;
    //如果被操作节点有前继节点则继承给入参前置节点
    if (node->prior != nullptr) {
        node->prior->next = priorNode;
    }
    node->prior = priorNode;
    return true;
}


bool deleteNextNode(DNode *node) {
    if (node == nullptr) {
        printf("入参节点不可为空");
        return false;
    }

    DNode *next = node->next;
    DNode *prior = node->prior;
    prior->next = next;

    if (next != nullptr) {
        next->prior = prior;
    }
    free(node);
    return true;
}

bool destroyList(DLinkedList &list) {
    if (isEmpty(list)) {
        return false;
    }
    while (list->next != nullptr) {
        deleteNextNode(list->next);
    }
    free(list);
    list = nullptr;
    return true;
}


bool printDList(DLinkedList list) {
    if (isEmpty(list)) {
        return false;
    }
    int i = 1;
    DNode *next = list->next;
    while (next != nullptr) {
        printf("第[%d]位 的数值为%d\n", i, next->e);
        next = next->next;
        i++;
    }
    return true;
}

