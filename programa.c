// Libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "colors.h"

// Functions
//// Menus
void administrador(void);
void gestor(void);
void engenheiro(void);
void mestredeobra(void);
void fornecedor(void);

//// Menu options
void getchoice(void);
void messages(void);
void addaccount(void);
void viewworks(void);
void getwork(void);
void addmessage(void);
void viewmessage(void);
void removemessage(void);
void requestwork(void);
void viewworksrequest(void);
void manageworksrequest(void);
void requestmaterial(void);
void viewmaterialrequest(void);
void addprice(void);
void buymaterial(void);
void confirmdelivery(void);

//// Login
void home(void);
void login(void);
void authlogin(void);

//// Other
void clearinput(void);
void formattext(void);

// Variables
//// login
int loggedaccount;
int type = -1; //
char username[16];
char password[16];
int connected = 0;

//// Menus
int inputbuffer, choice;
int workpos = 0;
int workrequestpos = 0;
int currentwork = -1;
char choicestr[5];
int accountpos = 1;

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
    int day, month, year;
};

//// Materials
struct materials{
    char matname[21];
    char quantity[21];
    char forn1[21], forn2[21], forn3[21], finalforn[21];
    float price, price2, price3, finalprice;
    int status; // 0 = Solicitado | 1 = Aguardando Compra | 2 = Enviado | 3 = Entregue
    int day, month, year;
};

//// Works
struct worksrequest{
    char workname[21];
    char workdescription[51];
}workrequest[5];

struct works{
    char workname[21];
    char workdescription[51];
    int messagepos;
    int matpos;
    struct messages message[20];
    struct materials material[100];
}work[5];

//// Date
time_t date;
struct tm * dateinfo;

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
void getdate(){
    time(&date);
    dateinfo = localtime(&date);
}

void getchoice(){
    if(fgets(choicestr, 5, stdin)){
            if(!strrchr(choicestr, '\n')){
            clearinput();
            }
        }

    choice = strtol(choicestr, NULL, 10);
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
    printf(BColorWhite "                      Obras                     \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    for(i = 0; i < workpos; i++){
        printf(BColorWhite "\nNúmero: " ResetColor "%d - " BColorWhite "Obra: " ResetColor "%s\n" BColorWhite "Descrição: " ResetColor "%s", (i + 1), work[i].workname, work[i].workdescription);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    }
    if(workpos == 0){
        system("clear || cls");
        printf(ColorYellow "Não há obras para exibir.\n" ResetColor);
    }
}

