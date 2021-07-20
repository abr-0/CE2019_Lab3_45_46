#include<iostream>
#include "linkedBST.h"

linkedBST::linkedBST() : root(nullptr) {}
// linkedBST::~linkedBST(){
//     delete root;
// }

bool linkedBST::isEmpty() const
{
    if(root == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void linkedBST::addBST(int key, char data)
{
    // Node *newNode= new Node;
    // newNode->key = key;
    // newNode->data = data;
    // newNode->left =nullptr;
    // newNode->right = nullptr;
    Node  *newNode=new Node(key, data, nullptr, nullptr);

   
    if (isEmpty())
    {
        root = newNode;
    }
    else
    {
        addBST(root, newNode);
    }
}

void linkedBST::addBST(Node *subroot, Node *newNode)
{
    
    if (subroot->key > newNode->key) {
        if (subroot->left != nullptr) {
            addBST(subroot->left, newNode);
        }
        else {
            subroot->left = newNode;
        }
    }
    else if (subroot->key < newNode->key) {
        if (subroot->right != nullptr) {
            addBST(subroot->right, newNode);
        }
        else {
            subroot->right = newNode;
        }
    }
    else
    {
        std::cout << "Duplicate key!!" << std::endl;
    }
}
void linkedBST::removeBST(int deleteKey){

        Node *curr_node=root;
        Node *prev=nullptr;

        while(curr_node!=nullptr && curr_node->key!=deleteKey)
        {
            prev=curr_node;
            if(deleteKey<curr_node->key)
            {
                curr_node=curr_node->left;
            }
            else
            {
                curr_node=curr_node->right;
            }
        }

        if(curr_node->left==nullptr || curr_node->right==nullptr)
        {
            Node *new_curr;
            if(curr_node->left==nullptr)
            {
                new_curr=curr_node->right;
            }
            else{
                new_curr=curr_node->left;
            }
            if(prev==nullptr)
            {
                delete curr_node;
            }

            if(curr_node==prev->left)
            {
                prev->left=new_curr;
            }
            else
            {
                prev->right=new_curr;
            }}
        else
        {
            Node *temp;
            Node *check=nullptr;
            temp=curr_node->right;
            while(temp->left!=nullptr)
            {
                check=temp;
                temp=temp->left;

            }
            if(check!=nullptr)
            {
                check->left=temp->right;
            }
            else{
                curr_node->right=temp->right;
            }
            curr_node->key=temp->key;
            delete temp;
        }
        



    }



void linkedBST::inorder() {

    inorder(root);

}

void linkedBST::inorder(Node *node, char sep) {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << sep<<std::endl;
        inorder(node->right);

    }
}

void linkedBST::max(int &output) {
    
    if (!this->isEmpty()) {
        Node *temp = root;
        
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        output = temp->key;
    }else {
        std::cout << "The tree is empty!" << std::endl;
    }
}

void linkedBST::min(int &output) {
    
    if (!this->isEmpty()) {
        Node *temp = root;
        
        while (temp->left!= nullptr) {
            temp = temp->left;
        }
        output = temp->key;
    } else {
        std::cout << "The tree is empty!" << std::endl;
    }
}

bool linkedBST::searchBST(int key) const{

    if (isEmpty()) 
    {
        std::cout << "The tree is empty!" << std::endl;
    } 
    else  
    {
        Node *temp = root;
        
        while (temp != nullptr) 
        {
            if (temp->key == key) 
            {
                break;

            } else if (temp->key < key) 
            {
                temp = temp->right;
            } else 
            {
                temp = temp->left;
            }
        }
    if (temp==nullptr)
    {
        return false;
    }
   
    return true;      
    }
    
}
