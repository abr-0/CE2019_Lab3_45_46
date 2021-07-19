#include <iostream>
#include "arrayBSTdec.hpp"

using std::cout;
using std::endl;

int main(){
    ArrayBST a1;
    cout << "isEmpty: " << a1.isEmpty() << endl;

    a1.addBST(5, 'A');
    a1.addBST(3, 'B');
    a1.addBST(8, 'C');
    a1.addBST(2, 'D');
    a1.addBST(9, 'E');
    a1.addBST(4, 'F');

    // a1.removeBST(2);
    // a1.removeBST(8);
    a1.removeBST(3);
    
    cout << "searchBST: " << a1.searchBST(8) << endl;
    cout << "isEmpty: " << a1.isEmpty() << endl;
    a1.display();
    return 0;
}