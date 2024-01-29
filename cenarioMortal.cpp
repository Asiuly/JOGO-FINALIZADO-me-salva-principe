#include "cenarioMortal.h"
#include <iostream>

using namespace std;

CenarioMortal:: CenarioMortal(): Cenario("============================================================================================================\nNao! Que azar, voce abriu a porta e entrou sem prestar atençao, caiu em um buraco de mais de 20 metros!\nInfelizmente nenhuma vida extra e capaz de te salvar agora, sua jornada de heroi acaba aqui!\n============================================================================================================\n") { }

void CenarioMortal:: addBuraco(Jogador player){
    player.executarMorte();
}

void CenarioMortal:: exibirGrafico() const{
}

string CenarioMortal::getCategoria() const{
    return "Mortal";
}