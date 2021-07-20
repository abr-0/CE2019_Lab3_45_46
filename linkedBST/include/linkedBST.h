#ifndef BST_h
#define BST_h

#include "../../abstractBST.hpp"
#include<iostream>
using namespace std;

class Node {
    public:
    int key;
    char data;
    Node *left;
    Node *right;

     Node():left(nullptr){}
     //Node():right(nullptr){}
    Node(int key,char data, Node *left, Node *right):key(key),data(data),left(left),right(right){}
};

class linkedBST : public AbstractBST {
    public:
    linkedBST();

    bool isEmpty() const;
    void addBST(int key, char data);
    
    void max(int &output);
    void min(int &output);
    
    bool searchBST(int key) const;
    void removeBST(int key);

    void inorder();
    
    private:
    Node *root;
    
    void addBST(Node *subroot, Node *newNode);

    void inorder(Node *node, char sep = ' ');
};
#endif 
