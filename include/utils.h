#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif

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

inline void configurarLocale() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    setlocale(LC_ALL, "pt_BR.UTF-8");
}

#endif // UTILS_H