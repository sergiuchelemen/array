
#include <iostream>
#include "Array.h"
#include "SortArray.h"
using namespace std;



int main()
{
    SortArray<int> b(0, 10);
    SortArray<int> c(0, 10);
    SortArray<int> d(0, 10);
    for (int i = 0; i < b.getLength(); ++i) {
        b[i] = 2 * i;
        c[i] = i;
        d[i] = 3 * i;
    }

    b.visit(f);
    c.visit(f);
    b = b + c;
    b.visit(f);

    return 0;
}