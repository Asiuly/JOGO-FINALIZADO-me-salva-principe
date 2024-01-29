#include "cenarioBau.h"
#include <iostream>
#include <ctime>
#include <windows.h> 

using namespace std;

CenarioBau:: CenarioBau(): Cenario ("============================================================================================================\nQue sorte! Voce encontra um bau do tesouro! Uma caixa arredondada com detalhes dourados ao lado.\n Isso seria uma armadilha? Deseja abrir o bau?\n============================================================================================================\n>") {
    addOpcao("IGNORAR");
    addOpcao("ABRIR");
 }

string CenarioBau:: addBau(string escolhaDoJogador, Jogador &player, int* resultado){
    //bau encontrado

    if(escolhaDoJogador=="IGNORAR"){
        *resultado = 0;
        return "\n============================================================================================================\nAlguns nao nasceram com a coragem suficiente para olhar dentro de um bau! Tudo bem, continue sua jornada\nNinguem ficara sabendo desse seu ato de covardia…\n============================================================================================================\n";
    }
    else{
        exibirBauAberto();
        //sortear um numero de 1 a 5 para o jogador receber sua recompensa
        srand(static_cast<int>(time(nullptr)));
        int numeroSorteado = rand() % 5 + 1;
        *resultado = numeroSorteado; //monitorar se apareceu um monstro


        //vida extra
        if(numeroSorteado==1){
            player.setVidas((player.getVidas() + 1));
            return "\n============================================================================================================\nParabens, acaba de ganhar uma vida extra! Parece que a sorte esta com voce, continue sua jornada!.\n============================================================================================================\n";
        }
        //acessório azul
        else if(numeroSorteado==2){
            string cor = "azul";
            player.addAcessorio(cor);
            return "\n============================================================================================================\nUau! Que acessorio lindo! Com certeza a princesa ira gostar! Voce acaba de achar uma tiara azul\nPodera ve-la na princesa se chegar ao topo da masmorra!\n============================================================================================================\n";
        }
        //acessório rosa
        else if(numeroSorteado == 3){
            string cor = "rosa";
            player.addAcessorio(cor);
            return "\n============================================================================================================\nUau! Que acessorio lindo! Com certeza a princesa ira gostar! Voce acaba de achar uma tiara rosa\nPodera ve-la na princesa se chegar ao topo da masmorra!\n============================================================================================================\n";
        }
        //medalha de um elemento aleatório
        else if(numeroSorteado==4){
            Elemento elemento = aleatorizarElemento();


            player.addMedalha(elemento);
            return "\n============================================================================================================\nAHAHAHA, que sorte! Agora voce pode se exibir para a princesa..Apenas eu e voce saberemos\nque voce nao matou esse monstro.. Parabens pela medalha!\n============================================================================================================\n";
        }
        //vai começar uma batalha contra um monstro
        else{
            return "\n============================================================================================================\nQue azar!! Parece que a sorte nao esta com voce, esse bau estava aprisionando um monstro! Boa sorte guerreiro!\n============================================================================================================";
        }
    }
}

void CenarioBau:: exibirGrafico() const{
    cout <<
        " _________________________________________\n"
        "/                                         \\\n"
        "|               Sala do Tesouro             |\n"
        "|                                           |\n"
        "|          ____...------------...____       |\n"
        "|     .-`-/o/__ ____ __ __  __ \\o\\_--._     |\n"
        "|   .'    / /                    \\ \\    '.  |\n"
        "|   |====/o/======================\\o\\====|  |\n"
        "|   |___/_/________..____..________\\_\\___|  |\n"
        "|   /  _/ \\_     <_o#\\__/#o_>     _/ \\_  \\  |\n"
        "|         \\_________\\####/_________/        |\n"
        "|   |===\\!/========================\\!/===|  |\n"
        "|   |   |=|          .---.         |=|   |  |\n"
        "|   |===|o|=========/     \\========|o|===|  |\n"
        "|   |   | |         \\() ()/        | |   |  |\n"
        "|   |===|o|======{'-.) A (.-'}=====|o|===|  |\n"
        "|   | __/ \\__     '-. uuu/.-'    __/ \\__ |  |\n"
        "|   |        |==== .'.'^'.'.====|        |  |\n"
        "|   |  _\\o/   __  {.' __  '.} _   _\\o/  _|  |\n"
        "|   `====================================`  |\n"
        "|                                           |\n"
        "|      | 1- IGNORAR |     | 2 - ABRIR |     |\n"
        "|                                           |\n"
        "\\__________________________________________//\n";
}

void CenarioBau:: exibirBauAberto() const{
    Sleep(1000);
    cout <<
        " _________________________________________\n"
        "/                                         \\\n"
        "|              BAÚ ABERTO!!               |\n"
        "|                                         |\n"
        "|               __________                |\n"
        "|              /\\____;;___\\               |\n"
        "|             | /         /               |\n"
        "|             `. ())oo() .                |\n"
        "|              |\\(%()*^^()^\\              |\n"
        "|             %| |-%-------|              |\n"
        "|            % \\ | %  ))   |              |\n"
        "|            %  \\|%________|              |\n"
        "|                                         |\n"
        " \\_______________________________________/\n";
}

string CenarioBau::getCategoria() const{
    return "Bau";
}