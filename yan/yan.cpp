#include <iostream>
#include <locale.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "vector";
using namespace std;
struct recepy {
    int ingridient1;
    int kol1;
    int ingridient2;
    int kol2;
};
vector <recepy> recepies;
void in() {
    recepy r;
    cout << "Enter ingridient: ";
    cin >> r.ingridient1 >> r.kol1 >> r.ingridient2 >> r.kol2;
    recepies.push_back(r);
}
recepy colIng(recepy ing) {
    recepy r;
    r.ingridient1 = 0;
    r.ingridient2 = 1;
    r.kol1 = 0;
    r.kol2 = 0;
    if (ing.ingridient1 != 0 && ing.ingridient1 != 1) {
        recepy newR = colIng(recepies[ing.ingridient1]);
        r.kol1 = newR.kol1 * ing.kol1 + r.kol1;
        r.kol2 = newR.kol2 * ing.kol1 + r.kol2;

    }
    else {
        r.kol1 = r.kol1 + ing.kol1;
    }
    if (ing.ingridient2 != 0 && ing.ingridient2 != 1) {
        recepy newR = colIng(recepies[ing.ingridient2]);
        r.kol1 = newR.kol1 * ing.kol2 + r.kol1;
        r.kol2 = newR.kol2 * ing.kol2 + r.kol2;
    }
    else {
        r.kol2 = r.kol2 + ing.kol2;
    }
    return(r);
};
recepy cont(recepy r) {
    recepy nr;
    nr.ingridient1 = 1;
    nr.ingridient2 = 0;
    nr.kol1 = 0;
    nr.kol2 = 0;
    if (r.ingridient1 != 0 and r.ingridient1 != 1) {
        recepy newR = colIng(recepies[r.ingridient1]);
        nr.kol1 = newR.kol1 * r.kol1;
        nr.kol2 = newR.kol2 * r.kol1;
    }
    else {
        nr.kol1 = r.kol1;
    }
    if (r.ingridient2 != 0 && r.ingridient2 != 1) {
        recepy newR = colIng(recepies[r.ingridient2]);
        nr.kol1 = newR.kol1 * r.kol2 + nr.kol1;
        nr.kol2 = newR.kol2 * r.kol2 + nr.kol2;
    }
    else {
        nr.kol2 = r.kol2;
    }
    return(nr);
}
/*bool m() {

};*/
int main()
{
    recepy r;
    r.ingridient1 = 0;
    recepies.push_back(r);
    r.ingridient2 = 1;
    recepies.push_back(r);
    while (true) {
        cout << "if you want write recepy enter 1. If you don't, enter 2.";
        int f;
        cin >> f;
        if (f == 1) {
            in();
        }
        else {
            cout << endl;
            break;
        }
    }
    for (int i = 2; i < recepies.size(); i++) {
        recepies[i] = cont(recepies[i]);
    }
    for (int i = 2; i < recepies.size(); i++) {
        std::cout << recepies[i].ingridient1 << " " << recepies[i].kol1 << " " << recepies[i].ingridient2 << " " << recepies[i].kol2 << endl;
    }
}

