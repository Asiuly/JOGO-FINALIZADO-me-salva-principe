#ifndef CENARIO_H
#define CENARIO_H
#include "jogador.h"
#include "monstro.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;


class Cenario {
    private:
        string descricao; //descrição do cenario
        vector<string> opcoes; //opções para o player selecionar
        Cenario* dir; // Opção 1
        Cenario* esq; // Opção 2

    public: //funções explicadas no arquivo cpp
        Cenario(string);
        void addOpcao(string);
        void setCaminho(Cenario*, int);
        Cenario* getCaminho(int) const;
        string captarEscolha(int);
        Elemento aleatorizarElemento() const;
        string getDescricao() const;
        virtual string getCategoria() const = 0;
        virtual void exibirGrafico() const = 0;
        void exibirMorte() const;
       
        virtual ~Cenario() = default;
};


#endif