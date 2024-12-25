#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // imprime o cabeçalho do jogo
    printf("---------------------------------------\n");
    printf("- Bem vindo ao jogo de adivinhacao :) -\n");
    printf("---------------------------------------\n");

    // conseguindo executar a aleatorização
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();

    // número secreto
    int numero = numerogrande % 100;

    int chute;
    int ganhou = 0;

    // pontuação
    double pontos = 1000.00;
    
    // recebe o chute do usuário
    while (ganhou == 0){    
        printf("Qual o seu chute? ");
        scanf("%d", &chute);

        // Tratemtno de erros
        if (chute < 0) {
            printf("Você não pode chutar numeros negativos\n");
            continue;
        }
        
        printf("seu chute foi %d\n", chute);

        int acertou = (chute == numero);

        // condicionais
        if(acertou) {
            printf("Voce acertou!\n");
            ganhou = 1;
        }
        else if(chute > numero) {
            printf("Seu chute foi maior que número secreto\n");
        }
        else{
            printf("Seu chute foi menor que o número secreto\n");  
        }
        double pontosperdidos = abs(chute - numero) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("Fim de Jogos\n");
    printf("Sua pontuação foi de %.1f", pontos);
}
