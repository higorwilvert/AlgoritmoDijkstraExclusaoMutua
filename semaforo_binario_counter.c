#include "biblioteca_djikastra.h"

#define THREADS 2
#define ITERACOES 1000000

int contador = 0; // Variável global para o contador

void *incrementar(void *arg)
{
    for (int i = 0; i < ITERACOES; i++)
    {
        // Entrar na seção crítica
        P();

        contador++; // Incrementa a variável global

        // Sair da seção crítica
        V();
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREADS];

    // Inicializa o semáforo binário
    inicializarSemaforo();

    // Cria as threads
    for (int i = 0; i < THREADS; i++)
    {
        if (pthread_create(&threads[i], NULL, incrementar, NULL) != 0)
        {
            perror("Erro ao criar a thread");
            exit(1);
        }
    }

    // Espera que as threads terminem
    for (int i = 0; i < THREADS; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Erro ao esperar a thread");
            exit(1);
        }
    }

    // Exibe o valor final do contador
    printf("Valor final do contador: %d\n", contador);

    // Remove o semáforo
    removerSemaforo();

    return 0;
}
