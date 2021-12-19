#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT 1024
#define WORD 30
#define TRUE 1
#define FALSE 0

// help functions
int isMin(char* word){
    char start = word[0];
    char end = word[strlen(word)-1];
    int res_s = 0;
    int res_e = 0;
    if(start < 91 && start > 64){
        res_s = 1;
    }
    else if(start < 123 && start > 96){
        res_s = 1;
    }
    if(end < 91 && end > 64){
        res_e = 1;
    }
    else if(end < 123 && end > 96){
        res_e = 1;
    }

    if(res_e == 1 && res_s == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int countChr(char* str, char c){
    int res = 0;
    int i;
    for(i = 0; i < strlen(str); i++){
        if(str[i] == c){
            res++;
        }
    }
    return res;
}

int isEqualAtbash(char* s, char* recived){
    int i;
    int j;
    for(i = 0, j = 0; i < strlen(s); i++){
        if(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'){
            continue;
        } 
        else if(s[i] == recived[j]){
            j++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int isEqual(char* s, char* recived){
    int i;
    int cnt_rec;
    int cnt_s;
    for(i = 0; i < strlen(recived); i++){
        if(recived[i] == ' ') continue;
        cnt_rec = countChr(recived, recived[i]);
        cnt_s = countChr(s, recived[i]);

        if(cnt_rec != cnt_s){
            return 0;
        }
    }
    for(i = 0; i < strlen(s); i++){
        if(s[i] == ' ') continue;
        cnt_rec = countChr(recived, s[i]);
        cnt_s = countChr(s, s[i]);

        if(cnt_rec != cnt_s){
            return 0;
        }
    }
    return 1;
}

int toGematri(char* word){ 
    int lower = 96;
    int uper = 64;
    int res = 0;
    int i;
    for(i = 0; i < strlen(word); i++){
        char c = word[i];
        if(c > 96 && c < 123){
            res += (c - lower); // using ascii values
        }
        if(c > 64 && c < 91){
            res += (c - uper); // using ascii values
        }
    }
    return res;
}

char* reverse(char* word){
    char* w = (char*) malloc(WORD);
    if(w){
        int i;
        for(i = 0; i < strlen(word); i++){ 
            w[i] = (char) word[strlen(word) - 1 - i];
        }
        return w;
    }
    else{
        return NULL;
    }
}

// A
void Gematria(char* recieved, char* txt){
    int gimetric_recieved = toGematri(recieved);
    int i;
    int j;
    int start = 0;
    for(i = 0; i < strlen(txt); i++){
        char* curr = txt+i;
        for(j = strlen(curr) - 1; j >= 0 ; j--){
            char* copy = (char*) malloc(TXT);
            strncpy(copy, curr, j);
            if(isMin(copy) == 1){
                int g = toGematri(copy);
                if(g == gimetric_recieved){
                    if(start == 0){
                        printf("%s", copy);
                        start++;
                    }
                    else{
                        printf("~%s", copy);
                    }
                }
            }
            free(copy);
        }
    }
}

// B
char* atbash(char* word){
    char* w = (char*) malloc(WORD);
    if(w){
        int i;
        for(i = 0; i < strlen(word); i++){
            if(word[i] > 96 && word[i] < 123){
                w[i] = (char) (123 - word[i] + 96);
            }
            if(word[i] > 64 && word[i] < 91){
                w[i] = (char) (91 - word[i] + 64);
            }
        }
        return w;
    }
    else {
        return NULL;
    }
}
void Atbash(char* recieved, char* txt){
    int i;
    int j;
    int start = 0;

    char* atba = atbash(recieved);
    char* revers_atba = reverse(atbash(recieved));

    for(i = 0; i < strlen(txt); i++){
        char* curr = txt+i;
        for(j = strlen(curr) - 1; j >= 0 ; j--){
            char* copy = (char*) malloc(TXT);
            strncpy(copy, curr, j);
            if(isMin(copy) == 1){
                if(isEqual(copy, atba) == 1 || isEqual(copy, revers_atba) == 1){
                    if(isEqualAtbash(copy, atba) == 1 || isEqualAtbash(copy, revers_atba) == 1){
                        if(start == 0){
                            printf("%s", copy);
                            start++;
                        }
                        else{
                            printf("~%s", copy);
                        }
                    }
                }
            }
            free(copy);
        }
    }
}

// C
void isAnagram(char* recieved, char* txt){
    int gimetric_recieved = toGematri(recieved);
    int i;
    int j;
    int start = 0;
    for(i = 0; i < strlen(txt); i++){
        char* curr = txt+i;
        for(j = strlen(curr) - 1; j >= 0 ; j--){
            char* copy = (char*) malloc(TXT);
            strncpy(copy, curr, j);
            if(isMin(copy) == 1){
                int g = toGematri(copy);
                if(g == gimetric_recieved && isEqual(copy, recieved) == 1){
                    if(start == 0){
                        printf("%s", copy);
                        start++;
                    }
                    else{
                        printf("~%s", copy);
                    }
                }
            }
            free(copy);
        }
    }
}

int main(){
    char* word = (char*) malloc(WORD);
    if(word){
        int i;
        for(i = 0; i < WORD; i++){
            char c = getchar();
            if(c != '\t' && c != '\n' && c != ' '){
                word[i] = c;
            }
            else{
                word[i] = '\0';
                break;
            }
        }
    }

    char* txt = (char*) malloc(TXT);  
    if(txt){
        int j;
        for(j = 0; j < TXT; j++){
            char c2 = getchar();
            if(c2 != '~'){
                txt[j] = c2;
            }
            else{
                txt[j] = '~';
                txt[j+1] = '\0';
                break;
            }
        }
    }

    // printf("\n");
    printf("Gematria Sequences: ");
    Gematria(word,txt);
    printf("\n");

    printf("Atbash Sequences: ");
    Atbash(word, txt);
    printf("\n");

    printf("Anagram Sequences: ");
     isAnagram(word,txt);
    // printf("\n");

    free(word);
    free(txt);
    return 0;
}