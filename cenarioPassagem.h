#ifndef CENARIOPASSAGEM_H
#define CENARIOPASSAGEM_H
#include "cenario.h"

class CenarioPassagem: public Cenario{
    public:
        CenarioPassagem();
        void exibirGrafico() const override;
        string getCategoria() const override;
        ~CenarioPassagem() { }
};

#endif