//
//  main.c
//  algorithm
//
//  Created by peng deng on 12/17/18.
//  Copyright © 2018 peng deng. All rights reserved.
//

#include <stdio.h>
#include "Link.h"
#include <assert.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("start: \n");
    char* arr[] = {"hello", "world", "how", "are", "you"};
    List list = Create(arr, 5);
    assert(!IsEmpty(list));
    Foreach(list);
    Element find = Find("world", list);
    assert(find -> content == "world");
    Remove(find, list);
    printf("remove find, then foreach; \n");
    Foreach(list);
    
    Element lost = Find("world", list);
    assert(lost == NULL);
    Element last = Find("you", list);
    assert(IsLast(last, list));
    
    
    return 0;
}
