#ifndef CENARIOMONSTRO_H
#define CENARIOMONSTRO_H
#include <iostream>
#include "cenario.h"

class CenarioMonstro: public Cenario{
    private:
        Monstro* monstro;
    public:
        CenarioMonstro();
        void addMonstro();
        Monstro getMonstro() const;
        void exeMonstro(Jogador*, string*);
        void exibirGrafico() const override;
        string getCategoria() const override;
        ~CenarioMonstro() { }
};

#endif