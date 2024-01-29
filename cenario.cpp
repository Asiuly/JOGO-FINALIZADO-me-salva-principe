#include "cenario.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

//inicializando a descrição que aparecerá no gráfico do cenário
Cenario:: Cenario(string descricao): descricao(descricao) { }


//adiciona uma opção que será inserida em uma caixa de seleção para o jogador
void Cenario:: addOpcao(string opcao){
    opcoes.push_back(opcao);
}

//no momento, está sendo realizada lógica da escolha com numeros, mas após a parte
//gráfica ser implementada, vai captar a escolha do usuário e retornar
string Cenario:: captarEscolha(int escolha){
    while(escolha <= 0 || escolha > opcoes.size()){
        cout << "\n============================================================================================================\nEscolha invalida! Por favor, escolha um numero entre 1 e " << opcoes.size() << ".\n============================================================================================================\n" << endl;
        cin >> escolha;
    }
    return opcoes[escolha-1];
}

//aleatoriza um elemento para gerar monstros e medalhas
Elemento Cenario:: aleatorizarElemento() const{
    srand(static_cast<int>(time(nullptr)));
    int numeroSorteado = rand() % 4 + 1;
    Elemento elemento;


    if(numeroSorteado==1)
        elemento = AR;
    else if(numeroSorteado==2)
        elemento = GRAMA;
    else if(numeroSorteado==3)
        elemento = AGUA;
    else
        elemento = FOGO;


    return elemento;
}


//retorna descrição do cenario
string Cenario:: getDescricao() const{
    return descricao;
}


//Utilizado para monitorar a estrutura de nós de cenários com next
void Cenario:: setCaminho(Cenario* proximoCenario, int direcao){
    if(direcao == 1)
        dir = proximoCenario;
    else if(direcao == 2)
        esq = proximoCenario;
    else{ // Cenário com caminho único (Exemplo: sala de monstro só vai para a de passagem)
        dir = proximoCenario;
        esq = proximoCenario;
    }
}


//retorna o proximo cenario
Cenario* Cenario:: getCaminho(int direcao) const{

    if(direcao == 1)
        return dir;
    else
        return esq;
}

void Cenario:: exibirMorte() const{
    cout <<
        ".                                                          .\n"
        ".                      FIM DO JOGO                         .\n"
        ".                                                          .\n"
        ".                       ______                             .\n"
        ".                    .-\"      \"-.                        .\n"
        ".                   /            \\                        .\n"
        ".       _          |              |          _             .\n"
        ".      ( \\         |,  .-.  .-.  ,|         / )           .\n"
        ".       > \"=._     | )(__/  \\__)( |     _.=\" <          .\n"
        ".      (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)     .\n"
        ".             \"=._ (_     ^^     _)\"_.=\"                .\n"
        ".                 \"=\\__|IIIIII|__/=\"                    .\n"
        ".                _.=\"| \\IIIIII/ |\"=._                   .\n"
        ".      _     _.=\"_.=\"\\          /\"=._\"=._     _       .\n"
        ".     ( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )      .\n"
        ".      > _.=\"                            \"=._ <          .\n"
        ".     (_/                                    \\_)          .\n";
}