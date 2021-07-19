#include <iostream>
#include "arrayBSTdec.hpp"

using std::cout;
using std::endl;

ArrayBST::ArrayBST(){
    for (size_t i = 0; i < MAX_NODES; ++i)
    {
        // initilize all nodes to null
        nodes[i] = NULL;
    }
}

ArrayBST::~ArrayBST(){}

bool ArrayBST::isEmpty() const{
    // check if root node exists
    return this->nodes[1] == NULL;
}

void ArrayBST::addBST(int key, char value){
    ArrayNode* newData(new ArrayNode(key, value));
    // add node in root or left or right sub tree
    // evaluating on the basis of key
    for (size_t i = 1; i < MAX_NODES; ) {
        ArrayNode* node = this->nodes[i];
        
        if (node == NULL) {
            this->nodes[i] = newData;
            cout << "Inserted: " << nodes[i]->value << endl;
            break;
        } else if (node->key < key) {
            i = 2 * i + 1;
        } else {
            i = 2 * i;
        }
    }
}

void ArrayBST::arrangeBST(int tempRoot){
    int pTemp =  tempRoot/2;
    nodes[pTemp] = nodes[tempRoot];
    nodes[tempRoot] = NULL;
    if (nodes[tempRoot*2] != NULL)
    {
        arrangeBST(tempRoot*2);
    }
    if (nodes[tempRoot*2+1] != NULL)
    {
        arrangeBST(tempRoot*2+1);
    }
}

void ArrayBST::removeBST(int key){
    if (searchBST(key))
    {
        int temp = 1;
        while (nodes[temp] != NULL && nodes[temp]->key != key)
        {
            if (nodes[temp]->key > key)
            {
                temp = temp*2;
            }
            else
            {
                temp = temp*2+1;
            }
        }
        // temp gets us the parent node

        // No Child
        if (nodes[temp*2] == NULL && nodes[temp*2+1] == NULL)
        {
            nodes[temp] = NULL;
        }
        // One Child
        else if (nodes[temp*2] == NULL || nodes[temp*2+1] == NULL)
        {
            if (nodes[temp*2] != NULL)
            {
                arrangeBST(temp*2);
            }
            else
            {
                arrangeBST(temp*2+1);
            }
        }
        // Two Children
        else
        {
            int smallRight = temp*2+1;
            while (nodes[smallRight] != NULL){
                smallRight = smallRight*2;
            }
            nodes[temp] = nodes[smallRight];
            if (nodes[smallRight*2+1]==NULL)
            {
                nodes[smallRight]=NULL;
            }
            else
            {
                arrangeBST(smallRight*2+1);
            }
        }
        
    }
}

bool ArrayBST::searchBST(int key) const{
    // returns 1 for true i.e. if a node with provided key exists
    // returns 0 for no match found
    for (size_t i = 1; i < MAX_NODES; ){
        ArrayNode* node = this->nodes[i];
        if (node == NULL) {
            break;
        } else if (node->key == key) {
            return true;
        } else if (node->key < key) {
            i = 2 * i + 1;
        } else {
            i = 2 * i;
        }
    }
    return false;
}

// EXTRA
// for array visualization of BST
void ArrayBST::display() const{
    for (size_t i = 0; i < MAX_NODES; ++i)
    {
        if (nodes[i] != NULL)
            cout << nodes[i]->value << ",";
            // cout << nodes[i]->key << ",";
        else
            cout << nodes[i] << ",";
    }
}