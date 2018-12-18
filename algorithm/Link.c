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
#include <assert.h>


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

void Insert(char* content, List list, Element before) {
    Element element = malloc(sizeof(Element));
    // 这里应该检查是否为NULL
    element->content = content;
    element->next = before->next;
    before->next = element;
}

Element FindPrevious(char* content, List list) {
    Element current = list;
    Element previous = NULL;
    while ( current!= NULL && current->content != content) {
        previous = current;
        current = current->next;
    }
    return previous;
}

// 删除整个链表
void DeleteList(List list) {
    Element current = list;
    while (current != NULL) {
        Element temp = current -> next;
        free(current);
        current = temp;
    }
}

void LinkTest() {
    char* arr[] = {"hello", "world", "how", "are", "you"};
    List list = Create(arr, 5);
    assert(!IsEmpty(list));
    Foreach(list);
    Element find = Find("world", list);
    assert(find -> content == "world");
    
    Element beforeFind = FindPrevious(find->content, list);
    assert(beforeFind->content == "hello");
    
    Remove(find, list);
    printf("remove find, then foreach; \n");
    Foreach(list);
    
    
    Insert("my friends!", list, beforeFind);
    Foreach(list);
    
    Element lost = Find("world", list);
    assert(lost == NULL);
    Element last = Find("you", list);
    assert(IsLast(last, list));
    printf("delete all list:\n");
    
    DeleteList(list);
    assert(IsEmpty(list));
    
}
