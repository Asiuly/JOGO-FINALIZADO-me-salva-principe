#ifndef MONSTRO_H
#define MONSTRO_H
#include "jogador.h"
#include <iostream>
#include <string>

class Monstro{
    private:
        Elemento elemento;
        Elemento fraqueza;
        string descricao;

    public:
    //construtor definindo fraqueza de acordo com elemento do monstro
        Monstro(Elemento elemento);
        void exibirMonstro() const;
        ~Monstro() {}
        friend class Jogador;
};

#endif