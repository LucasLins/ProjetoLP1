// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

// Constants

// Variables
char password[16];

void fornecedor(){
    int selection;

    do{
        printf(BColorCyan "\n##############################################" ResetColor);
        printf(BColorCyan "\n#                 " BColorWhite "Fornecedor" BColorCyan "                 #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Visualizar chamados de compra" BColorCyan "          #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Adicionar o valor de três fornecedores" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Desconectar da conta" BColorCyan "                   #" ResetColor);
        printf(BColorCyan "\n##############################################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);
        scanf("%d", &selection);
        scanf("%*[^\n]%*c");
        system("cls || clear");

        switch(selection){
            case 1:
                break;

            case 2:
                break;

            case 3:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");
                fornecedor();   
                break;
        }
    }while(selection =! 4);
}

void mestredeobra(){
    int selection;

    do{
        printf(BColorCyan "\n#######################################" ResetColor);
        printf(BColorCyan "\n#           " BColorWhite "Mestre de Obra" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Solicitar Compra" BColorCyan "                #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Confirmar recebimento da compra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Listar compras realizadas" BColorCyan "       #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Solicitar novos funcionários" BColorCyan "    #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "5 - Desconectar da conta" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n#######################################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);
        scanf("%d", &selection);
        scanf("%*[^\n]%*c");
        system("cls || clear");

        switch(selection){
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;
            
            case 5:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");
                mestredeobra();   
                break;
        }
    }while(selection =! 5);
}


void engenheiro(){
    int selection;

    do{
        printf(BColorCyan "\n###############################" ResetColor);
        printf(BColorCyan "\n#         " BColorWhite "Engenheiro" BColorCyan "          #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Iniciar Obra" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Contratar Funcionários" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Verificar custo da obra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Selecionar fornecedor e" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "    finalizar compra" BColorCyan "        #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "5 - Adicionar mensagem de" BColorCyan "   #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "    acompanhamento da obra" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "6 - Desconectar da conta" BColorCyan "    #" ResetColor);
        printf(BColorCyan "\n###############################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);
        scanf("%d", &selection);
        scanf("%*[^\n]%*c");
        system("cls || clear");

        switch(selection){
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;
            
            case 5:
                break;
            
            case 6:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");
                engenheiro();   
                break;
        }
    }while(selection =! 6);
}

void gestor(){
    int selection;

    do{
        printf(BColorCyan "\n###################################" ResetColor);
        printf(BColorCyan "\n#          " BColorWhite "Gestor UNIESP" BColorCyan "          #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Solicitar nova Obra" BColorCyan "         #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Verificar custo da obra" BColorCyan "     #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Verificar histórico da obra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Desconectar da conta" BColorCyan "        #" ResetColor);
        printf(BColorCyan "\n###################################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);
        scanf("%d", &selection);
        scanf("%*[^\n]%*c");
        system("cls || clear");

        switch(selection){
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");
                gestor();   
                break;
        }
    }while(selection =! 4);
}

// Login Auth
void authlogin(){
    int loggedin;
    int attempts = 0;

    // Senhas dos usuários
    char passgestor[] = "gestoruni01";
    char passeng[] = "eng01";
    char passmdo[] = "mdo01";
    char passforn[] = "forn01";

    do{
        if(attempts >= 3){
            printf(ColorRed "\nMuitas tentativas, tente novamente mais tarde." ResetColor);
            loggedin = 1;
            attempts = 0;
        }
        else{
            printf("\nDigite a senha de acesso:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
            printf(ColorGreen "\n-> " ResetColor);
            scanf(" %s", &password);

            if(strcmp(passgestor,password) == 0){
                loggedin = 1;
                system("cls || clear");
                gestor();
            }
            else if(strcmp(passeng,password) == 0){
                loggedin = 1;
                system("cls || clear");
                engenheiro();
            }
            else if(strcmp(passmdo,password) == 0){
                loggedin = 1;
                system("cls || clear");
                mestredeobra();
            }
            else if(strcmp(passforn,password) == 0){
                loggedin = 1;
                system("cls || clear");
                fornecedor();
            }
            else{
                attempts += 1;
                if(attempts < 3)
                    printf(ColorRed "\nSenha incorreta! Tente novamente." ResetColor);                
            }
        }
    }while(loggedin != 1);
}

int main(){
    int selection;
    do{
        printf(BColorCyan "\n########################" ResetColor);
        printf(BColorCyan "\n#   " BColorWhite "Alana Construções" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Fazer login" BColorCyan "      #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Sair do programa" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n########################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);
        scanf("%d", &selection);
        scanf("%*[^\n]%*c");
        system("cls || clear");

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
