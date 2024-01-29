#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Monstro;
class Cenario;

enum Elemento{
    AGUA,
    GRAMA,
    FOGO,
    AR
};


struct Medalha{
    Elemento elemento;
};


struct Acessorio{
    string cor;
};


class Jogador {
    private:
        int vidas; //vidas do player
        Cenario* cenarioAtual; //cenário em que o jogador se encontra
        vector<Medalha> medalhas; //medalhas elementais adquiridas
        vector<Acessorio> acessorios; //acessórios para princesa adquiridos
    public: //funções explicadas no arquivo cpp
        Jogador(int, Cenario*);
        void addMedalha(Elemento);
        int getVidas() const;
        vector<Medalha> getMedalhas() const;
        bool batalhar(Monstro, string);
        void executarMorte();
        void setCenarioAtual(string);
        Cenario* getCenarioAtual() const;
        void setVidas(int);
        void addAcessorio(string);
        vector<Acessorio> getAcessorio() const;
        void exibirMedalhasAcessorios() const;
        void seguirJornada(string*);
        ~Jogador(){}
};


#endif
