#define EPSREL 0.1
#define SETTEMPERATURE 95
#define TANKTEMPERATURE 60
#define AMBIENTTEMPERATURE 17
#define GOTOXY( X, Y ) ((short*)&xyPos)[0]=X,((short*)&xyPos)[1]=Y,SetConsoleCursorPosition( hConsole, xyPos )
#define DEFAULTMESSAGE "Please select                                                     \r"
