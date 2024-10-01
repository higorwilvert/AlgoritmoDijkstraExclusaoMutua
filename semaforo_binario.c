#include "biblioteca_djikastra.h"

#define ITERACOES 10 // Número de iterações que cada processo executará

void processo(int processo)
{
    for (int i = 0; i < ITERACOES; i++)
    {
        // Entrar na seção crítica
        P();

        printf("Processo %d na seção crítica\n", processo);
        sleep(1); // Simula trabalho na seção crítica

        // Sair da seção crítica
        V();

        printf("Processo %d fora da seção crítica\n", processo);
        sleep(1); // Simula trabalho fora da seção crítica
    }
}

int main()
{
    // Inicializa o semáforo binário
    inicializarSemaforo();

    // Criação dos processos filhos
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        processo(0);
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 == 0)
    {
        processo(1);
        exit(0);
    }

    // Espera pelos processos filhos
    wait(NULL);
    wait(NULL);

    // Remove o semáforo
    removerSemaforo();

    return 0;
}
