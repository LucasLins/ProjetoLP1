#ifndef HEADER_H_
#define HEADER_H_

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
void totalspending(void);
void workhistory(void);
void viewmaterials(void);

//// Login
void home(void);
void login(void);
void authlogin(void);

//// Other
void clearinput(void);
void formattext(void);
void getdate(void);


// Text Colors
//// Relugar
#define ColorBlack "\e[0;30m"
#define ColorRed "\e[0;91m"
#define ColorGreen "\e[0;92m"
#define ColorYellow "\e[0;93m"
#define ColorBlue "\e[0;94m"
#define ColorMagenta "\e[0;95m"
#define ColorCyan "\e[0;96m"
#define ColorWhite "\e[0;97m"

//// Bold
#define BColorBlack "\e[1;30m"
#define BColorRed "\e[1;91m"
#define BColorGreen "\e[1;92m"
#define BColorYellow "\e[1;93m"
#define BColorBlue "\e[1;94m"
#define BColorMagenta "\e[1;95m"
#define BColorCyan "\e[1;96m"
#define BColorWhite "\e[1;97m"

//// Foreground + Background
#define FGBGWhite "\e[97;107m"

//// Clear color
#define ResetColor "\e[0m"

#endif