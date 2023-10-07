
#include <iostream>
#include "Array.h"
#include "SortArray.h"
#include "Permutare.h"
using namespace std;



int main()
{
    SortArray<unsigned int> b(0, 10);
    for (int i = 0; i < b.getLength(); ++i) {
        b[i] = 2 * i;
    }

    
    Permutare p(6);
    Permutare c(10);
    p.setReverse();
    c = p;
    p.setReverse();
    c.getData();
    return 0;
}