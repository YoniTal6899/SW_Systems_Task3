#ifndef HEADERS
#define HEADERS

#define TXT 1024
#define WORD 30

void printGimatriaWords(int value, char txt[]);
void updateToPrintSTR(char txt[], int i, int j, char to_print[]);
void changeAtbash(char str[]);
int sameLettersOrder(char txt[], int i, int j, char word[]);
void printAtbashWords(char word[], char txt[]);
int reverseLettersOrder(char txt[], int i, int j, char word[]);
void deleteChar(char str[], int index);
void printAnagram(char word[], char txt[]);
void changeAtbash(char str[]);
int getLocation(char word[], char ch);

#endif