
#include <iostream>
#include "Array.h"
#include "SortArray.h"
#include "Permutare.h"
using namespace std;



int main()
{
    SortArray <int> a(0, 3);
    for (int i = a.getBase(); i < a.getLength(); ++i) {
        cin >> a.data[i];
    }

    int val = a.findValue(3);
    cout << val;
    return 0;
    
    
}

