#include "cenarioPrincesa.h"
#include <cstdlib>
#include <ctime>
#include <windows.h> 
#include <chrono>
#include <iostream>

using namespace std;

CenarioPrincesa:: CenarioPrincesa(): Cenario("============================================================================================================\nParabens! Voce chegou ao topo da masmorra, a princesa fica muito feliz em ve-lo!\n============================================================================================================\n"){}

void CenarioPrincesa:: exibirGrafico() const{
    Sleep(4000);
    system("cls");
    cout << "============================================================================================================\nA princesa esta logo ali, aguarde!!\n============================================================================================================\n";
    Sleep(3500);
    system("cls");
    cout <<
        "                          (,);    /\\                        \n"
        "                         ((  ^_   ||            ...          \n"
        "                          ' /  \\  ||           (()))         \n"
        "                            L {=) ||           {' ())        \n"
        "                             ) -  ||            )_ (()       \n"
        "                           (_   \\====       @  (   (_)       \n"
        "                           | (___/{ }        \\7 \\ _) |       \n"
        "                            \\____\\/)          {)=== /\\       \n"
        "                            |    |             \\ |    |      \n"
        "                            |_\\/\\_|               |    |      \n"
        "                             |  |                |    |      \n"
        "                              ) )\\               |    |      \n"
        "                            _/| |/               |    |      \n"
        "                           ( ,\\ |_               '~~~~'      \n"
        "                            \\_(___)               _/Y        \n";

    Sleep(1500);
    system("cls");

    cout <<
        "                          ((  ^_.     (()))\n"
        "                           ' / /_\\    {' ())\n"
        "                             L( '}     )_ (())\n"
        "                              ) (_    (   (_)\n"
        "                            (_  / }{)===='_/\n"
        "                            | `/\\/\\     |   \\\n"
        "                            L___/ |     |    |\n"
        "                             |  . \\     |    |\n"
        "                             |_/ \\_\\    |    |\n"
        "                             ( ____ )   |    |\n"
        "                              | | | |   |    |\n"
        "                          ( --' | \\ |_  '~~~~'\n"
        "                          /_/---) (___)  _/Y\n"
        "                             H\n"
        "                     -=======H%%O   \n"
        "                             H\n";

    Sleep(1500);
    system("cls");

    cout <<
        "                                             (\\/)\n"
        "                                              \\/\n"
        "\n"
        "                                        (,);\n"
        "                                       ((  ^_.  ... \n"
        "                                        ' / /_\\(()))\n"
        "                                          L( '}{' ())\n"
        "                                          ) (   )_ (())\n"
        "                                        (_   \\ (   (_)\n"
        "                                        | (__'__\\_) |\n"
        "                                         \\___|_(}==/ \\\n"
        "                                         |    |  |    |\n"
        "                                         |_/\\_|  |    |\n"
        "                                          |  |   |    |\n"
        "                                           ) )\\  |    |\n"
        "                                         _/| |/  |    \\\n"
        "                                        ( ,\\ |_  '~~~~/7\n"
        "                                         \\_(___)  _/Y\n"
        "                                      H\n"
        "                              -=======H%%O \n";
    Sleep(1500);
    system("cls");
    cout<< "FIM DO JOGO\n\n";

}

string CenarioPrincesa::getCategoria() const{
    return "Princesa";
}