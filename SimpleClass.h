//
// Created by Jie Liu on 8/7/14.
// Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//


#ifndef __SimpleClass_H_
#define __SimpleClass_H_

#include "Serialize.h"

class SimpleClass
{
public:
    typedef HasOwnSerializeInterface SerializeInterface;

    void Serialize(){
        cout << "use own serialize function" << endl;
    }
};


#endif //__SimpleClass_H_
