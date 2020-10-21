// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

// Constants

// Variables
char password[16];
int inputbuffer, success, choice;


int verifychoice(){
    while (1) {
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);
        if (scanf("%d", &choice) < 0 || ((inputbuffer = getchar()) != EOF && inputbuffer != '\n')) { // 
            clearerr(stdin);
            do{
                inputbuffer = getchar();
            }while (inputbuffer != EOF && inputbuffer != '\n');
            clearerr(stdin);
            printf(ColorRed "Opção desconhecida, digite novamente.\n" ResetColor);
        }
        else{
            return choice;
            break;
        }
    }
}

void fornecedor(){
    

    do{
        printf(BColorCyan "\n##############################################" ResetColor);
        printf(BColorCyan "\n#                 " BColorWhite "Fornecedor" BColorCyan "                 #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Visualizar chamados de compra" BColorCyan "          #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Adicionar o valor de três fornecedores" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Desconectar da conta" BColorCyan "                   #" ResetColor);
        printf(BColorCyan "\n##############################################" ResetColor);
        choice = verifychoice();
        
        system("cls || clear");

        switch(choice){
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
    }while(choice =! 4);
}

void mestredeobra(){
    

    do{
        printf(BColorCyan "\n#######################################" ResetColor);
        printf(BColorCyan "\n#           " BColorWhite "Mestre de Obra" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Solicitar Compra" BColorCyan "                #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Confirmar recebimento da compra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Listar compras realizadas" BColorCyan "       #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Solicitar novos funcionários" BColorCyan "    #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "5 - Desconectar da conta" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n#######################################" ResetColor);
        choice = verifychoice();
        
        system("cls || clear");

        switch(choice){
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
    }while(choice =! 5);
}


void engenheiro(){
    

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
        choice = verifychoice();
        
        system("cls || clear");

        switch(choice){
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
    }while(choice =! 6);
}

void gestor(){
    

    do{
        printf(BColorCyan "\n###################################" ResetColor);
        printf(BColorCyan "\n#          " BColorWhite "Gestor UNIESP" BColorCyan "          #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Solicitar nova Obra" BColorCyan "         #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Verificar custo da obra" BColorCyan "     #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Verificar histórico da obra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Desconectar da conta" BColorCyan "        #" ResetColor);
        printf(BColorCyan "\n###################################" ResetColor);
        choice = verifychoice();
        
        system("cls || clear");

        switch(choice){
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
    }while(choice =! 4);
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
            system("cls || clear");
            printf(ColorRed "Muitas tentativas, tente novamente mais tarde.\n" ResetColor);
            loggedin = 1;
            attempts = 0;
            success = 0;
        }
        else{
            printf("\nDigite a senha de acesso:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
            printf(ColorGreen "\n-> " FGBGWhite);
            scanf(" %s", &password);
            printf(ResetColor);
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
    
    do{
        printf(BColorCyan "\n########################" ResetColor);
        printf(BColorCyan "\n#   " BColorWhite "Alana Construções" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Fazer login" BColorCyan "      #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Sair do programa" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n########################" ResetColor);
        choice = verifychoice();

        system("cls || clear");

        switch(choice){
            case 1:
                authlogin();
                break;
            case 2:
                printf(ColorRed "Saindo do programa...\n" ResetColor);
                break;
            default:
                printf(ColorRed "Opção desconhecida, digite novamente.\n" ResetColor);
                success = 0;
                break;
        }
    }while(choice != 2);

    return 0;
}
