#include <iostream>
#include "arrayBSTdec.hpp"

using std::cout;
using std::endl;

ArrayBST::ArrayBST(){
    for (size_t i = 0; i < MAX_NODES; ++i)
    {
        nodes[i] = NULL;
    }
}

ArrayBST::~ArrayBST(){}

bool ArrayBST::isEmpty() const{
    return this->nodes[1] == NULL;
}

void ArrayBST::addBST(int key, char value){
    ArrayNode* newData(new ArrayNode(key, value));
    
    for (size_t i = 1; i < MAX_NODES; ) {
        ArrayNode* node = this->nodes[i];
        
        if (node == NULL) {
            this->nodes[i] = newData;
            break;
        } else if (node->key < key) {
            i = 2 * i + 1;
        } else {
            i = 2 * i;
        }
    }
}

void ArrayBST::removeBST(int key){

}

bool ArrayBST::searchBST(int key) const{
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