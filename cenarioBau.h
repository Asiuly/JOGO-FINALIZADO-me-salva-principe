#ifndef CENARIOBAU_H
#define CENARIOBAU_H

#include "cenario.h"

class CenarioBau: public Cenario{
    public:
        CenarioBau();
        string addBau(string, Jogador &, int*);
        void exibirGrafico() const override;
        string getCategoria() const override;
        void exibirBauAberto() const;
        ~CenarioBau() { }

};  

#endif