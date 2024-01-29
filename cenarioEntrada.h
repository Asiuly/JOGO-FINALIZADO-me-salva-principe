#ifndef CENARIOENTRADA_H
#define CENARIOENTRADA_H
#include "cenario.h"

class CenarioEntrada: public Cenario{
    public:
        CenarioEntrada();
        void exibirGrafico() const override;
        string getCategoria() const override;
        ~CenarioEntrada() { }

};

#endif