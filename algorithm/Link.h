//
//  Link.h
//  algorithm
//
//  Created by peng deng on 12/17/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#ifndef Link_h
#define Link_h

struct Node {
    char* content;
    struct Node* next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List; // 链表
typedef PtrToNode Element;
typedef PtrToNode Postiion; // 查找的结果


List MakeEmpty(List link);
List Create(char* array[], int length);
void Foreach(List list);
void Remove(Element element, List list);
int IsLast(Element element, List list);
int IsEmpty(List list);
// 根据内容查找
Element Find(char* content, List list);

void LinkTest();

#endif /* Link_h */
