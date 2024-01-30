#include "cenarioArmadilha.h"
#include <iostream>

using namespace std;

CenarioArmadilha:: CenarioArmadilha(): Cenario("\n============================================================================================================\nOh nao! escolha errada, voce caiu em uma armadilha e perdeu uma vida... Siga em frente sua jornada cavalheiro....\n============================================================================================================\n"){ }

void CenarioArmadilha:: exibirGrafico() const{
    cout <<
        " _____________________________________________________\n"
        "|                                                       |\n"
        "|      OH NAOO, UMA ARMADILHA!! :( -1 VIDA, CONTINUE    |\n"
        "|                                                       |\n"
        "|                         _.-'                          |\n"
        "|         _____________.-'________________________.     |\n"
        "|                /         _.-' O           /|          |\n"
        "|               /  i====_======O  _________/ /          |\n"
        "|              /  /    XX    O  /     _   /|/           |\n"
        "|             /  /   XXXX o  /     (   / /              |\n"
        "|            /  /    XXX   O  /_________/ /             |\n"
        "|           /  L===========O           /|/              |\n"
        "|          /__________________________/ /               |\n"
        "|          __________________________|/                 |\n"
        "|                                                       |\n"
        "|                                                       |\n"
        "|_______________________________________________________|\n";
}

string CenarioArmadilha::getCategoria() const{
    return "Armadilha";
}