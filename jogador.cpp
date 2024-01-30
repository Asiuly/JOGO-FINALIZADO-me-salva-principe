#include "jogador.h"
#include "cenario.h"
#include "monstro.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h> 
using namespace std;


//inicializa o jogador com um numero de vidas e no cecnario de entrada criado na main(onde estamos monitorando os cenarios)
Jogador:: Jogador(int numVidas, Cenario* cenarioEntrada): vidas(numVidas), cenarioAtual(cenarioEntrada) {}


//adiciona uma medalha à coleção do player
void Jogador:: addMedalha(Elemento elemento){
    Medalha medalha;
    medalha.elemento = elemento;
    medalhas.push_back(medalha);
}


//retorna todas as medalhas do player
vector<Medalha> Jogador:: getMedalhas() const{
    return medalhas;
}


//retorna o número de vidas restantes
int Jogador:: getVidas() const{
    return vidas;
}


//de acordo com a opção do jogador, verifica se o monstro será derrotado
bool Jogador:: batalhar(Monstro monstro1, string opcaoCenarioBatalha){
    Elemento elementoEscolhido;
    if (opcaoCenarioBatalha == "AGUA")
        elementoEscolhido = AGUA;
    else if(opcaoCenarioBatalha == "FOGO")
        elementoEscolhido = FOGO;
    else if(opcaoCenarioBatalha == "AR")
        elementoEscolhido = AR;
    else
        elementoEscolhido = GRAMA;
    //convertendo string para elemento
    if(elementoEscolhido == monstro1.fraqueza){
        cout << "\n============================================================================================================\nMuito bem! Parece que voce entende de elementos! Aqui esta uma medalha por sua bela conquista!\nA princesa ficara orgulhosa, pode prosseguir seu caminho em paz\n============================================================================================================\n" << endl;
        addMedalha(monstro1.elemento);
        return true;
        //derrotou o monstro ganhou a medalha
    }
    else{
        cout << "\n============================================================================================================\nNaoo! Parece que voce se confundiu ao atacar os elementos, Ninguem ira ficar sabendo dessa falha.\nVoce perdeu uma vida!\n============================================================================================================" << endl;


        if(this->vidas>1){
            cout << "\n============================================================================================================\nParece que voce deu sorte dessa vez! Escapou do elementar por pouco! \nFuja dessa sala imediatamente e esconda esse fracasso… Boa sorte da proxima vez!\n============================================================================================================\n" << endl;
        }
        else{
            cout << "\n============================================================================================================\nParece que esse elementar era mais do que voce podia lidar, infelizmente sua jornada de heroi acaba aqui!\n============================================================================================================\n" << endl;//jogador morre se tiver apenas 1 vida
        }
        
        this->vidas -= 1;
       
        return false;
    }
}


void Jogador:: executarMorte(){
    getCenarioAtual()->exibirMorte();
    cout << "\n============================================================================================================\nO jogo acabou, voce perdeu! Suas vidas acabaram nao ha mais chances para voce, aqui esta seu legado:\n============================================================================================================\n" << endl;
    vidas = 0;
    exibirMedalhasAcessorios();
}


//passa para o proximo cenario pré-definido
void Jogador:: setCenarioAtual(string sdirecao){
    int direcao = 0;
    if(sdirecao == "ESQUERDA")
        direcao = 2;
    else if(sdirecao == "DIREITA")
        direcao = 1;
    cenarioAtual = this->getCenarioAtual()->getCaminho(direcao);
}


//retorna o cenário atual do jogador
Cenario* Jogador:: getCenarioAtual() const{
    return cenarioAtual;
}


//atualiza quantidade de vidas
void Jogador:: setVidas(int vida) {
    this->vidas = vida;
}


//adiciona um acessório à coleção do jogador
void Jogador:: addAcessorio(string cor){
    Acessorio acessorio;
    acessorio.cor = cor;


    acessorios.push_back(acessorio);
}


