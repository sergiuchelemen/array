#include <iostream>
#include "Array.h"
#include "SortArray.h"
#include "Permutare.h"
#include "SMatrix.h"
#include "Polinom.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;




int main()
{    
    QueueAsArray<int> coada(3);
    for (int i = 0; i < 4; ++i) {
        coada.enQueue(i);
    }
    
    cout << coada << '\n';
    cout << coada.head << " " << coada.tail;
    return 0;
}






