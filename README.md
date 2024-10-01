# Projeto de Exclusão Mútua com Semáforos Binários

Por **Higor Wilvert** para a matéria de **Sistemas Operacionais**, lecionada pelo professor **Diego Turazzi**. Ele implementa um sistema de **exclusão mútua** utilizando **semaforos binários** em C, para garantir que múltiplos processos ou threads não acessem a seção crítica ao mesmo tempo.


## Estrutura do Projeto

- **`biblioteca_djikastra.h`**: 
  Contém as funções de inicialização, controle e remoção de semáforos binários.

- **`semaforo_binario_counter.c`**: 
  Implementação que utiliza threads para acessar a seção crítica, com exclusão mútua garantida por semáforos.

- **`semaforo_binario.c`**: 
  Implementação que utiliza processos para acessar a seção crítica, também controlada por semáforos binários.

- **`AlgoritmoDijkstraExclusaoMutua.pdf`**: 
  PDF explicando como funciona o algortimo 


### Instalar Dependências (se necessário)
Caso você ainda não tenha o GCC e o build-essential instalados no seu sistema, rode os seguintes comandos (válido para sistemas Ubuntu/Debian):
```bash
sudo apt-get install build-essential
```

### Compilar o Código
Agora que está tudo pronto, vamos compilar o código. O projeto possui dois arquivos principais que exemplificam o uso de semáforos binários com threads e processos.
```bash
gcc -o semaforo_threads semaforo_binario_counter.c -pthread
```
```bash
gcc -o semaforo_processos semaforo_binario.c -pthread
```

### Executar o Código
Após a compilação, execute os programas gerados:
```bash
./semaforo_threads
```
```bash
./semaforo_processos
```
