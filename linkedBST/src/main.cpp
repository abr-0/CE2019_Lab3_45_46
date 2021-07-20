#include<iostream>
#include "linkedBST.h"
using namespace std;

int main()
{
    linkedBST test;

    test.addBST(30,'A');
    test.addBST(40,'B');
    test.addBST(20,'C');
    test.addBST(5,'D');
    test.addBST(88,'E');
    test.addBST(59,'F');
    test.addBST(23,'G');
    test.addBST(12,'H');

    test.addBST(10,'I');
    std::cout<<"BST inorder traversal"<<std::endl;
    test.inorder();
    test.removeBST(40);

    test.removeBST(10);
    std::cout<<"After removal:"<<std::endl;
    test.inorder();

    int min_key;
    test.min(min_key);
    std::cout<<"The minium key in BST is:"<<min_key<<std::endl;

    int max_key;
    test.max(max_key);
    std::cout<<"The maximum key in BST is:"<<max_key<<std::endl;
    
    std::cout<<"Checking Existence of key:"<<test.searchBST(5)<<std::endl;
}