//
//  Link.h
//  algorithm
//
//  Created by peng deng on 12/17/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#ifndef Link_h
#define Link_h
#include "Type.h"

List MakeEmpty(List link);
List Create(char* array[], int length);
void Foreach(List list);
void Remove(Element element, List list);
int IsLast(Element element, List list);
int IsEmpty(List list);
// 根据内容查找
Element Find(char* content, List list);

Element FindPrevious(char* content, List list);

void Insert(char* content, List list, Element before);

void DeleteList(List list);

void LinkTest();

#endif /* Link_h */
