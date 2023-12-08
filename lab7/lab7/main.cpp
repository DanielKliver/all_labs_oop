#include <iostream>

#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

void cnt()
{
    LinkedList::cnt();
    Stack::cnt();
    Queue::cnt();
}

int main()
{
    cnt();

    Queue *q = new Queue;

    for (int i = 0; i < 3; i++)
    {
        q->push(i);
    }
    q->print();
    for (int i = 0; i < 4; i++)
    {
        q->pop();
    }
    q->print();
    cnt();

    Stack *s = new Stack;
    for (int i = 0; i < 3; i++)
    {
        s->push(i);
    }
    s->print();
    for (int i = 0; i < 4; i++)
    {
        s->pop();
    }
    s->print();
    cnt();

    LinkedList *l = new LinkedList;
    for (int i = 0; i < 3; i++)
    {
        l->push(i);
    }
    l->print();
    for (int i = 0; i < 4; i++)
    {
        l->pop();
    }
    l->print();
    cnt();

    delete q;
    delete s;
    delete l;

    cnt();
}