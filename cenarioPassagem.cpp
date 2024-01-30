#include "cenarioPassagem.h"
#include <iostream>

using namespace std;

CenarioPassagem:: CenarioPassagem(): Cenario("============================================================================================================\nUfa! Um pouco de descanso, voce se depara com uma sala de passagem, parece que voce tem 2 direcoes a seguir:\n============================================================================================================\n"){
    addOpcao("ESQUERDA");
    addOpcao("DIREITA");
}

void CenarioPassagem:: exibirGrafico() const{
    cout <<
        " ______________________________________________ \n"
        "/                                              \\\n"
        "|                SALA DE PASSAGEM               |\n"
        "|                                               |\n"
        "|         ______                 ______         |\n"
        "|      ,-' ;  ! `-.           ,-' ;  ! `-.      |\n"
        "|     / :  !  :  . \\         / :  !  :  . \\     |\n"
        "|    |_ ;   __:  ;  |       |_ ;   __:  ;  |    |\n"
        "|    )| .  :)(.  !  |       )| .  :)(.  !  |    |\n"
        "|    |    (##)  _   |       |    (##)  _   |    |\n"
        "|    |  :  ;`'  (_) (       ) (_) :  ;`' ; |    |\n"
        "|    |  :  :  .     |       |  :  :  .     |    |\n"
        "|    )_ !  ,  ;  ;  |       )_ !  ,  ;  ;  |    |\n"
        "|    || .  .  :  :  |       || .  .  :  :  |    |\n"
        "|    |; .  |  :  .  |       |; .  |  :  .  |    |\n"
        "|    |. ,._;----.___|       |. ,._;----.___|    |\n"
        "|                                               |\n"
        "|    | 1 - ESQUERDA |        | 2 - DIREITA |    |\n"
        "|                                               |\n"
        "\\_____________________________________________//\n";
}

string CenarioPassagem::getCategoria() const{
    return "Passagem";
}