//
//  LinkCursor.c
//  algorithm
//
//  Created by peng deng on 12/19/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#include "LinkCursor.h"
#include <stdlib.h>


CursorElement* InitializeCursorList(char** array, int length) {
    CursorElement* result = malloc(sizeof(CursorElement) * length);
    int i = 0;
    for (; i < length; i++) {
        CursorElement element = malloc(sizeof(CursorElement));
        element->content = array[i];
        element->next = i + 1;
        result[i] = element;
    }
    result[length - 1]->next = 0;
    return result;
}

Post FindCursor(char* find, CursorElement* list) {
    CursorElement current = *list;
    Post pos = -1;
    while (current->next && current->content != find) {
        pos = current->next;
        current = list[current->next];
    }
    return pos;
}

void ForeachCursor(CursorElement* list) {
    CursorElement current = *list;
    while (current->next) {
        printf("content is %d \n", current->next);
        current = list[current->next];
    }
    printf("content is %s \n", current->content);
}

void TestCursor() {
    char* input[] = {"hello", "world", "my", "friend"};
    CursorElement* array = InitializeCursorList(input, 4);
    printf("position is %d\n", FindCursor("my", array));
//    ForeachCursor(array);
}
