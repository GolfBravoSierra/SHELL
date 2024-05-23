#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h> 

// Função LS ================================================
int main() {
    struct dirent *de;  // Ponteiro para entrada do diretório

    // opendir() retorna um ponteiro de DIR. 
    DIR *dr = opendir(".");

    if (dr == NULL)  // Se não foi possível abrir o diretório
    {
        printf("Não foi possível abrir o diretório atual" );
    }

    // para readdir()
    while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);
    }
    closedir(dr);    

    return 0;
}
// ==========================================================