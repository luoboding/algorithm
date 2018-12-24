//
//  Type.h
//  algorithm
//
//  Created by peng deng on 12/19/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#ifndef Type_h
#define Type_h
typedef struct Node {
    char* content;
    struct Node* next;
} Node;

typedef Node* List; // 链表
typedef Node* Element;
typedef Node* Postion; // 查找的结果
typedef Node* Stack;


typedef int Post;

typedef struct {
    char* content;
    Post next;
} CursorNode;

typedef CursorNode* CursorElement;

#endif /* Type_h */
