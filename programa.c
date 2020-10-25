// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

// Variables
//// login
char password[16];
char name[20] = "Lucas Lins";

//// Menus
int inputbuffer, choice;

//// Messages
int messagepos = 0;
char text[201];

// Arrays
//// Messages
char messagehistory[31][201];
char messageauthor[31][201];


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

// Área do Fornecedor
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

// Área do Mestre de Obras
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

// Área do Engenheiro
int verifynumber(){
    while (1) {
        printf("\nDigite o número da mensagem que deseja remover:");
        printf(ColorGreen "\n-> " ResetColor);
        if (scanf("%d", &choice) < 0 || ((inputbuffer = getchar()) != EOF && inputbuffer != '\n')) { // 
            clearerr(stdin);
            do{
                inputbuffer = getchar();
            }while (inputbuffer != EOF && inputbuffer != '\n');
            clearerr(stdin);
            printf(ColorRed "Número desconhecido, digite novamente.\n" ResetColor);
        }
        else{
            return choice;
            break;
        }
    }
}

void addmessage(){
    printf("\nDigite a mensagem que deseja adicionar:" ColorYellow " (Máximo 200 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    fgets(text, 201, stdin);
    if(messagepos <= 30){
        strcpy(messagehistory[messagepos], text);
        strcpy(messageauthor[messagepos], name);
        messagepos++;
        printf(ColorGreen "Mensagem adicionada com sucesso!\n" ResetColor);
    }
    else
        printf(ColorRed "O histórico de mensagens está cheio. Apague mensagens e tente novamente." ResetColor);
}

void viewmessage(){
    int i;
    for(i = 0; i < messagepos; i++){
        printf(BColorWhite "\nNúmero: " ResetColor "%d - " BColorWhite "Autor: " ResetColor "%s\n" BColorWhite "Mensagem: " ResetColor "%s", (i + 1), messageauthor[i], messagehistory[i]);
    }
    if(messagepos == 0)
        printf(ColorYellow "Não há mensagens para exibir." ResetColor);
}

void removemessage(){
    int i;

    viewmessage();
        choice = verifynumber();

    if(choice - 1 >= 0 && choice <= messagepos){
        for(i = choice - 1; i < messagepos; i++){
            strcpy(messagehistory[i], messagehistory[i+1]);
            strcpy(messageauthor[i], messageauthor[i+1]);
        }
        strcpy(messagehistory[messagepos], "");
        strcpy(messageauthor[messagepos], "");
        messagepos--;
        printf(ColorGreen "\nMensagem removida com sucesso!" ResetColor);
    }
    else
        printf(ColorRed "Não foi possível localizar esta mensagem.\n" ResetColor);
}

void messages(){

    do{
        printf(BColorCyan "\n############################" ResetColor);
        printf(BColorCyan "\n#  " BColorWhite "Engenheiro - Mensagens" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Adicionar mensagem" BColorCyan "   #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Remover mensagem" BColorCyan "     #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Retornar" BColorCyan "             #" ResetColor);
        printf(BColorCyan "\n############################" ResetColor);
        choice = verifychoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                addmessage();
                messages();
                break;

            case 2:
                if(messagepos == 0)
                    viewmessage();
                else
                    removemessage();
                messages();
                break;

            case 3:
                engenheiro();
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");
                messages();   
                break;
        }
    }while(choice =! 4);
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
                messages();
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

// Área do Gestor UNIESP
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
                break;
        }
    }while(choice != 2);

    return 0;
}
