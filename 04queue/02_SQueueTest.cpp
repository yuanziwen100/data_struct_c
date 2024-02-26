#include "queue.h"

/**
 * 初始化
 * @param queue
 * @return
 */
bool init(SQueue &queue);

/**
 * 判空
 * @param queue
 * @return
 */
bool isEmpty(SQueue queue);

/**
 * 判满
 * @param queue
 * @return
 */
bool isFull(SQueue queue);


bool inQueue(SQueue &queue, int e);

int readHead(SQueue queue);

bool outQueue(SQueue &queue);

void printQueue(SQueue queue);

int main() {
    setbuf(stdout, nullptr);
    //声明队列
    SQueue queue;
    //初始化队列
    init(queue);

    //入队
    int i = 1;
    while (i <= 10) {
        inQueue(queue, i++);
    }
    //遍历队列
    printQueue(queue);

    printf("当前队列长度为%d\n", queue.size);
    //出队3个元素
    for (int j = 0; j < 10; ++j) {
        outQueue(queue);
    }
    //遍历队列
    printQueue(queue);
    printf("当前队列长度为%d\n", queue.size);
    return 0;
}


bool init(SQueue &queue) {
    queue.rear = 0;
    queue.front = 0;
    queue.size = 0;
    printf("队列初始化成功\n");
    return true;
}

bool isEmpty(SQueue queue) {
    return queue.size == 0;
}

bool isFull(SQueue queue) {
    return queue.size == MaxSize;
}


bool inQueue(SQueue &queue, int e) {
    if (isFull(queue)) {
        printf("当前队列已满,无法插入新元素\n");
        return false;
    }
    queue.data[queue.rear] = e;
    queue.rear = (queue.rear + 1) % MaxSize;
    queue.size++;
    return true;
}

int readHead(SQueue queue) {
    if (isEmpty(queue)) {
        printf("读取队头元素,队列不可为空\n");
        return false;
    }
    return queue.data[queue.front];
}

bool outQueue(SQueue &queue) {
    if (isEmpty(queue)) {
        printf("出队队列不可为空\n");
        return false;
    }
    int head = readHead(queue);
    printf("队头元素%d被删除\n", head);
    queue.front = (queue.front + 1) % MaxSize;
    queue.size--;
    return true;
}

void printQueue(SQueue queue) {
    if (isEmpty(queue)) {
        printf("队列为空无法遍历\n");
        return;
    }
    int point = queue.front;
    int count = 1;
    while (point < queue.size && count <= queue.size) {
        printf("队列元素第%d位为%d\n", count++, queue.data[point]);
        point = (point + 1) % MaxSize;
    }
}

