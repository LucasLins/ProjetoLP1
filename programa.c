// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"

// Functions
void home(void);
void administrador(void);
void gestor(void);
void engenheiro(void);
void mestredeobra(void);
void fornecedor(void);
void getchoice(void);
void login(void);
void authlogin(void);
void addaccount(void);
void viewworks(void);
void getwork(void);
void addmessage(void);
void viewmessage(void);
void removemessage(void);
void messages(void);
void clearinput(void);
void formattext(void);

// Variables
//// login
int loggedaccount;
int type = -1; //
char username[16];
char password[16];
int accountpos = 1;
int connected = 0;

//// Menus
int inputbuffer, choice;
int workpos = 0;
int currentwork = -1;
char choicestr[2];

//// Messages
char text[201];


// Structs
//// Accounts
struct accounts{
    char username[16];
    char password[16];
    char name[21];
    int type;
    int status;
}account[10];

//// Messages
struct messages{
    char author[21];
    char text[201];
};

//// Works
struct works{
    char workname[21];
    char workdescription[51];
    float totalmaterials;
    float totalemployees;

    int messagepos;
    struct messages message[20];
}work[5];

// Main menu
int main(){

    do{
        printf(BColorCyan "\n########################" ResetColor);
        printf(BColorCyan "\n#   " BColorWhite "Alana Construções" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Fazer login" BColorCyan "      #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Sair do programa" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n########################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();

        system("cls || clear");

        switch(choice){
            case 1:
                login();
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

//General
void getchoice(){
    if(fgets(choicestr, 2, stdin)){
            if(!strrchr(choicestr, '\n')){
            clearinput();
            }
        }

    choice = atoi(choicestr);
}

void clearinput(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void formattext(){ // Adiciona nova linha a cada 50 caracteres para manter o texto organizado
    int i;
    int lenght = strlen(text);
    for(i = 40; i<lenght; i++){
        if(i >= 36 && i <= 60){
            if(text[i] == ' '){
                text[i] = '\n';
                i = 90;
            }
        }
        if(i >= 95 && i <= 110){
            if(text[i] == ' '){
                text[i] = '\n';
                i = 111;
            }
        }
        if(i >= 145 && i <= 160){
            if(text[i] == ' '){
                text[i] = '\n';
                i = 201;
            }
        }
    }
}

void viewworks(){
    int i;
    for(i = 0; i < workpos; i++){
        printf(BColorWhite "\nNúmero: " ResetColor "%d - " BColorWhite "Obra: " ResetColor "%s\n" BColorWhite "Descrição: " ResetColor "%s", (i + 1), work[i].workname, work[i].workdescription);
    }
    if(workpos == 0)
        printf(ColorYellow "Não há obras para exibir." ResetColor);
}

void getwork(){
    viewworks();

    if(workpos > 0){
        printf("\nDigite o número da Obra que deseja escolher:");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();

        if((choice - 1) >= 0 && (choice - 1) < workpos)
            currentwork = choice - 1;
        else
            printf("Número da obra inválido.");
    }
}

// Login
void authlogin(){
    type = -1;
    int i;
    for(i = 0; i < accountpos; i++){
        if(strncmp(account[i].username, username, 16) == 0 && strncmp(account[i].password, password, 16) == 0){
            type = account[i].type;
            loggedaccount = i; // current account logged
            i = accountpos; // break loop
        }
    }
}

void login(){
    int attempts;    
    int loggedin = 0;

    if(strncmp(account[0].username, "adminuniesp\n", 16) != 0){ // Adiciona a conta do administrador do sistema, caso não exista.
        strncpy(account[0].username,"adminuniesp\n", 16);
        strncpy(account[0].password,"adminuniesp\n", 16);
        strncpy(account[0].name,"Admin", 21);
        account[0].type = 0;
    }

    do{
        if(attempts >= 3){
            system("cls || clear");
            printf(ColorRed "Muitas tentativas, tente novamente mais tarde.\n" ResetColor);
            loggedin = 1;
            attempts = 0;
        }
        else{
            printf("\nDigite o usuário:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
            printf(ColorGreen "\n-> " ResetColor);
            
            if(fgets(username, sizeof(username), stdin)){
                if(!strrchr(username, '\n')){
                    clearinput();
                }
            }

            printf("\nDigite a senha:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
            printf(ColorGreen "\n-> " FGBGWhite);

            if(fgets(password, sizeof(password), stdin)){
                if(!strrchr(password, '\n')){
                    clearinput();
                }
            }
            printf(ResetColor);

            authlogin();

            if(type == -1){
                system("cls || clear");
                printf(ColorRed "Nome de usuário ou senha incorreto!\n" ResetColor);
                attempts++;
            }
            else{
                system("cls || clear");
                printf(ColorGreen "\nBem vindo(a), %s!\n" ResetColor, account[loggedaccount].name);
                connected = 1;
                home();
                loggedin = 1;
            }
        }
    }while(loggedin != 1);
}

void home(){
    do{
        switch(type){
            case 0:
                administrador();
                break;
            case 1:
                gestor();
                break;
            case 2:
                engenheiro();
                break;
            case 3:
                mestredeobra();
                break;
            case 4:
                fornecedor();
                break;
            default:
                printf(ColorRed "\nOcorreu um erro desconhecido, entre em contato com o Administrador." ResetColor);
                connected = 0;
                break;
        }
    }while(connected);
}

// Área do Administrador do sistema
void addaccount(){

    printf("\nDigite o usuário:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    
    if(fgets(account[accountpos].username, 16, stdin)){
        if(!strrchr(account[accountpos].username, '\n')){
            clearinput();
        }
    }

    printf("\nDigite a senha:" ColorYellow "(máximo 15 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);

    if(fgets(account[accountpos].password, 16, stdin)){
        if(!strrchr(account[accountpos].password, '\n')){
            clearinput();
        }
    }

    printf("\nDigite o nome do funcionário:" ColorYellow "(máximo 20 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    
    if(fgets(account[accountpos].name, 21, stdin)){
        if(!strrchr(account[accountpos].name, '\n')){
            clearinput();
        }
    }
    account[accountpos].name[strlen(account[accountpos].name) - 1] = '\0'; // Remove o \n do nome para melhor utilização dessa variável.

    printf("\nDigite o tipo (cargo) da conta:" ColorYellow "\n(1 = Gestor UNIESP | 2 = Engenheiro | 3 = Mestre de Obra | 4 = Fornecedor)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);

    if(fgets(choicestr, 2, stdin)){
        if(!strrchr(choicestr, '\n')){
            clearinput();
        }
    }
    if(atoi(choicestr) > 0 && atoi(choicestr) <= 4){
        account[accountpos].type = atoi(choicestr);
        printf(ColorGreen "Conta adicionada com sucesso!" ResetColor);
        accountpos++;
    }
    else
        printf(ColorRed "Número inválido");
}

void administrador(){
    do{
        printf(BColorCyan "\n##############################" ResetColor);
        printf(BColorCyan "\n#            " BColorWhite "Admin" BColorCyan "           #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Adicionar novo usuário" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Desconectar da conta" BColorCyan "   #" ResetColor);
        printf(BColorCyan "\n##############################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                addaccount();
                break;

            case 2:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                connected = 0;
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");  
                break;
        }
    }while(choice =! 2);
}

// Área do Gestor UNIESP
void viewmessage(){
    int i;
    for(i = 0; i < work[currentwork].messagepos; i++){
        printf(BColorWhite "\nNúmero: " ResetColor "%d - " BColorWhite "Autor: " ResetColor "%s\n" BColorWhite "Mensagem: " ResetColor "%s", (i + 1), work[currentwork].message[i].author, work[currentwork].message[i].text);
    }
    if(work[currentwork].messagepos == 0)
        printf(ColorYellow "Não há mensagens para exibir." ResetColor);
}

void gestor(){

    do{
        printf(BColorCyan "\n###################################" ResetColor);
        printf(BColorCyan "\n#          " BColorWhite "Gestor UNIESP" BColorCyan "          #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Escolher Obra" BColorCyan "               #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Solicitar nova Obra" BColorCyan "         #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Verificar custo da obra" BColorCyan "     #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Verificar histórico da obra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "5 - Desconectar da conta" BColorCyan "        #" ResetColor);
        printf(BColorCyan "\n###################################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                getwork();
                break;

            case 2:
                break;

            case 3:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;

            case 4:
                if(currentwork > -1){
                    viewmessage();
                    printf(ColorYellow "\nPressione Enter para retornar..." ResetColor);
                    getchar();
                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;

            case 5:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                connected = 0;
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");   
                break;
        }
    }while(choice =! 4);
}

// Área do Engenheiro
void addmessage(){
    printf("\nDigite a mensagem que deseja adicionar:" ColorYellow " (Máximo 200 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    if(fgets(text, sizeof(text), stdin)){
        if(!strrchr(text, '\n')){
            clearinput();
        }
    }

    if(strlen(text) > 41)
        formattext();        

    
    if(work[currentwork].messagepos <= 20){
        strncpy(work[currentwork].message[work[currentwork].messagepos].text, text, 201);
        strncpy(work[currentwork].message[work[currentwork].messagepos].author, account[loggedaccount].name, 21);
        work[currentwork].messagepos++;
        printf(ColorGreen "Mensagem adicionada com sucesso!\n" ResetColor);
    }
    else
        printf(ColorRed "O histórico de mensagens está cheio. Apague mensagens e tente novamente." ResetColor);
}

void removemessage(){
    int i;

    viewmessage();

    printf("\nDigite o número da mensagem que deseja remover:");
    printf(ColorGreen "\n-> " ResetColor);

    getchoice();

    if(choice - 1 >= 0 && choice <= work[currentwork].messagepos){
        for(i = choice - 1; i < work[currentwork].messagepos; i++){
            work[currentwork].message[i] = work[currentwork].message[i+1];
        }
        work[currentwork].messagepos--;
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
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                addmessage();
                break;

            case 2:
                if(work[currentwork].messagepos == 0)
                    viewmessage();
                else
                    removemessage();
                break;

            case 3:
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");  
                break;
        }
    }while(choice =! 3);
}

void engenheiro(){
    
    do{
        printf(BColorCyan "\n###############################" ResetColor);
        printf(BColorCyan "\n#         " BColorWhite "Engenheiro" BColorCyan "          #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Escolher Obra" BColorCyan "           #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Iniciar Obra" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Contratar Funcionários" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Verificar custo da obra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "5 - Selecionar fornecedor e" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "    finalizar compra" BColorCyan "        #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "6 - Adicionar mensagem de" BColorCyan "   #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "    acompanhamento da obra" BColorCyan "  #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "7 - Desconectar da conta" BColorCyan "    #" ResetColor);
        printf(BColorCyan "\n###############################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                getwork();
                break;

            case 2:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;

            case 3:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;

            case 4:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;

            case 5:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;
            
            case 6:
                if(currentwork > -1){
                    messages();
                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;
            
            case 7:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                connected = 0;
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");  
                break;
        }
    }while(choice =! 6);
}

// Área do Mestre de Obras
void mestredeobra(){

    do{
        printf(BColorCyan "\n#######################################" ResetColor);
        printf(BColorCyan "\n#           " BColorWhite "Mestre de Obra" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "1 - Escolher Obra" BColorCyan "                   #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "2 - Solicitar Compra" BColorCyan "                #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "3 - Confirmar recebimento da compra" BColorCyan " #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "4 - Listar compras realizadas" BColorCyan "       #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "5 - Solicitar novos funcionários" BColorCyan "    #" ResetColor);
        printf(BColorCyan "\n# " ResetColor "6 - Desconectar da conta" BColorCyan "            #" ResetColor);
        printf(BColorCyan "\n#######################################" ResetColor);
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                getwork();
                break;

            case 2:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;
            
            case 3:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;

            case 4:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;

            case 5:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "\nVocê ainda não escolheu uma Obra!" ResetColor);
                }
                break;
            
            case 6:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                connected = 0;
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");
                break;
        }
    }while(choice =! 5);
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
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                break;

            case 2:
                break;

            case 3:
                printf(ColorYellow "Desconectado, até mais!\n" ResetColor);
                connected = 0;
                break;
            
            default:
                printf(ColorRed "Opção desconhecida, tente novamente.\n");
                break;
        }
    }while(choice =! 3);
}