#pragma once

struct Node
{
    Node * next;
    Node * prev;
    int data;

    Node() : data(0), next(nullptr), prev(nullptr) {}

    Node(int data, Node * next, Node * prev) : data(data), next(next), prev(prev) {}

    ~Node() {};
};