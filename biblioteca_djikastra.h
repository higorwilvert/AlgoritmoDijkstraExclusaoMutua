// biblioteca_djikastra.h

#ifndef BIBLIOTECA_DJIKASTRA_H
#define BIBLIOTECA_DJIKASTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

// Definição do semáforo binário
int semaforoId; // Identificador do semáforo

// União necessária para a inicialização de semáforos
union uniao_semaforo
{
    int valor; // Valor inicial do semáforo
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

// Função para inicializar o semáforo binário
void inicializarSemaforo()
{
    semaforoId = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666); // Cria um semáforo
    if (semaforoId == -1)
    {
        perror("Erro ao criar o semáforo");
        exit(1);
    }

    // Inicializa o semáforo com valor 1 (binário)
    union uniao_semaforo argumento;
    argumento.valor = 1;
    if (semctl(semaforoId, 0, SETVAL, argumento) == -1)
    {
        perror("Erro ao inicializar o semáforo");
        exit(1);
    }
}

// Função para operação P (wait) no semáforo
void P()
{
    struct sembuf operacao;
    operacao.sem_num = 0;
    operacao.sem_op = -1; // Operação P (wait)
    operacao.sem_flg = 0;
    if (semop(semaforoId, &operacao, 1) == -1)
    {
        perror("Erro na operação de espera (P)");
        exit(1);
    }
}

// Função para operação V (signal) no semáforo
void V()
{
    struct sembuf operacao;
    operacao.sem_num = 0;
    operacao.sem_op = 1; // Operação V (signal)
    operacao.sem_flg = 0;
    if (semop(semaforoId, &operacao, 1) == -1)
    {
        perror("Erro na operação de sinalização (V)");
        exit(1);
    }
}

// Função para remover o semáforo
void removerSemaforo()
{
    if (semctl(semaforoId, 0, IPC_RMID) == -1)
    {
        perror("Erro ao remover o semáforo");
        exit(1);
    }
}

#endif
