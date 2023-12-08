#include <exception>
#include "LinkedList.hpp"

int LinkedList::count = 0;

LinkedList::LinkedList() : first(nullptr), last(nullptr), size(0)
{
    LinkedList::count++;
}

LinkedList::LinkedList(int data) : first(new Node), last(first), size(1)
{
    this->first->data = data;
    LinkedList::count++;
}

LinkedList::~LinkedList()
{
    for (Node* node = this->first; node != nullptr; node = node->next)
    {
        delete node;
    }
    LinkedList::count--;
}


void LinkedList::cnt()
{
    std::cout << "Count of instances LinkedList: " << LinkedList::count << '\n';
}

void LinkedList::print()
{
    for (Node* node = this->first; node != nullptr; node = node->next)
    {
        std::cout << node->data << ' ';
    }
    std::cout << '\n';
}

void LinkedList::push(int data)
{
    Node *node;

    if (this->first == nullptr)
    {
        node = new Node(data, nullptr, nullptr);
        this->first = node;
        this->last = node;
    }
    else
    {
        node = new Node(data, this->first, nullptr);
        this->first->prev = node;
        this->first = node;
        if (this->size == 1)
            this->last->prev = node;
    }
    this->size++;
}

void LinkedList::pop()
{
    try
    {
        if (this->first == nullptr)
        {
            throw std::string("List is empty");
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