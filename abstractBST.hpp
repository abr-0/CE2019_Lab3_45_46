// abstract class for Binary Search Tree
#pragma once

class AbstractBST{
public:
    virtual bool isEmpty() = 0;
    virtual bool add(int key, int value) = 0;
    virtual bool max(int &output) = 0;
    virtual bool min(int &output) = 0;
    virtual bool exists(int targetKey) = 0;
    virtual void inorder() = 0;
};