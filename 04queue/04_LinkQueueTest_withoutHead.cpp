

#include "linkQueue.h"


void init(LinkQueue &queue);

bool isEmpty(LinkQueue queue);

bool push(LinkQueue &queue, int e);

bool pop(LinkQueue &queue, int &e);

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
    queue.front = queue.rear = nullptr;
    queue.length = 0;
    std::cout << "***********************************\n" << "链表队列初始化成功" << std::endl;
}


bool isEmpty(LinkQueue queue) {
    return queue.front == nullptr || queue.length == 0;
}


bool push(LinkQueue &queue, int e) {
    LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
    if (node == nullptr) {
        printf("分配内存空间失败\n");
        return false;
    }
    node->data = e;
    node->next = nullptr;
    if (queue.front == nullptr) {
        queue.front = queue.rear = node;
    } else {
        queue.rear->next = node;
        queue.rear = node;
    }
    queue.length++;
    printf("队列元素[%d]入队成功,当前长度%d\n", e, queue.length);
    return true;
}


bool pop(LinkQueue &queue, int &e) {
    if (isEmpty(queue)) {
        printf("出队队列不可为空\n");
        return false;
    }
    LinkNode *node = queue.front;
    e = node->data;
    queue.front = node->next;
    if (node == queue.rear) {
        queue.front = queue.rear = nullptr;
    }
    free(node);
    queue.length--;
    printf("队列元素[%d]出队成功,当前长度%d\n", e, queue.length);
    return true;
}


void printLinkQueue(LinkQueue queue) {
    printf("**********************************\n");
    LinkNode *point = queue.front;
    int counter = 1;
    while (point != nullptr) {
        printf("队列第%d位元素为%d\n", counter++, point->data);
        point = point->next;
    }


}
