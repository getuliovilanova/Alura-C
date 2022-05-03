#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void abertura (){
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta(char ct[26], int* cf){
    char letrainformada; //  letra digitada pelo usuário
    scanf(" %c", &letrainformada);

    ct[(*cf)] = letrainformada; //guarda letra digitada no array chutes
    (*cf)++; // e incrementa a qtd de chutes realizados
}

int main(){
    char palavrasecreta[20];

    sprintf(palavrasecreta,"MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int chutesfeitos = 0;

    abertura();

    do
    {
        for (int i = 0; i < strlen(palavrasecreta); i++){

            int acertouletra = 0;

            for (int x = 0; x < chutesfeitos; x++){
                if(chutes[x] == palavrasecreta [i]){
                    acertouletra = 1;
                    break;
                }
            }

            if(acertouletra){
                printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
            }
            
        }
        printf("\n");

        chuta(chutes, &chutesfeitos);

        
    } while (!acertou && !enforcou);
    
}