//retorna todos os acessórios adquiridos pelo player
vector<Acessorio> Jogador:: getAcessorio() const{
    return acessorios;
}


//exibe o legado do jogador
void Jogador:: exibirMedalhasAcessorios() const{
   
    if(medalhas.size() == 0){
        cout << "medalhas: 0" << endl;
    }
    else{
        cout << "MEDALHAS" << endl;
        for(int i=0; i<medalhas.size(); i++){
            if(medalhas[i].elemento==FOGO){
                cout <<
        "    \\@@@@|     |####/\n"
        "     \\@@@|     |###/\n"
        "      `@@|_____|##'\n"
        "           (O)\n"
        "        .-'''''-.\n"
        "      .'  * * *  `.\n"
        "     :  *       *  :\n"
        "    : ~  F O G O   ~ :\n"
        "    : ~  F I R E ~ :\n"
        "     :  *       *  :\n"
        "      `.  * * *  .'\n"
        "        `-.....-'\n";
            }
            else if(medalhas[i].elemento == AGUA){
                cout <<
        "    \\@@@@|     |####/\n"
        "     \\@@@|     |###/\n"
        "      `@@|_____|##'\n"
        "           (O)\n"
        "        .-'''''-.\n"
        "      .'  * * *  `.\n"
        "     :  *       *  :\n"
        "    : ~  A G U A   ~ :\n"
        "    : ~ W A T E R ~ :\n"
        "     :  *       *  :\n"
        "      `.  * * *  .'\n"
        "        `-.....-'\n";;
            }
            else if(medalhas[i].elemento == GRAMA){
                cout <<
        "    \\@@@@|     |####/\n"
        "     \\@@@|     |###/\n"
        "      `@@|_____|##'\n"
        "           (O)\n"
        "        .-'''''-.\n"
        "      .'  * * *  `.\n"
        "     :  *       *  :\n"
        "    : ~ G R A M A ~ :\n"
        "    : ~ G R A S S  ~ :\n"
        "     :  *       *  :\n"
        "      `.  * * *  .'\n"
        "        `-.....-'\n";;
            }
            else{
                cout <<
        "    \\@@@@|     |####/\n"
        "     \\@@@|     |###/\n"
        "      `@@|_____|##'\n"
        "           (O)\n"
        "        .-'''''-.\n"
        "      .'  * * *  `.\n"
        "     :  *       *  :\n"
        "    : ~   A I R   ~ :\n"
        "    : ~    A R     ~ :\n"
        "     :  *       *  :\n"
        "      `.  * * *  .'\n"
        "        `-.....-'\n";;
            }
        }
    }


    if(acessorios.size() == 0){
        cout << "acessorios: 0" << endl;
    }
    else{
        cout << "ACESSORIOS" << endl;
        for(int i=0; i<acessorios.size(); i++){
            cout << "UMA TIARA DA COR " << acessorios[i].cor << endl;
        }
    }


    cout << "VIDAS RESTANTES: " << getVidas() << endl;
}

void Jogador:: seguirJornada(string *opcaoEscolhida){
    if(getCenarioAtual()->getCaminho(1) == getCenarioAtual()->getCaminho(2)){
        //PASSA O JOGADOR PARA O PROXIMO CENARIO
        setCenarioAtual("unico");
    }
    //DESCREVE CENARIO DE PASSAGEM
    Sleep(5000);
    system("cls");
    cout << getCenarioAtual()->getDescricao() << endl;
    getCenarioAtual()->exibirGrafico();
    int escolhaDoJogador;
    cin >> escolhaDoJogador;

    //JOGADOR ESCOLHE CAMINHO
    *opcaoEscolhida = getCenarioAtual()->captarEscolha(escolhaDoJogador);

    // INDO PARA CAMINHO ESCOLHIDO
    system("cls");
    setCenarioAtual(*opcaoEscolhida);
    cout << getCenarioAtual()->getDescricao() << endl;
    getCenarioAtual()->exibirGrafico();
}