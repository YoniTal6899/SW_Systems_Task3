#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT 1024
#define WORD 30

int tm=0;
int InitRem=0;
char atb[WORD];
char reversed[WORD];


int letter_val(char c)
{
    if('A'<=c && c<'Z')
    {
        return ((c-'A'+1));
    }
    else if('a'<=c && c<='z')
    {
        return ((c-'a'+1));
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
    //printf("the val is %d\n",sum);
    return sum;
}
void print_match(char m[WORD], int len)
{
    if(tm>0) printf("~");  
    for(int i=0; i<len; i++)
    {
        printf("%c",m[i]);
    }

    memset(m, 0, len);
}

void G_S(char w[TXT], int val)
{

    char match[WORD];
    memset(match, '\0', WORD);
    int sum=0;
    int counter=0;
    for (int i = 0; i < strlen(w); i++)
    {
        for (int j = i; j < strlen(w); j++)
        {
            if(sum==0 && letter_val(w[j])==0)break;
            sum+=letter_val(w[j]);
            if(sum<val)
            {
                match[counter++]=w[j];
            }
            else if(sum==val)
            {
                match[counter]=w[j];
                counter++;
                match[counter]='\0';
                print_match(match,counter);
                tm++;
                counter=0;
                sum=0;
                memset(match, '\0', WORD);
                break;
            }
            else
            {            
                sum=0;
                memset(match, '\0', WORD);
                counter=0;
                break;
            }           
        }
        memset(match, '\0', WORD);
        sum=0;
        counter=0;       
    }
}


void reverseWord(char w[WORD] ){
    int j = 0;
    for (int i = strlen(w)-1; i >=0; i--)
    {
        reversed[j] = w[i];
        j++;
    }
}
void atbash(char w[WORD])
{
    int index=0;
    for (int i = 0; i < strlen(w); i++)
    {
        if(65<=(int)w[i] && (int)w[i]<=90)
        {
            atb[index]= 'A'+'Z'-w[i];
            index++;
        }
        else if(97<=(int)w[i] && (int)w[i]<=122)
        {
            atb[index]= 'a'+'z'-w[i];
            index++;
        }
        else
        {
            atb[index]=w[i];
            index++;
        }        
    }
    reverseWord(atb);   
} 
int wordCheck (char w[WORD]){
    int atbC = 0;
    int revC = 0;
    for (int i = 0; i < strlen(atb); i++)
    {
        if (w[i] ==atb[i])
        {
            atbC++;
        }
        if (w[i]==reversed[i])
        {
            revC++;
        }
    }
    if (atbC==strlen(atb)||revC==strlen(atb))
    {
        return 1;
    }
    return 0;
}

void AT_S(char t[TXT])
{
    tm=0;
    char check[WORD];
    for (int i = 0; i < strlen(t)-strlen(atb); i++)
    {
        if (t[i]==' ')
        {
            continue;
        }
        int tempI=i;
        for (int j = 0; j < strlen(atb); j++)
        {
            while (t[j+tempI]==' ')
            {
                tempI++;
            }
            check[j]=t[tempI+j];
        }
       if (wordCheck(check))
       {
           print_match(check,WORD);
            tm++;
       }
       memset(check,0,WORD);
    }

}

int isFinished(char* remaining){
    int flag = 1;
    for (int  i = 0; i < strlen(remaining); i++)
    {
        if (remaining[i]!=' ')
        {
            flag=0;
            break;
        }
    }
    if (flag){
        return 1;
    }
    return 0;
}

int match(char* remaining,char c){
    if(c==' ') return 1;
    for (int i = 0; i < strlen(remaining); i++)
    {
        if (c==remaining[i])
        {
            remaining[i] = ' ';
            return 1;
        }        
    }
    return 0;    
}

void print_matchT(char m[WORD], int len)
{
    if(tm>0) printf("~");  
    for(int i=0; i<len; i++)
    {
        printf("%c",m[i]);
    }

    memset(m, 0, len);
}
void InitRemaining(char* r, char w[WORD])
{
    memset(r,0,WORD);
    r[0]=' ';
    for(int i=1; i<=strlen(w);i++)
    {
        r[i]=w[i-1];
    }
}
void Anagram(char w[WORD],char t[TXT]){
    char remaining[WORD];
    tm=0;
    InitRemaining(remaining,w);
    char m[TXT];
    int mindex=0;
    memset(m,0,TXT);
    int start = 1;
    for (int i = 0; i < strlen(t); i++)
    {   
        if(start && t[i]==' '){ 
            continue;
        }
        // if(isFinished(remaining)){
        //     InitRem+=1;
        //     printf("Finised! --> i = %d InitRem = %d\n",i,InitRem);
        //     print_matchT(m,TXT);
        //     tm++;
        //     InitRemaining(remaining,w);
        //     mindex=0;
        //     memset(m,0,TXT);
        //     continue;
        //}
        if (match(remaining,t[i])){
            start=0;
            m[mindex]=t[i];
            mindex++;
            if(isFinished(remaining)){
                start=1;
                print_matchT(m,TXT);
                tm++;
                InitRemaining(remaining,w);
                mindex=0;
                memset(m,0,TXT);
            }
        }
        else{
            start=1;
            i=i-mindex;
            mindex=0;
            memset(m,0,TXT);
            InitRemaining(remaining,w);
        }
    }
} 


int main()
{
    char word[WORD];
    char tmptxt[TXT];
    char tmpwrd[WORD];
    char text[TXT];
    int j=0;
    scanf("%s", tmpwrd);
    scanf("%[^~]", tmptxt);
    for(int i=0; i<strlen(tmpwrd); i++)
    {
        if(tmpwrd[i]=='\\') 
        {
            if(tmpwrd[i+1]=='t' || tmpwrd[i+1]=='n')
                break;
            else
            {
                word[j]=tmpwrd[i];
                j++;
            }
        }
        else
        {
            word[j]=tmpwrd[i];
            j++;
        }            
    }
    j=0;
    for(int i=1; i< strlen(tmptxt); i++)
    {
        text[j]=tmptxt[i];
        j++;
    }
    text[j] = '\0';    
    printf("Gematria Sequences: ");    
    G_S(text,word_val(word));
    printf("\n");
    printf("Atbash Sequences: ");
    atbash(word);
    AT_S(text);
    printf("here \n");
    printf("Anagram Sequences: ");
    Anagram(word,text);    
    return 0;
}