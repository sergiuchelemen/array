#include <iostream>
#include "Array.h"
#include "SortArray.h"
#include "Permutare.h"
#include "Matrix.h"
#include "Polinom.h"
using namespace std;




int main()
{    
    Term<int> term(1, 2);
    Term<int> term2(3, 3);
    Term<int> term3(4, 5);
    Term<int> term4(2, 6);

    Polinom<int> polinom;
    Polinom<int> polinom2;

    polinom2 + term + term2 + 2;
    polinom.addTerm(term);
    polinom.addTerm(term2);
    polinom.addTerm(term3);

    polinom - 2;
    polinom.afisare();

    cout << "Gradul polinomului este " << polinom.grad << '\n';

    int eval = polinom.evaluate(2);
    cout << eval;
    return 0;
}

// 1^2 + 3^3 + 4^5
// 1^2 + 3^3

// 1^4 + 3^5 + 4^7

// 3^7 + 9^8 + 12^10

// 28  128  226



