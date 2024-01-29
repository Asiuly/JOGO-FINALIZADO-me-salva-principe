#include "cenarioMonstro.h"
#include <iostream>

using namespace std;

CenarioMonstro:: CenarioMonstro(): Cenario("============================================================================================================\nOh Nao! Voce nao ouviu os barulhos? Acabou de entrar em uma sala com um monstro!\nPara enfrenta-lo, precisa o atacar com seu elemento oposto! Escolha um Elemento para combater o monstro:\n============================================================================================================") { 
    addOpcao("AGUA");
    addOpcao("FOGO");
    addOpcao("GRAMA");
    addOpcao("AR");
}

//cria um monstro para o cenario com um elemento de parametro
void CenarioMonstro:: addMonstro(){
    Elemento elemento = aleatorizarElemento();
    monstro = new Monstro(elemento);
}

Monstro CenarioMonstro:: getMonstro() const{
    return *monstro;
}

void CenarioMonstro:: exeMonstro(Jogador* jogador, string* opcaoEscolhida){
    //JOGADOR ESCOLHE ELEMENTO
    int escolhaDoJogador;
    cin >> escolhaDoJogador;
    *opcaoEscolhida = captarEscolha(escolhaDoJogador);

    //BATALHA DEFINE VITÓRIA OU DERROTA DE ACORDO COM OPÇÃO DO PLAYER
    jogador->batalhar(*monstro, *opcaoEscolhida);
}

void CenarioMonstro:: exibirGrafico() const{
    monstro->exibirMonstro();
}

string CenarioMonstro::getCategoria() const{
    return "Monstro";
}
