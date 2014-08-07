//
//  main.cpp
//  Traits
//
//  Created by Jie Liu on 8/7/14.
//  Copyright (c) 2014 Jie Liu. All rights reserved.
//

#include <iostream>
#include "SimpleClass.h"

int main(int argc, const char * argv[])
{

    SimpleClass simpleClass;
    Serialize(simpleClass);


    int a = 10;
    Serialize(a);

    return 0;
}
