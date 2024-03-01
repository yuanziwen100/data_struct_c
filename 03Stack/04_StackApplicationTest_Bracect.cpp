

#include "stdio.h"


#define Maxsize 10


typedef struct {
    char data[Maxsize];
    int top;
} Stack;


bool match(char brackets[], int length);

int main() {

    char brackets[13] = "(((())){[]}]";
    bool result = match(brackets, 12);
    printf("测试完成[%s],测试结果%d\n", brackets, result);
    return 0;
}


void init(Stack &stack) {
    stack.top = -1;
}

bool isEmpty(Stack stack) {
    return stack.top == -1;
}


bool push(Stack &stack, char element) {
    if (stack.top == Maxsize - 1) {
        printf("当前栈已满\n");
        return false;
    }
    stack.data[++stack.top] = element;
    printf("元素%c 入栈\n", element);
    return true;
}

char pop(Stack &stack, char &top) {
    if (isEmpty(stack)) {
        printf("当前栈为空,无法出栈\n");
        return false;
    }
    top = stack.data[stack.top--];
    printf("栈顶元素%c 出栈\n", top);
    return top;
}


bool match(char brackets[], int length) {
    Stack stack;
    init(stack);

    for (int i = 0; i < length; ++i) {
        char param = brackets[i];
        if (param == '(' || param == '[' || param == '{') {
            //入栈
            push(stack, param);
        } else {
            if (isEmpty(stack)) {
                return false;
            }

            char top;
            pop(stack, top);
            if (top != '(' && param == ')') {
                return false;
            } else if (top != '[' && param == ']') {
                return false;
            } else if (top != '{' && param == '}') {
                return false;
            }
            printf("出栈%c与入参%c匹配成功\n", param, top);
        }
    }

    return isEmpty(stack);
}



