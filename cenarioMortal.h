#ifndef CENARIOMORTAL_H
#define CENARIOMORTAL_H
#include "cenario.h"

class CenarioMortal: public Cenario{
    public:
        CenarioMortal();
        void addBuraco(Jogador);
        void exibirGrafico() const override;
        string getCategoria() const override;
        ~CenarioMortal() { }
};

#endif