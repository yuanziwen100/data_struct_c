

#include "../ins.h"

/**
 * 定义一个链表(节点)
 */
typedef struct Node {
    int data;
    Node *next;
} Node, *LinkedList;

/**
 * 初始化链表
 * @param list
 */
void initList(LinkedList &list) {
    list = NULL;
    printf("链表初始化成功\n");
}




/**
 * 按位查找
 * @param list  链表对象
 * @param i  位序
 * @return 返回该节点  如果为NULL表示错误
 */
Node *getByIndex(LinkedList list, int i) {

    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return NULL;
    }
    //校验i的合法性
    if (i < 0) {
        printf("非法位序值\n");
        return NULL;
    }

    //当前链表的位序
    int j = 0;
    Node *p = list;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }


    return p;
}


/**
 * 链表销毁
 * @param list
 */
void destroyList(LinkedList &list) {
    Node *p = list;
    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return;
    }
    while (p->next != NULL) {
        Node *temp = p;
        p = temp->next;
        free(temp);
    }

    printf("链表已销毁\n");
}


/**
 * 在指定节点后插入元素
 * @param node
 * @param e
 * @return
 */
bool insertAfterNode(Node *node, int e) {
    if (node == NULL){
        return false;
    }
    Node *s = (Node *) malloc(sizeof(Node));
    if (s == NULL) {
        printf("内存不足\n");
        return false;
    }
    s->next = node->next;
    s->data = e;
    node->next = s;
    return true;
}

/**
 * 在指定节点前插入元素
 * @param list
 * @param e
 * @return
 */
bool push(LinkedList list, int e) {
    Node *s = (Node *) malloc(sizeof(Node));
    if (s == NULL) {
        printf("内存不足\n");
        return false;
    }
    s->next = list->next;
    list->next = s;
    s->data = list->data;
    list->data = e;
    return true;
}

/**
 * 在链表的第i位序中插入元素
 * @param list 链表
 * @param i  位序
 * @param e  元素
 * @return  是否插入成功
 */
bool insertList(LinkedList &list, int i, int e) {
    //校验i的合法性
    if (i < 1) {
        printf("非法位序值\n");
        return false;
    }
    //获取第i-1个元素
    Node *p = getByIndex(list, i - 1);



    //在i-1后插入元素e
    return insertAfterNode(p, e);
}




/**
 * 按值查找
 * @param list  链表对象
 * @param e  元素值
 * @return 返回该节点  如果为NULL表示错误
 */
Node *getByValue(LinkedList list, int e) {

    //当前链表的位序
    Node *p = list->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}


/**
 * 按位删除
 * @param list 链表对象
 * @param i 位序
 * @return
 */
bool removeByIndex(LinkedList list, int i) {
    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return false;
    }
    //校验i的合法性
    if (i < 1) {
        printf("非法位序值\n");
        return false;
    }
    //按位查找到i及i+1的节点
    Node *beforeP = getByIndex(list, i - 1);

    Node *p = getByIndex(list, i);
    if (beforeP == NULL || p == NULL) {
        return false;
    }
    beforeP->next = p->next;
    free(p);
    return true;
}


/**
 * 按值删除
 * @param list 链表对象
 * @param value 位序
 * @return
 */
bool removeByValue(LinkedList list, int value) {

    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return false;
    }

    //按值查找到对应节点
    Node *p = getByValue(list, value);
    if (p == NULL) {
        printf("未获取到对应节点\n");
        return false;
    }

    //遍历链表找到value的前一个节点
    Node *p1 = list;
    while (p1 != NULL && p1->next != p) {
        p1 = p1->next;
    }

    if (p1 == NULL) {
        printf("未找到p-1节点\n");
        return false;
    }
    p1->next = p->next;
    free(p);
    return true;
}





int main() {

    //禁用缓冲区
    setbuf(stdout, NULL);

    LinkedList list;
    //初始化list
    initList(list);

    //插入元素
    insertList(list, 1, 1);

    insertList(list, 2, 2);

    insertList(list, -1, 999);

    insertList(list, 3, 3);
    insertList(list, 4, 5);
    insertList(list, 4, 4);
    insertList(list, 10, 99);

    removeByIndex(list, 1);
    removeByValue(list, 999);

    printList(list);
    return 0;
}

