
#include "../../ins.h"


/**
 * 链表判空
 * @param list
 * @return
 */
bool isEmpty(LinkedList list) {
    return list == NULL;
}


/**
 * 打印链表
 * @param list
 */
void printList(LinkedList list) {
    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return;
    }

    Node *p = list->next;
    int i = 1;
    while (p != NULL) {
        printf("第[%d]位的元素为%d\n", i, p->data);
        p = p->next;
        i++;
    }
}
