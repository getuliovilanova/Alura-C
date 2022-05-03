#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("\n**********************************************************\n");
    printf("********** Bem vindo(a) ao jogo de adivinhacao! **********\n");
    printf("**********************************************************\n\n");

    int segundos = time(0); // conta os segundos desde 01/01/1970
    srand(segundos); //gera semente para o aleatório

    int aleatorio = rand();

    int numerosecreto = aleatorio % 100;
    int palpite; 
    int tentativa = 1;
    double pontos = 1000;

    int acertou;

    int selecao = 0;
    
    int nivel;

   while (selecao == 0)
    {
        printf("Selecione o nivel de dificuldade\n");
        printf("(1) Facil (2) Medio (3) Dificil: ");
        scanf("%d", &nivel);

        if (nivel < 1 || nivel > 3)
        {
            printf("\nOpcao invalida! Escolha um numero entre 1 e 3\n\n");
        } else{
            selecao = 1;
        }
    }
    
    int numtentativas;

    switch(nivel){
        case 1:
            numtentativas = 20;
            break;
        case 2:
            numtentativas = 15;
            break;
        default:
            numtentativas = 6;
            break;
    }

    printf("\n**********************************************************\n\n");

    for (int i = 1; i <= numtentativas; i++) {

        printf("-> Tentativa %d de %d\n", i, numtentativas);
        printf("Qual eh o seu palpite? ");
        scanf("%d", &palpite);

        if(palpite < 0) {
            printf("Seu palpite nao pode ser um numero negativo!\n\n");
            i--;
            continue;
        }

        acertou = (palpite == numerosecreto);

        if(acertou) {
            break;
        } else if(palpite > numerosecreto) {
            printf("\nSeu chute foi maior do que o numero secreto!\n\n");
        } else {
            printf("\nSeu chute foi menor do que o numero secreto!\n\n");
        }

        double pontosperdidos = abs(palpite - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }

    if(acertou) {
        printf("\nParabens! Voce acertou!\n");
        printf("Voce fez %.1f pontos\n\n", pontos);
    } else {
        printf("Voce perdeu! Tente novamente!\n\n");
    }
    
}