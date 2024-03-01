
#include "linkQueue.h"

/**
 * 初始化
 * @param queue
 */
void init(LinkQueue &queue);

/**
 * 判空
 * @param queue
 * @return
 */
bool isEmpty(LinkQueue queue);

/**
 * 队列入队
 * @param queue
 * @param e
 * @return
 */
bool push(LinkQueue &queue, int e);

/**
 * 队列出队
 * @param queue
 * @param e
 * @return
 */
bool pop(LinkQueue &queue, int &e);



/**
 * 打印队列链表
 * @param queue
 */
void printLinkQueue(LinkQueue queue);

int main() {
    //禁用缓冲区
    setbuf(stdout, nullptr);
    setbuf(stdin, nullptr);
    int ti, to;
    printf("请输入入队队列个数和出队队列个数\n");
    scanf("%d%d", &ti, &to);

    LinkQueue queue;
    //初始化
    init(queue);
    int i = 0, j = 0;
    while (++i <= ti) {
        push(queue, i);
    }
    //打印链表队列
    printLinkQueue(queue);

    //出队若干

    int e = -999;
    while (++j <= to) {

        pop(queue, e);
    }

    int length = size(queue);
    int realLength = i - j;
    printf("测试结束,当前队列长度为%d,实际应为%d,测试结果%d\n", length, realLength, realLength == length);

    //打印
    printLinkQueue(queue);

    return 0;
}


void init(LinkQueue &queue) {
    queue.front = queue.rear = (LinkNode *) malloc(sizeof(LinkNode));
    queue.front->next = nullptr;
    queue.length = 0;
    std::cout << "***********************************\n" << "链表队列初始化成功" << std::endl;

}


bool isEmpty(LinkQueue queue) {
    return queue.front->next == nullptr;
}


bool push(LinkQueue &queue, int e) {
    LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
    if (s == nullptr) {
        printf("分配内存空间失败\n");
        return false;
    }
    s->data = e;
    s->next = nullptr;
    queue.rear->next = s;
    queue.rear = s;
    queue.length++;
    printf("队列元素[%d]入队成功,当前长度%d\n", e, queue.length);
    return true;
}


bool pop(LinkQueue &queue, int &e) {
    if (isEmpty(queue)) {
        printf("出队队列不可为空\n");
        return false;
    }
    LinkNode *s = queue.front->next;
    e = s->data;
    queue.front->next = s->next;
    //如果是最后一个元素出队，恢复为初始化状态
    if (s == queue.rear) {
        queue.front == queue.rear;
    }
    free(s);
    queue.length--;
    printf("队列元素[%d]出队成功,当前长度%d\n", e, queue.length);
    return true;
}

void printLinkQueue(LinkQueue queue) {
    printf("**********************************\n");
    LinkNode *point = queue.front->next;
    int counter = 1;
    while (point != nullptr) {
        printf("队列第%d位元素为%d\n", counter++, point->data);
        point = point->next;
    }


}

