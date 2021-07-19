// abstract class for Binary Search Tree
#pragma once

class AbstractBST{
public:
    virtual bool isEmpty() const = 0;
    virtual void addBST(int key, char value) = 0;
    virtual void removeBST(int key) = 0;
    virtual bool searchBST(int key) const = 0;
};