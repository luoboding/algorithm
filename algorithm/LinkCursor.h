//
//  LinkCursor.h
//  algorithm
//
//  Created by peng deng on 12/19/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#ifndef LinkCursor_h
#define LinkCursor_h

#include <stdio.h>
#include "Type.h"

CursorElement* InitializeCursorList(char**, int length);
void ForeachCursor(CursorElement* list);

void Test();


#endif /* LinkCursor_h */
