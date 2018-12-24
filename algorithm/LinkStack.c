//
//  LinkStack.c
//  algorithm
//
//  Created by peng deng on 12/24/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#include "LinkStack.h"
#include <stdlib.h>
// 检查栈是否为为空.
int isLinkStackEmpty(Stack s) {
    return s->next == NULL;
}

Stack CreateLinkStack() {
    Stack s = malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Out off memory.");
    }
    s->next = NULL;
    MakeLinkStackEmpty(s);
    return s;
}

void MakeLinkStackEmpty(Stack s) {
    if (s == NULL) {
        printf("stack can not be null");
    } else {
        while (!isLinkStackEmpty(s)) {
            PopLinkStack(s);
        }
    }
}

// 压栈
void PushLinkStack(Stack s, char* content) {
    if (s == NULL) {
        printf("stack can not be null");
    } else {
        struct Node* temp = malloc(sizeof(struct Node*));
        temp->content = content;
        temp->next = s->next;
        s->next = temp;
    }
}

// 返回栈顶元素
char* top(Stack s) {
    if (s == NULL) {
        return 0;
    }
    return s->next->content;
}

// 弹栈

void PopLinkStack(Stack s) {
    struct Node* FirstCell;
    if (s == NULL) {
        printf("stack can not be null");
    } else {
        FirstCell = s->next;
        s->next = s->next->next;
        free(FirstCell);
    }
}
