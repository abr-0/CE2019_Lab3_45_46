#pragma once

#include "../../abstractBST.hpp"

#define MAX_NODES 16

struct ArrayNode
{
    int key;
    char value;

    ArrayNode(int key, char value) : key(key), value(value) {}
};

class ArrayBST:public AbstractBST{
private:
    ArrayNode *nodes[MAX_NODES];
public:
    ArrayBST();
    ~ArrayBST();

    bool isEmpty() const;
    void addBST(int key, char value);
    void arrangeBST(int tempRoot);
    void removeBST(int key);
    bool searchBST(int key) const;
    void display() const;
};