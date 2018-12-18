//
//  Link.c
//  algorithm
//
//  Created by peng deng on 12/17/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#include "Link.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* 判断当前节点是否为最后节点 */
int IsLast(Element element, List list) {
    return element->next == NULL;
}

int IsEmpty(List list) {
    return list->next == NULL;
}


Element Find(char* content, List list) {
    Element current = list;
    while (current != NULL && current->content != content) {
        current = current->next;
    }
    return current;
}

void Remove(Element element, List list) {
    
    Element previous = NULL;
    Element current = list;
    while (!IsEmpty(list) && current != element) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

// 一个链表生成器
List Create(char* arr[], int length) {
    Element previous = NULL;
    List list = NULL;
    int i = 0;
    for(; i < length; i++) {
        printf("index %d, %s \n", i, arr[i]);
        Element element = malloc(sizeof(Element));
        element->content = arr[i];
        element->next = NULL;
        if (i == 0) {
            list = element;
        } else {
            previous->next = element;
        }
        previous = element;
    }
    return list;
}

// 遍历整个链表
void Foreach(List list) {
    Element current = list;
    while (current != NULL) {
        printf("content is %s\n", current->content);
        current = current->next;
    }
}
