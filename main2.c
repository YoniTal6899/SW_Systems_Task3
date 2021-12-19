#include <stdio.h>
#include <string.h>
#include "actions.h"

#define TXT 1024
#define WORD 30

int letter_val(char c)
{
    if(65<=(int)c && (int)c<=90)
    {
        return ((c-64));
    }
    else if(97<=(int)c && (int)c<=122)
    {
        return ((c-96));
    }
    return 0;
}
int word_val(char w[WORD])
{    
    int sum=0;
    for(int i=0; i<strlen(w); i++)
    {
        sum+=letter_val(w[i]);
    }
    return sum;
}

int main()
{
    char word[WORD];
    char text[TXT];    
    int index = 0;
    char tmp = getchar();
    while(tmp!=' ' && tmp!='\t' && tmp!='\n'){
        word[index] = tmp;
        tmp = getchar();
        index++;
    }
    index=0;
    tmp=getchar();
    while('~'!=tmp){
        text[index] = tmp;
        tmp = getchar();
        index++;
    }    
    int val = word_val(word);

    printf("Gematria Sequences: ");
    printGimatriaWords(val, text);
    printf("\n");
    
    printf("Atbash Sequences: ");
    printAtbashWords(word, text);
    printf("\n");

    printf("Anagram Sequences: ");
    printAnagram(word, text);
    
    return 0;
}