#pragma once

#include "LinkedList.hpp"

class Stack : public LinkedList
{
private:
    static int countstack;

public:
    Stack();

    Stack(int data);

    ~Stack();

    void pop();

    static void cnt();
};
