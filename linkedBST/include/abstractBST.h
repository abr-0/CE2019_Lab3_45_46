#ifndef abstractBST_h
#define abstractBST_h


class abstractBST {
public:

    virtual bool isEmpty() = 0;
    virtual void addBST(int key, int data) = 0;
    virtual void max(int &output) = 0;
    virtual void min(int &output) = 0;
    virtual bool exists(int targetKey) = 0;
    virtual void removeBST(int key) = 0;
    virtual void inorder() = 0;
};
#endif 
