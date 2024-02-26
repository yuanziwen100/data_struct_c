
/**
 * 牺牲一个长度的队列
 */

#include "queue.h"


/**
 * 初始化队列
 * @param queue
 * @return
 */
bool initQueue(CQueue &queue);

/**
 * 判空
 * @param queue
 * @return
 */
bool isEmpty(CQueue queue);


/**
 * 判满
 * @param queue
 * @return
 */
bool isFull(CQueue queue);

/**
 * 入队
 * @param queue
 * @param e
 * @return
 */
bool inQueue(CQueue &queue, int e);

/**
 * 读取队头元素
 * @param queue
 * @return
 */
int readHead(CQueue &queue);

/**
 * 出队
 * @param queue
 * @return
 */
bool outQueue(CQueue &queue);

/**
 * 获取队列长度
 * @param queue
 * @return
 */
int length(CQueue queue);


/**
 * 遍历队列
 * @param queue
 */
void printQueue(CQueue queue);

int main() {
    //输出区禁用缓存
    setbuf(stdout, NULL);
    //定义队列
    CQueue queue;
    //初始化队列
    initQueue(queue);
    //入队
    int i = 1;
    while (i <= 10) {
        inQueue(queue, i++);
    }
    //遍历队列
    printQueue(queue);

    printf("当前队列长度为%d\n", length(queue));
    //出队3个元素
    for (int j = 0; j < 10; ++j) {
        outQueue(queue);
    }
    //遍历队列
    printQueue(queue);
    printf("当前队列长度为%d\n", length(queue));
    return 0;
}


bool initQueue(CQueue &queue) {
    queue.rear = 0;
    queue.front = 0;
    return true;
}


bool isEmpty(CQueue queue) {
    return queue.front == queue.rear;
}


bool isFull(CQueue queue) {
    return (queue.rear + 1) % MaxSize == queue.front;
}


bool inQueue(CQueue &queue, int e) {
    if (isFull(queue)) {
        printf("队列已满无法插入新元素\n");
        return false;
    }
    queue.data[queue.rear] = e;
    queue.rear = (queue.rear + 1) % MaxSize;
    printf("元素%d入队\n", e);
    return true;
}

int readHead(CQueue &queue) {
    if (isEmpty(queue)) {
        printf("队列不可为空\n");
        return false;
    }
    return queue.data[queue.front];
}


bool outQueue(CQueue &queue) {
    if (isEmpty(queue)) {
        printf("队列为空,无法出队\n");
        return false;
    }
    //读取一下队头元素
    int head = readHead(queue);

    queue.front = (queue.front + 1) % MaxSize;
    printf("队头元素head:%d出队\n", head);
    return true;
}

int length(CQueue queue) {
    int length;
    if (queue.rear < queue.front) {
        length = queue.rear + MaxSize - queue.front;
    } else {
        length = queue.rear - queue.front;
    }
    return length;
}


void printQueue(CQueue queue) {
    if (isEmpty(queue)) {
        printf("队列为空无法遍历\n");
        return;
    }
    int point = queue.front;
    while (point < queue.rear) {
        printf("队列元素%d\n", queue.data[point]);
        point = (point + 1) % MaxSize;
    }
}