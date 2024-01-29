#ifndef CENARIOARMADILHA_H
#define CENARIOARMADILHA_H
#include "cenario.h"

class CenarioArmadilha: public Cenario{
    private: 
        int armadilha;
    public:
        CenarioArmadilha();
        void exibirGrafico() const override;
        string getCategoria() const override;
        ~CenarioArmadilha() { };
};

#endif