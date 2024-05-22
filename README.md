# SHELL

## Oque é o Shell

Esse é um programa em C que foi desenvolvido como projeto final  da matéria, Projetos de Sistemas Operacionais, ele tem como objetivo simular as funcionalidade de um terminal Shell de sistemas com base em Linux.

Objetivo:

Desenvolver uma aplicação Shell – interpretador de comandos

Conceitos envolvidos:

Programação em C

Chamadas de sistema

Criação e gerenciamento de processos

Gerenciamento de arquivos

### Passo a Passo de como executar nosso Shell

clone o nosso repositório

Primeiro certifique se de ter a biblioteca ReadLine instalada no seu computador, para faser isso rode o comando:

```sh
sudo apt-get install libreadline-dev
```

Para compilar nosso programa use os comandos:

```sh
gcc -c shell.c -lreadline
```

Em seguida use o comando:

```sh
gcc -o shell shell.o -lreadline
```

Para executar use o comando:

```sh
./shell
```

Nosso Shell vem sem um path definido para busca de executaveis sugerimos definer ele logo que iniciar o progrma com o comando:

```sh
path
```

certifique se de seguir o exemplo de como adicionar um path:

path /home/user/Documentos



## Autores

| [<img src="https://avatars.githubusercontent.com/u/67844545?v=4" width=115><br><sub>Eduardo Silva</sub>](https://github.com/EduardoSilvaS) |  [<img src="https://avatars.githubusercontent.com/u/106974254?v=4" width=115><br><sub>GolfBravoSierra</sub>](https://github.com/GolfBravoSierra) |  [<img src="https://avatars.githubusercontent.com/u/111363981?v=4" width=115><br><sub>VRoston</sub>](https://github.com/VRoston) | [<img src="https://avatars.githubusercontent.com/u/111525582?v=4" width=115><br><sub>Luccavco</sub>](https://github.com/Luccavco) | 
| :---: | :---: | :---: |:---: |
