#ifndef CENARIOPRINCESA_H
#define CENARIOPRINCESA_H
#include "cenario.h"

class CenarioPrincesa: public Cenario{
    public:
        CenarioPrincesa();
        void exibirGrafico() const override;
        string getCategoria() const override;
        ~CenarioPrincesa() { }
};

#endif