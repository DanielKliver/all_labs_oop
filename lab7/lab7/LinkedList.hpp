#pragma once

#include <iostream>
#include <string>

#include "Node.hpp"

class LinkedList
{
protected:
    static int count;
    Node *first;
    Node *last;
    size_t size;

public:
    LinkedList();

    LinkedList(int data);

    virtual ~LinkedList();

    static void cnt();

    void print();

    virtual void push(int data);

    virtual void pop();

    inline size_t length() { return this->size; }
};
