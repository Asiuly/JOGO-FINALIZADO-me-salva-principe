#include "cenarioEntrada.h"
#include <iostream>

using namespace std;

CenarioEntrada:: CenarioEntrada(): Cenario("============================================================================================================\nVoce se ve parado na frente de uma masmorra com duas portas laterais, precisa decidir uma direcao a seguir:\n============================================================================================================\n"){
    addOpcao("ESQUERDA");
    addOpcao("DIREITA");
 }

void CenarioEntrada:: exibirGrafico() const{
    cout <<
        "   /\\                                                       /\\\n"
        "  |  |                                                      |  |\n"
        " /----\\                ME SALVA PRINCIPE!                 /----\\\n"
        "[______]           APENAS PARA OS MAIS CORAJOSOS          [______]\n"
        " |    |         _____                        _____         |    |\n"
        " |[]  |        [     ]                      [     ]        |  []|\n"
        " |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |\n"
        " |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |\n"
        " |             |     |/'    ____..____    '\\|     |             |\n"
        "  \\  []        |     |    /'    ||    '\\    |     |        []  /\n"
        "   |      []   |     |   |o     ||     o|   |     |  []       |\n"
        "   |           |  _  |   |     _||_     |   |  _  |           |\n"
        "   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |\n"
        "   |           |     |   |     (||)     |   |     |           |\n"
        "   |           |     |   |      ||      |   |     |           |\n"
        " /''           |     |   |o     ||     o|   |     |           ''\\\n"
        "[_____________[_______]--'------''------'--[_______]_____________]\n"
        "__________________________________________________________________\n"
        "|                                                                |\n"
        "|               | 1- ESQUERDA |     | 2 - DIREITA |              |\n"
        "\\______________________________________________________________//\n";

}

string CenarioEntrada::getCategoria() const{
    return "Entrada";
}