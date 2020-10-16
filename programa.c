// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

// Constants

// Variables
char username[16];
char password[16];

// Login Auth
void authlogin(){
    int loggedin;

    // Senhas dos usuários
    char passgestor[] = "gestoruni01";
    char passeng[] = "eng01";
    char passmdo[] = "mdo01";
    char passforn[] = "forn01";

    do{
    printf("\nDigite o usuário:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    scanf(" %s", &username);
    printf("\nDigite a senha:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    scanf(" %s", &password);

    if(strcmp(passgestor,password) == 0){
        loggedin = 1;
    }
    else if(strcmp(passeng,password) == 0){
        loggedin = 1;
    }
    else if(strcmp(passmdo,password) == 0){
        loggedin = 1;
    }
    else if(strcmp(passforn,password) == 0){
        loggedin = 1;
    }
    else
        printf(ColorRed "\nSenha incorreta! Tente novamente." ResetColor);
    
    }while(loggedin != 1);
}

int main(){
    int selection;
    do{
        printf(BColorCyan "\n########################" ResetColor);
        printf(BColorCyan "\n# " BColorWhite "Alana Construções" BColorCyan "    #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Fazer login" BColorCyan "      #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Sair do programa" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n########################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);
        scanf("%d%*c", &selection);

        switch(selection){
            case 1:
                authlogin();
                break;
            case 2:
                printf(ColorRed "Saindo do programa...\n" ResetColor);
                break;
            default:
                printf(ColorRed "Opção desconhecida, digite novamente.\n" ResetColor);
                break;
        }
    }while(selection != 2);

    return 0;
}
