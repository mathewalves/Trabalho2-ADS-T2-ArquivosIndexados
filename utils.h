#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>

using namespace std;

inline void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

inline void aguardarEnter() {
    cout << "\nPressione Enter para continuar...";
    cin.ignore();
    cin.get();
}

#endif // UTILS_H