#include "Stack.hpp"

int Stack::countstack = 0;

Stack::Stack()
{
    LinkedList::count--;
    Stack::countstack++;
}

Stack::Stack(int data) : LinkedList(data)
{
    LinkedList::count--;
    Stack::countstack++;
}

Stack::~Stack()
{
    LinkedList::count++;
    Stack::countstack--;
}

void Stack::cnt()
{
    std::cout << "Count of instances Stack: " << Stack::countstack << '\n';
}

void Stack::pop()
{
    try
    {
        if (this->first == nullptr)
        {
            throw std::string("Stack is empty");
        }
        
        Node * next = this->first->next;

        delete this->first;

        if (next != nullptr)
            next->prev = nullptr;
        else
            this->last = next;
        if(this->size == 2)
            this->last = next;

        this->first = next;
        this->size--;
    }
    catch(const std::string& s)
    {
        std::cout << s << '\n';
    }
}