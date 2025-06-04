#include "interface.h"
#include <stdio.h>

#include <windows.h>

int main() {

    SetConsoleOutputCP(65001);  // saída (printf)
    SetConsoleCP(65001);        // entrada (scanf)

    exibirMenu();
    return 0;
}
