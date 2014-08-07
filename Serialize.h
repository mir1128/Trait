#pragma once

#include <iostream>
using namespace std;

struct HasOwnSerializeInterface{};
struct HasNoSerializeInterface{};

template <class T>
class Trait
{
public:
    typedef typename T::SerializeInterface SerializeInterface;
};

#define PartialSpecialization(x) \
template <> \
class Trait<x> \
{   \
public: \
    typedef  HasNoSerializeInterface SerializeInterface; \
};

PartialSpecialization(int)
PartialSpecialization(char)
PartialSpecialization(short)
PartialSpecialization(float)


template <class T, class U>
class SerializeHelper{};

template  <class T>
class SerializeHelper<T, HasOwnSerializeInterface>
{
public:
    static void SerializeImplement(T& obj)
    {
        obj.Serialize();
    }
};


template  <class T>
class SerializeHelper<T, HasNoSerializeInterface>
{
public:
    static void SerializeImplement(T& obj)
    {
        cout << "use defualt serialize" << endl;
    }
};


template <class T>
void Serialize(T& obj)
{
    typedef  typename  Trait<T>::SerializeInterface SerializeInterface;
    SerializeHelper<T, SerializeInterface>::SerializeImplement(obj);
}

