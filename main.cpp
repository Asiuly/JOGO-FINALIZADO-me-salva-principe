#include "jogador.h"
#include "cenario.h"
#include "cenarioMonstro.h"
#include "cenarioArmadilha.h"
#include "cenarioBau.h"
#include "cenarioMortal.h"
#include "cenarioPrincesa.h"
#include "cenarioPassagem.h"
#include "cenarioEntrada.h"
#include <iostream>
#include <string>
#include <windows.h> 
#include <vector>

using namespace std;

int main() {
    // ---------------------------- CONSTRUÇÃO DO JOGO -------------------------------------
    // -- DEFININDO CENARIOS DE ACORDO COM ORDEM DO DOCUMENTO --
    string opcaoEscolhida;
    int escolhaDoJogador;
    
    CenarioEntrada cenarioEntrada;

    CenarioMonstro cenarioMonstro;

    CenarioBau cenarioBau;

    CenarioPassagem cenarioPassagem;

    CenarioMortal cenarioMortal;

    CenarioArmadilha cenarioArmadilha;

    CenarioPrincesa cenarioPrincesa;
    // -- DEFININDO CENARIOS DE ACORDO COM ORDEM DO DOCUMENTO --

    // -- ADICIONANDO OS CAMINHOS DOS CENÁRIOS --
    cenarioEntrada.setCaminho(&cenarioBau, 1);
    cenarioEntrada.setCaminho(&cenarioMonstro, 2);
    
    //MONSTRO TENDO ELEMENTO ALEATORIZADO
    cenarioMonstro.addMonstro();

    cenarioBau.setCaminho(&cenarioPassagem, 3);
    cenarioMonstro.setCaminho(&cenarioPassagem, 3);
    cenarioArmadilha.setCaminho(&cenarioPassagem, 3);
    cenarioMortal.setCaminho(&cenarioEntrada, 3); // RECOMEÇA O JOGO

    // -- ADICIONANDO OS CAMINHOS DOS CENÁRIOS --

    // ---------------------------- EXECUÇÃO DO JOGO -------------------------------------

    // Criação e posicionamento do jogador.
    Jogador jogador(3, &cenarioEntrada);
    
    jogador.seguirJornada(&opcaoEscolhida);

    if(opcaoEscolhida == "ESQUERDA"){
        // Ao ir para a esquerda, jogador se depara com um monstro.
        cenarioMonstro.exeMonstro(&jogador, &opcaoEscolhida);
    }
    else{
        cin >> escolhaDoJogador;
        opcaoEscolhida = jogador.getCenarioAtual()->captarEscolha(escolhaDoJogador);
        int resultadoBau; // Caso saia um monstro
       
        // Aleatorização do conteúdo do baú
        cout << cenarioBau.addBau(opcaoEscolhida, jogador, &resultadoBau) << endl;

        // Caso o conteúdo seja um monstro.
        if(resultadoBau == 5){
            // Adiciona um novo monstro e leva o jogador a ele.
            cenarioMonstro.addMonstro();
            cenarioBau.setCaminho(&cenarioMonstro, 3);
            jogador.setCenarioAtual("unico");
            
            // Luta contra o monstro
            jogador.getCenarioAtual()->exibirGrafico();
            cenarioMonstro.exeMonstro(&jogador, &opcaoEscolhida);
        }
    }

    // ---------------------------- MANUTENCAO ------------------------------------- //
    // Verificando fim do jogo.
    if(jogador.getVidas() == 0){
        jogador.executarMorte();
        return 0;
    }

    // Mudando cenário de passagem.
    cenarioPassagem.setCaminho(&cenarioMonstro, 1);
    cenarioMonstro.addMonstro();

    cenarioPassagem.setCaminho(&cenarioArmadilha, 2);
    jogador.seguirJornada(&opcaoEscolhida);
    // ---------------------------- MANUTENCAO ------------------------------------- //

    if(opcaoEscolhida == "ESQUERDA"){
        // Ao ir para a esquerda, jogador cai em uma armadilha.
        jogador.setVidas((jogador.getVidas() - 1));
    }
    else{
        // Ao ir para a direita, encontra um monstro.
        cenarioMonstro.exeMonstro(&jogador, &opcaoEscolhida);
    }

    // ---------------------------- MANUTENCAO -------------------------------------
    // Verificando fim do jogo.
    if(jogador.getVidas() == 0){
        jogador.executarMorte();
        return 0;
    }

    // Mudando cenário de passagem
    cenarioPassagem.setCaminho(&cenarioMortal, 1);
    cenarioPassagem.setCaminho(&cenarioBau, 2);
    jogador.seguirJornada(&opcaoEscolhida);
    // ---------------------------- MANUTENCAO -------------------------------------

    if(opcaoEscolhida == "ESQUERDA"){
        // Decisão de abrir o baú
        cin >> escolhaDoJogador;
        opcaoEscolhida = jogador.getCenarioAtual()->captarEscolha(escolhaDoJogador);
        int resultadoBau; // Caso saia um monstro
       
        // Aleatorização do conteúdo do baú
        cout << cenarioBau.addBau(opcaoEscolhida, jogador, &resultadoBau) << endl;
 
        // Caso o conteúdo seja um monstro.
        if(resultadoBau == 5){
            // Adiciona um novo monstro e leva o jogador a ele.
            cenarioMonstro.addMonstro();
            cenarioBau.setCaminho(&cenarioMonstro, 3);
            jogador.setCenarioAtual("unico");
            
            // Luta contra o monstro
            jogador.getCenarioAtual()->exibirGrafico();
            cenarioMonstro.exeMonstro(&jogador, &opcaoEscolhida);
        }
    }
    else{
        // Ao ir para a direita, jogador cai em uma armadilha mortal
        cenarioMortal.addBuraco(jogador);
        return 0;
    }

    // ---------------------------- MANUTENCAO ------------------------------------- //
    // Verificando fim do jogo.
    if(jogador.getVidas() == 0){
        jogador.executarMorte();
        return 0;
    }

    // Mudando cenário de passagem.
    cenarioPassagem.setCaminho(&cenarioArmadilha, 1);
    cenarioPassagem.setCaminho(&cenarioMonstro, 2);
    // Aleatorizando elemento do monstro.
    cenarioMonstro.addMonstro();

    jogador.seguirJornada(&opcaoEscolhida);
    // ---------------------------- MANUTENCAO ------------------------------------- //

    if(opcaoEscolhida == "ESQUERDA"){
        // Ao ir para a esquerda, jogador encontra um monstro.
        cenarioMonstro.exeMonstro(&jogador, &opcaoEscolhida);
    }
    else{
        // Ao ir para a direita, jogador cai em uma armadilha.
        jogador.setVidas((jogador.getVidas() - 1));
    }
    
    // ---------------------------- MANUTENCAO ------------------------------------- //
    // Verificando fim do jogo.
    if(jogador.getVidas() == 0){
        jogador.executarMorte();
        return 0;
    }

    // Editando Cenário final.
    cenarioArmadilha.setCaminho(&cenarioBau, 3);
    cenarioMonstro.setCaminho(&cenarioPrincesa, 3);
    cenarioBau.setCaminho(&cenarioPrincesa, 3);

    // Jogador anda ao próximo cenário
    jogador.setCenarioAtual("unico");
    
    Sleep(3000);
    // Descrição do cenário
    cout << jogador.getCenarioAtual()->getDescricao() << endl;
    jogador.getCenarioAtual()->exibirGrafico();
    // ---------------------------- MANUTENCAO ------------------------------------- //


    if(jogador.getCenarioAtual() == &cenarioBau){
        // Decisão de abrir o baú
        cin >> escolhaDoJogador;
        opcaoEscolhida = jogador.getCenarioAtual()->captarEscolha(escolhaDoJogador);
        int resultadoBau; // Caso saia um monstro
       
        // Aleatorização do conteúdo do baú
        cout << cenarioBau.addBau(opcaoEscolhida, jogador, &resultadoBau) << endl;

        // Caso o conteúdo seja um monstro.
        if(resultadoBau == 5){
            // Adiciona um novo monstro e leva o jogador a ele.
            cenarioMonstro.addMonstro();
            cenarioBau.setCaminho(&cenarioMonstro, 3);
            jogador.setCenarioAtual("unico");
            
            // Luta contra o monstro
            jogador.getCenarioAtual()->exibirGrafico();
            cenarioMonstro.exeMonstro(&jogador, &opcaoEscolhida);
        }
        
        // ---------------------------- MANUTENCAO ------------------------------------- //
        // Verificando fim do jogo.
        if(jogador.getVidas() == 0){
            jogador.executarMorte();
            return 0;
        }

        // Jogador anda ao próximo cenário
        jogador.setCenarioAtual("unico");
        // Descrição do cenário
        jogador.getCenarioAtual()->exibirGrafico();
        cout << jogador.getCenarioAtual()->getDescricao() << endl;
        // ---------------------------- MANUTENCAO ------------------------------------- //
    }

    // Fim
    jogador.exibirMedalhasAcessorios();
    // ---------------------------- EXECUÇÃO DO JOGO -------------------------------------

    return 0;
}
