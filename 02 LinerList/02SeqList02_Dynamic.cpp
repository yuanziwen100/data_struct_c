/*
author:YuanZiwen
data: 2024/2/18
description:
*/
//
#include "iostream"
#include "stdio.h"
#include "stdlib.h"

#define InitSize 10

//定义结构体
typedef struct {
    //数据
    int *data;
    //当前数组的最大长度
    int maxSize;
    //线性表的当前长度
    int length;
} SeqList;

void printList(SeqList list);

/**
 * 初始化数据结构
 * @param list
 */
void initList(SeqList &list) {

    list.data = (int *) malloc(sizeof(int) * InitSize);
    for (int i = 0; i < InitSize; ++i) {
        list.data[i] = 0;
    }
    //赋值数据结构的长度相关变量
    list.length = 0;
    list.maxSize = InitSize;
    std::cout << "----------------------\n"
              << "init successfully"
              << std::endl;
}

/**
 * 销毁数据结构
 * @param list
 */
void destroyList(SeqList &list) {
    list.length = list.maxSize = 0;
    //释放内存空间
    free(list.data);
    std::cout << "----------------------\n"
              << "destroy successfully"
              << std::endl;
}

/**
 * 动态扩容
 * @param p
 * @param length
 * @return
 */
void increaseMemory(SeqList &list) {
    int *p = list.data;
    list.maxSize <<= 1;
    list.data = (int *) malloc((sizeof(int) * list.maxSize));
    for (int i = 0; i < list.length; ++i) {
        list.data[i] = p[i];
    }
    //释放原来的内存空间
    free(p);
}


/**
 * 在第i的位置插入数据
 * @param list
 * @param i
 * @param data
 */
void listInsert(SeqList &list, int i, int data) {
    //判断是否越界
    if (list.length != 0 && i < 1) {
        printf("非法位序值\n");
        return;
    }

    //指针判空
    if(list == NULL){
        return;
    }

    list.data[(i - 1)] = data;
    list.length++;
    if (list.length >= list.maxSize) {
        increaseMemory(list);
    }
    std::cout << "----------------------\n"
              << "insert successfully"
              << std::endl;
}

/**
 * 删除第i的位置上的数据
 * @param list
 * @param i
 */
void listRemove(SeqList &list, int i) {
    //判断是否越界
    if (i < 1) {
        printf("非法位序值\n");
        return;
    }
    list.data[i - 1] = 0;
    //处理结构中的数据
    for (int v = i - 1; v + 1 < list.length; ++v) {
        list.data[v] = list.data[v + 1];
        list.data[v + 1] = 0;
    }
    list.length--;
    std::cout << "----------------------\n"
              << "删除第[ " << i << "]位上的元素成功"
              << std::endl;
}

/**
 * 查找位序上的元素
 * @param sqlList
 * @param index
 * @return
 */
int getElement(SeqList list, int index) {
    //判断是否越界
    if (index >= list.maxSize || index < 1) {
        printf("非法位序值");
        return -999;
    }
    int result = list.data[index - 1];
    std::cout << "----------------------" << std::endl;
    printf("获取位序[%d]结果位%d\n", index, result);
    return result;
}

/**
 * 获取一个线性表实例
 * @return 
 */
SeqList getInstance() {
    //实例化sqlList
    SeqList sqlList;
    initList(sqlList);
    return sqlList;
}


int main() {
    //获取线性表实例
    SeqList sqlList = getInstance();
    //在线性表中第i位上插入元素data

    for (int i = 1; i < 100; ++i) {
        listInsert(sqlList, i, i);
    }

    //获取并打印第i位上的元素
    int result = getElement(sqlList, 2);

    //删除第i位上的元素
//    listRemove(sqlList, 2);
    //打印当前线性表
    printList(sqlList);
    //线性表销毁
    destroyList(sqlList);
}

/**
 * 打印表
 * @param list
 */
void printList(SeqList list) {
    std::cout << "----------------------\n"
              << "start to print this list"
              << std::endl;

    int length = list.length;
    if (length > list.maxSize || (list.length != 0 && length < 1)) {
        printf("非法长度");
        return;
    }
    for (int i = 0; i < length; ++i) {
        printf("list 第[%d]位元素为%d\n", (i + 1), list.data[i]);
    }
}