void getwork(){
    viewworks();

    if(workpos > 0){
        printf("\nDigite o número da Obra que deseja escolher:");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();

        system("clear || cls");

        if((choice - 1) >= 0 && (choice - 1) < workpos){
            currentwork = choice - 1;
            printf(ColorGreen "Obra escolhida com sucesso!\n" ResetColor);
        }
        else
            printf(ColorRed "Número da obra inválido.\n" ResetColor);
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
            printf(BColorWhite "                      Login                     \n" ResetColor);
            printf(ColorCyan "--------------------------------------------------\n" ResetColor);
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
                printf(ColorRed "Nome de usuário ou senha incorreto!\n\n" ResetColor);
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
    currentwork = -1;
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
    printf(BColorWhite "                Criar nova conta                \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
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

    if(fgets(choicestr, 5, stdin)){
        if(!strrchr(choicestr, '\n')){
            clearinput();
        }
    }

    system("clear || cls");

    if(strtol(choicestr, NULL, 10) > 0 && strtol(choicestr, NULL, 10) <= 4){
        account[accountpos].type = strtol(choicestr, NULL, 10);
        printf(ColorGreen "Conta adicionada com sucesso!\n" ResetColor);
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
void requestwork(){
    printf(BColorWhite "              Solicitar nova obra               \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    printf("\nDigite o nome da obra: " ColorYellow "(máximo 20 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);

    if(fgets(workrequest[workrequestpos].workname, 21, stdin)){
        if(!strrchr(workrequest[workrequestpos].workname, '\n')){
            clearinput();
        }
    }
    workrequest[workrequestpos].workname[strlen(workrequest[workrequestpos].workname) -1] = '\0'; // Remove o \n do fim da string para melhor exibição desta variável.

    printf("\nDigite a descrição da obra: " ColorYellow "(máximo 50 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);

    if(fgets(workrequest[workrequestpos].workdescription, 51, stdin)){
        if(!strrchr(workrequest[workrequestpos].workdescription, '\n')){
            clearinput();
        }
    }

    system("clear || cls");

    printf(ColorGreen "Obra solicitada com sucesso!\n" ResetColor);

    workrequestpos++;
}

void viewmessage(){
    int i;
    printf(BColorWhite "                     Mensagens                  \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    for(i = 0; i < work[currentwork].messagepos; i++){
        printf(BColorWhite "\nNúmero: " ResetColor "%d" BColorWhite " Autor: " ResetColor "%s" BColorWhite " Data: " ResetColor "%02d/%02d/%d\n" BColorWhite "Mensagem: " ResetColor "%s", (i + 1), work[currentwork].message[i].author, work[currentwork].message[i].day, work[currentwork].message[i].month, work[currentwork].message[i].year, work[currentwork].message[i].text);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    }
    if(work[currentwork].messagepos == 0){
        system("clear || cls");
        printf(ColorYellow "Não há mensagens para exibir.\n" ResetColor);
    }
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
                if(workrequestpos <= 5)
                    requestwork();
                else 
                    printf(ColorRed "Há muitas solicitações no momento, tente novamente mais tarde.\n" ResetColor);
                break;

            case 3:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
                }
                break;

            case 4:
                if(currentwork > -1){
                    viewmessage();
                    printf(ColorYellow "\nPressione Enter para retornar..." ResetColor);
                    getchar();
                    system("clear || cls");
                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
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
void buymaterial(){
    int i;
    int j;
    printf(BColorWhite "             Comprar material                   \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);

    for(i = 0; i < work[currentwork].matpos; i++){
        if(work[currentwork].material[i].status == 1){
            printf(BColorWhite "ID:" ResetColor "%d\n" BColorWhite "Material:" ResetColor " %s" BColorWhite "Quantidade:" ResetColor " %s" BColorWhite "Data: " ResetColor "%02d/%02d/%d\n" BColorWhite "Status:" ResetColor " %s", i + 1, work[currentwork].material[i].matname, work[currentwork].material[i].quantity, work[currentwork].material[i].day, work[currentwork].material[i].month, work[currentwork].material[i].year, "Aguardando compra\n");
            printf(ColorCyan "--------------------------------------------------\n" ResetColor);
        }
    }

    printf("\nDigite o ID do material:");
    printf(ColorGreen "\n-> " ResetColor);
    getchoice();
    i = choice - 1;

    system("clear || cls");

    if(i >= 0 && i < work[currentwork].matpos && work[currentwork].material[i].status == 1){
        printf(BColorWhite "                Material escolhido              \n" ResetColor);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
        printf(BColorWhite "ID:" ResetColor "%d\n" BColorWhite "Material:" ResetColor " %s" BColorWhite "Quantidade:" ResetColor " %s" BColorWhite "Data: " ResetColor "%02d/%02d/%d\n", i + 1, work[currentwork].material[i].matname, work[currentwork].material[i].quantity, work[currentwork].material[i].day, work[currentwork].material[i].month, work[currentwork].material[i].year);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);

        printf(BColorWhite "                  Fornecedores                  \n" ResetColor);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
        printf(BColorWhite "Número: " ResetColor "%d\n" BColorWhite "Fornecedor:" ResetColor " %s" BColorWhite "Preço:" ResetColor " %.2f\n", 1, work[currentwork].material[i].forn1, work[currentwork].material[i].price);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
        printf(BColorWhite "Número: " ResetColor "%d\n" BColorWhite "Fornecedor:" ResetColor " %s" BColorWhite "Preço:" ResetColor " %.2f\n", 2, work[currentwork].material[i].forn2, work[currentwork].material[i].price2);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
        printf(BColorWhite "Número: " ResetColor "%d\n" BColorWhite "Fornecedor:" ResetColor " %s" BColorWhite "Preço:" ResetColor " %.2f\n", 3, work[currentwork].material[i].forn3, work[currentwork].material[i].price3);

        printf("\nDigite o número do fornecedor que deseja realizar a compra:");
        printf(ColorGreen "\n-> " ResetColor);
        getchoice();
        j = choice;

        system("clear || cls");

        if(j == 1){
            strncpy(work[currentwork].material[i].finalforn, work[currentwork].material[i].forn1, 21);
            work[currentwork].material[i].finalprice = work[currentwork].material[i].price;
            work[currentwork].material[i].status = 2;
            printf(ColorGreen "Compra realizada com sucesso!\n" ResetColor);
        }
        else if(j == 2){
            strncpy(work[currentwork].material[i].finalforn, work[currentwork].material[i].forn2, 21);
            work[currentwork].material[i].finalprice = work[currentwork].material[i].price2;
            work[currentwork].material[i].status = 2;
            printf(ColorGreen "Compra realizada com sucesso!\n" ResetColor);
        }
        else if(j == 3){
            strncpy(work[currentwork].material[i].finalforn, work[currentwork].material[i].forn3, 21);
            work[currentwork].material[i].finalprice = work[currentwork].material[i].price3;
            work[currentwork].material[i].status = 2;
            printf(ColorGreen "Compra realizada com sucesso!\n" ResetColor);
        }
        else 
            printf(ColorRed "Fornecedor escolhido não existe!\n" ResetColor);
    }
    else 
        printf(ColorRed "Material escolhido não existe!\n" ResetColor);
}

void viewworksrequest(){
    int i;
    printf(BColorWhite "             Solicitações de obra               \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    for(i = 0; i < workrequestpos; i++){
        printf(BColorWhite "\nNúmero: " ResetColor "%d - " BColorWhite "Obra: " ResetColor "%s\n" BColorWhite "Descrição: " ResetColor "%s", (i + 1), workrequest[i].workname, workrequest[i].workdescription);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    }
    if(workrequestpos == 0)
        printf(ColorYellow "Não há solicitações de obras para exibir.\n" ResetColor);
}

void manageworksrequest(){
    int i;
    viewworksrequest();
    if(workrequestpos > 0){
        printf("\nDigite o número da solicitação de obra que deseja iniciar:");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();

        system("clear || cls");

        if((choice - 1) >= 0 && (choice - 1) < workrequestpos){
            // Copia as informações para a obra
            strncpy(work[workpos].workname, workrequest[choice -1].workname, 21);
            strncpy(work[workpos].workdescription, workrequest[choice -1].workdescription, 51);
            workpos++;

            // Remove a solicitação
            for(i = (choice - 1); i < workrequestpos; i++){
                workrequest[i] = workrequest[i + 1];
            }
            workrequestpos--;

            printf(ColorGreen "Obra iniciada com sucesso!\n" ResetColor);
        }
        else
            printf(ColorRed "\nObra selecionada não existe! Tente novamente.\n" ResetColor);
    }
}

void addmessage(){
    printf(BColorWhite "               Adicionar mensagem               \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    printf("\nDigite a mensagem que deseja adicionar:" ColorYellow " (máximo 200 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    if(fgets(text, sizeof(text), stdin)){
        if(!strrchr(text, '\n')){
            clearinput();
        }
    }

    if(strlen(text) > 41)
        formattext();        

    system("clear || cls");

    if(work[currentwork].messagepos <= 20){
        strncpy(work[currentwork].message[work[currentwork].messagepos].text, text, 201);
        strncpy(work[currentwork].message[work[currentwork].messagepos].author, account[loggedaccount].name, 21);
        getdate();
        work[currentwork].message[work[currentwork].messagepos].day = dateinfo->tm_mday;
        work[currentwork].message[work[currentwork].messagepos].month = dateinfo->tm_mon + 1;
        work[currentwork].message[work[currentwork].messagepos].year = dateinfo->tm_year + 1900;
        work[currentwork].messagepos++;
        printf(ColorGreen "Mensagem adicionada com sucesso!\n" ResetColor);
    }
    else
        printf(ColorRed "O histórico de mensagens está cheio. Apague mensagens e tente novamente.\n" ResetColor);
}

void removemessage(){
    int i;

    viewmessage();

    printf("\nDigite o número da mensagem que deseja remover:");
    printf(ColorGreen "\n-> " ResetColor);

    getchoice();

    system("clear || cls");

    if((choice - 1) >= 0 && (choice -1) < work[currentwork].messagepos){
        for(i = (choice - 1); i < work[currentwork].messagepos; i++){
            work[currentwork].message[i] = work[currentwork].message[i+1];
        }
        work[currentwork].messagepos--;
        printf(ColorGreen "Mensagem removida com sucesso!\n" ResetColor);
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
                if(workpos <= 5)
                    manageworksrequest();
                else 
                    printf(ColorRed "Há muitas obras em andamento, aguarde a conclusão de outras obras.\n" ResetColor);
                break;

            case 3:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
                }
                break;

            case 4:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
                }
                break;

            case 5:
                if(currentwork > -1){
                    if(work[currentwork].matpos > 0)
                        buymaterial();
                    else 
                        printf(ColorYellow "Não há materiais para comprar\n" ResetColor);
                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
                }
                break;
            
            case 6:
                if(currentwork > -1){
                    messages();
                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
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
void confirmdelivery(){
    int i;
    printf(BColorWhite "             Confirmar Recebimento              \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);

    for(i = 0; i < work[currentwork].matpos; i++){
        if(work[currentwork].material[i].status == 2){
            printf(BColorWhite "ID:" ResetColor "%d\n" BColorWhite "Material:" ResetColor " %s" BColorWhite "Quantidade:" ResetColor " %s" BColorWhite "Data: " ResetColor "%02d/%02d/%d\n" BColorWhite "Status:" ResetColor " %s", i + 1, work[currentwork].material[i].matname, work[currentwork].material[i].quantity, work[currentwork].material[i].day, work[currentwork].material[i].month, work[currentwork].material[i].year, "Enviado\n");
            printf(ColorCyan "--------------------------------------------------\n" ResetColor);
        }
    }

    printf("\nDigite o ID do material recebido:");
    printf(ColorGreen "\n-> " ResetColor);
    getchoice();
    i = choice - 1;

    system("clear || cls");

    if(i >= 0 && i <= work[currentwork].matpos && work[currentwork].material[i].status == 2){
        work[currentwork].material[i].status = 3;
        printf(ColorGreen "Recebimento confirmado com sucesso!\n" ResetColor);
    }
    else 
        printf(ColorRed "Material escolhido não existe!\n" ResetColor);
}

void requestmaterial(){
    printf(BColorWhite "               Solicitar Material               \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    printf("\nDigite o nome do material:" ColorYellow " (máximo 50 caracteres!)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    if(fgets(work[currentwork].material[work[currentwork].matpos].matname, 51, stdin)){
        if(!strrchr(work[currentwork].material[work[currentwork].matpos].matname, '\n')){
            clearinput();
        }
    }

    printf("\nDigite a quantidade do material:" ColorYellow " (Exemplo: 100kg | 10L)" ResetColor);
    printf(ColorGreen "\n-> " ResetColor);
    if(fgets(work[currentwork].material[work[currentwork].matpos].quantity, 21, stdin)){
        if(!strrchr(work[currentwork].material[work[currentwork].matpos].quantity, '\n')){
            clearinput();
        }
    }
    getdate();
    work[currentwork].material[work[currentwork].matpos].status = 0;
    work[currentwork].material[work[currentwork].matpos].day = dateinfo->tm_mday;
    work[currentwork].material[work[currentwork].matpos].month = dateinfo->tm_mon + 1;
    work[currentwork].material[work[currentwork].matpos].year = dateinfo->tm_year + 1900;
    work[currentwork].matpos++;

    system("clear || cls");

    printf(ColorGreen "Material solicitado com sucesso!\n" ResetColor);

}

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
                    if(work[currentwork].matpos <= 100)
                        requestmaterial();
                    else
                        printf(ColorRed "Lista de materiais está cheia, entre em contato com o Administrador.\n" ResetColor);
                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
                }
                break;
            
            case 3:
                if(currentwork > -1){
                    if(work[currentwork].matpos > 0)
                        confirmdelivery();
                    else
                        printf(ColorYellow "Não há materiais para receber!\n" ResetColor);
                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
                }
                break;

            case 4:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
                }
                break;

            case 5:
                if(currentwork > -1){

                }
                else{
                    printf(ColorYellow "Você ainda não escolheu uma Obra!\n" ResetColor);
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
void viewmaterialrequest(){
    int i, j;
    printf(BColorWhite "           Solicitações de Materiais            \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);

    for(i = 0; i < workpos; i++){
        for(j = 0; j < work[i].matpos; j++){
            if(work[i].material[j].status == 0){
                printf(BColorWhite "\nMaterial:" ResetColor " %s" BColorWhite "Quantidade:" ResetColor " %s" BColorWhite "Data: " ResetColor "%02d/%02d/%d\n" BColorWhite "Status:" ResetColor " %s", work[i].material[j].matname, work[i].material[j].quantity, work[i].material[j].day, work[i].material[j].month, work[i].material[j].year, "Solicitado\n");
                printf(ColorCyan "--------------------------------------------------\n" ResetColor);
            }
        }
        if(work[i].matpos == 0){
            system("clear || cls");
            printf(ColorYellow "Não há solicitações de materiais para exibir\n" ResetColor);
        }
    }
}

void addprice(){
    int i, j;
    char pricestr[20];
    float price;

    printf(BColorWhite "       Adicionar valor de Fornecedores          \n" ResetColor);
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    for(i = 0; i < workpos; i++){
        for(j = 0; j < work[i].matpos; j++){
            if(work[i].material[j].status == 0)
                printf(BColorWhite "\nObra:" ResetColor "%d | " BColorWhite "ID:" ResetColor "%d\n" BColorWhite "Material:" ResetColor " %s" BColorWhite "Quantidade:" ResetColor " %s" BColorWhite "Data: " ResetColor "%02d/%02d/%d\n" BColorWhite "Status:" ResetColor " %s", i + 1, j + 1, work[i].material[j].matname, work[i].material[j].quantity, work[i].material[j].day, work[i].material[j].month, work[i].material[j].year, "Solicitado\n");
        }
    printf(ColorCyan "--------------------------------------------------\n" ResetColor);
    }

    printf("\nDigite o número da obra:");
    printf(ColorGreen "\n-> " ResetColor);
    getchoice();
    i = choice - 1;

    printf("\nDigite o ID:");
    printf(ColorGreen "\n-> " ResetColor);
    getchoice();
    j = choice - 1;

    system("clear || cls");

    if(i >= 0 && i < workpos && j >= 0 && j < work[i].matpos && work[i].material[j].status == 0){
        printf(BColorWhite "                Material escolhido              \n" ResetColor);
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);
        printf(BColorWhite "\nObra:" ResetColor "%d | " BColorWhite "ID:" ResetColor "%d\n" BColorWhite "Material:" ResetColor " %s" BColorWhite "Quantidade:" ResetColor " %s" BColorWhite "Data: " ResetColor "%02d/%02d/%d\n" BColorWhite "Status:" ResetColor " %s", i + 1, j + 1, work[i].material[j].matname, work[i].material[j].quantity, work[i].material[j].day, work[i].material[j].month, work[i].material[j].year, "Solicitado\n");
        printf(ColorCyan "--------------------------------------------------\n" ResetColor);

        printf("\nDigite o nome do Fornecedor 1:");
        printf(ColorGreen "\n-> " ResetColor);
        if(fgets(work[i].material[j].forn1, 21, stdin)){
            if(!strrchr(work[i].material[j].forn1, '\n')){
                clearinput();
            }
        }

        printf("\nDigite o preço do Fornecedor 1:");
        printf(ColorGreen "\n-> " ResetColor);
        if(fgets(pricestr, 20, stdin)){
            if(!strrchr(pricestr, '\n')){
                clearinput();
            }
        }
        price = strtof(pricestr, NULL);
        work[i].material[j].price = price;

        printf("\nDigite o nome do Fornecedor 2:");
        printf(ColorGreen "\n-> " ResetColor);
        if(fgets(work[i].material[j].forn2, 21, stdin)){
            if(!strrchr(work[i].material[j].forn2, '\n')){
                clearinput();
            }
        }

        printf("\nDigite o preço do Fornecedor 2:");
        printf(ColorGreen "\n-> " ResetColor);
        if(fgets(pricestr, 20, stdin)){
            if(!strrchr(pricestr, '\n')){
                clearinput();
            }
        }
        price = strtof(pricestr, NULL);
        work[i].material[j].price2 = price;

        printf("\nDigite o nome do Fornecedor 3:");
        printf(ColorGreen "\n-> " ResetColor);
        if(fgets(work[i].material[j].forn3, 21, stdin)){
            if(!strrchr(work[i].material[j].forn3, '\n')){
                clearinput();
            }
        }

        printf("\nDigite o preço do Fornecedor 3:");
        printf(ColorGreen "\n-> " ResetColor);
        if(fgets(pricestr, 20, stdin)){
            if(!strrchr(pricestr, '\n')){
                clearinput();
            }
        }
        price = strtof(pricestr, NULL);
        work[i].material[j].price3 = price;

        work[i].material[j].status = 1;

        system("clear || cls");

        printf(ColorGreen "Preços adicionados com sucesso!\n" ResetColor);
    }
    else{
        system("clear || cls");
        printf(ColorRed "Número da obra ou ID não encontrado!\n" ResetColor);
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
        printf("\nO que deseja fazer?");
        printf(ColorGreen "\n-> " ResetColor);

        getchoice();
        
        system("cls || clear");

        switch(choice){
            case 1:
                viewmaterialrequest();
                printf(ColorYellow "\nPressione Enter para retornar..." ResetColor);
                getchar();
                system("clear || cls");
                break;

            case 2:
                addprice();
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