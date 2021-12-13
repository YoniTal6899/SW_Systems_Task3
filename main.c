#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 256
#define WORD 30

void clear_arr(char a[TXT], int len)
{
    for(int i=0; i<len; i++)
    {
        a[i]=NULL;
    }
} 
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
int g_val(char w[WORD])
{
    long len= strlen(w);
    int val=0;
    for(int i=0;i<len;i++)
    {        
        val= val+letter_val(w[i]);     
    }
    return val;
}
void g_match(char w[WORD], char t[TXT])
{
    char match[TXT];
    int w_val= g_val(w);
    int w_len= strlen(w);
    int t_len= strlen(t);
    int diff= t_len-w_len;
    int currsum=0;
    int j=0;
    for(int i=0; i<diff; i++)
    {
        if(currsum < w_val)
        {
            currsum= currsum + letter_val(t[i]);
            match[j]=t[i];
            j++;
        }
        if(currsum==w_val)
        {
            printf(" %s,", match);
            clear_arr(match,j);
            j=0;
        }
        if(currsum>w_val)
        {
            clear_arr(match,j);
            j=0;
        }
    }
}
int main()
{
    char a='1';
    int i;
    int j=0;
    char word[WORD];
    char tmptxt[TXT];
    char tmpwrd[WORD];
    char text[TXT];
    scanf("%s", tmpwrd);
    for(i=0; i<strlen(tmpwrd); i++)
    {
        if(tmpwrd[i]=='\\') 
        {
            if(tmpwrd[i+1]=='t' || tmpwrd[i+1]=='n')
                break;
        }
        else
        {
            word[j]=tmpwrd[i];
            j++;
        }            
    }
    j=0;
    scanf("%s", tmptxt);
    while(tmptxt!=NULL)
    {
        for(i=0; i<strlen(tmptxt); i++)
        {
            if(tmptxt[i]!='~') 
            {
                text[j]=tmptxt[i];
                j++;
            }
        else
            break;

        }
        scanf("%s", tmptxt);    
    }
    printf("The word is: %s\n", word);
    printf("The text is: %s\n", text);
    return 0;
}