
#include "../ins.h"


/**
 * 尾插法建立一个链表
 * @param list
 * @return
 */
LinkedList listTailInsert(LinkedList &list);

/**
 * 头插法建立一个链表
 * @param list 
 * @return 
 */
LinkedList ListHeaderInsert(LinkedList &list);

/**
 * 链表倒转
 */
LinkedList listReverse(LinkedList &list);

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    LinkedList list;
    listTailInsert(list);
    printList(list);
    listReverse(list);
    printList(list);
    return 0;
}


LinkedList listTailInsert(LinkedList &list) {
    //输入的数字
    int x;
    //为链表申请一块空间
    list = (LinkedList) malloc(sizeof(LinkNode));
    if (list == NULL) {
        printf("内存不足\n");
        return NULL;
    }
    //赋值指针指向头节点
    LinkNode *s, *r = list;

    //首次为x输入值
    printf("请输入元素\n");
    scanf("%d", &x);
    while (x != -1) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        if (s == NULL) {
            printf("内存不足\n");
            break;
        }
        s->data = x;
        r->next = s;
        r = s;
        printf("请输入元素\n");
        scanf("%d", &x);
    }
    //置尾结点的next为NULL
    r->next = NULL;
    return list;
}


LinkedList ListHeaderInsert(LinkedList &list) {
    //用户输入值变量
    int x;
    //为链表头结点申请空间
    list = (LinkNode *) malloc(sizeof(LinkNode));
    if (list == NULL) {
        printf("内存不足\n");
        return NULL;
    }
    list->next = NULL;
    scanf("%d", &x);
    while (x != -1) {
        LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
        if (s == NULL) {
            printf("内存不足\n");
            break;
        }
        s->data = x;
        s->next = list->next;
        list->next = s;
        scanf("%d", &x);
    }

    return list;


}


LinkedList listReverse(LinkedList &list) {
    if (isEmpty(list)) {
        printf("链表不可为空\n");
        return NULL;
    }
    LinkNode *s, *r = list;

    while (r != NULL) {
        s = r;
        r->next = s->next;
        list->next = s;
        s->next = r;
        if (r->next->next == NULL) {
            s = r->next;
            s->next = list->next;
            list->next = s;
            r->next = NULL;
            break;
        }
        r = r->next;
    }
    return list;

}


