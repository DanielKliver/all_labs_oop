#include "Queue.hpp"

int Queue::countqueue = 0;

Queue::Queue()
{
    LinkedList::count--;
    Queue::countqueue++;
}

Queue::Queue(int data) : LinkedList(data)
{
    LinkedList::count--;
    Queue::countqueue++;
}

Queue::~Queue()
{
    LinkedList::count++;
     Queue::countqueue--;
}

void Queue::cnt()
{
    std::cout << "Count of instances Queue: " << Queue::countqueue << '\n';
}

void Queue::pop()
{
    try
    {
        if (this->first == nullptr)
        {
            throw std::string("Queue is empty");
        }
        
        Node * next = this->last->prev;

        delete this->last;

        if (next != nullptr)
            next->next = nullptr;
        else
            this->first = next;
        if(this->size == 2)
            this->first = next;

        this->last = next;
        this->size--;
    }
    catch(const std::string& s)
    {
        std::cout << s << '\n';
    }
}