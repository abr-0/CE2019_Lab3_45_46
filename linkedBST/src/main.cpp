#include<iostream>
#include "linkedBST.h"
using namespace std;

int main()
{
    linkedBST test;

    test.addBST(30,30);
    test.addBST(40,40);
    test.addBST(20,20);
    test.addBST(5,5);
    test.addBST(88,88);
    test.addBST(59,59);
    test.addBST(23,23);
    test.addBST(12,12);

    test.addBST(10,10);
    std::cout<<"BST inorder traversal"<<std::endl;
    test.inorder();
    test.removeBST(40);

    test.removeBST(10);
    std::cout<<"After removal:"<<std::endl;
    test.inorder();

    int min_value;
    test.min(min_value);
    std::cout<<"The minium value in BST is:"<<min_value<<std::endl;

    int max_value;
    test.max(max_value);
    std::cout<<"The maximum value in BST is:"<<max_value<<std::endl;
    
    std::cout<<"Checking Existence of key:"<<test.exists(5)<<std::endl;
}