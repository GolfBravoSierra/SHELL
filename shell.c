#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h> 

// Definindo constantes =====================================
#define palavra_tamanho 30
#define MAX_path 100
// ==========================================================

// Declaração de Funcções ===================================
char* cdfunction();
char* pathfunction(char *path);
int somafunction(int numero1, int numero2);
char** split_input(char *input);
// ==========================================================

int main(){

    // Declarando variaveis =================================
    char input[100] = ""; 
    char s[600];
    char **path = NULL;
    // ======================================================

    // Obtendo o diretório de trabalho atual ============
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    // ==================================================


    // Laço infinito ========================================
    while(strcmp(input, "exit") != 0)
    {

        // Recebendo input do usuario =======================
        if (getcwd(s, 600) == NULL) 
        {
            strcpy(input, readline("currenty directory is too big>")); 
        }
        else
        {
            printf("%s", s);
            strcpy(input, readline(">"));
        }
        // ==================================================

        // Separando input ==================================
        path = split_input(input);
        // ==================================================

        // Tratamento de entrada ============================
        if (strcmp(path[0], "cd") == 0)
        {   
            // Chamando a função CD ==========================
            cdfunction(path);
            // ===============================================
        }
        else if (strcmp(input, "path") == 0)
        {
            printf("ola de comando");
        }
        else if (strcmp(path[0], "ls") == 0)
        {
            // Crinado processo para funcão ls ==============
            pid_t pid = fork();
            // ==============================================

            // Verificando se o processo foi criado =========
            if (pid == 0)
            {
                // Concatenando o caminho do executável======
                strcat(cwd, "/ls");
                // Chamando a função ls =====================
                execl(cwd, "ls", NULL);
                _exit(0);
                // ==========================================
            }
            else
            {
                int status;
                waitpid(pid, &status, 0);
            }
            // ==============================================

        }
        else if (strcmp(path[0], "exit") == 0)
        {
            break;
        }
        else 
        {
            // Crinado processo =============================
            pid_t pid = fork();
            // ==============================================

            // Verificando se o processo foi criado =========
            if (pid == 0)
            {
                // Procurando o arquivo no PATH ==============
                printf("ola vc esta no exeção fork");
                char *path_env = getenv("PATH");
                if (path_env == NULL) 
                {
                    perror("getenv");
                    _exit(1);
                }

                char *path_copy = strdup(path_env);
                char *dir = strtok(path_copy, ":");
                while (dir != NULL) 
                {
                    char caminho[256];
                    snprintf(caminho, sizeof(caminho), "%s/%s", dir, path[0]);
                    execl(caminho, path[0], NULL);
                    dir = strtok(NULL, ":");
                }
                free(path_copy);

                // Se chegamos a este ponto, então a execução falhou
                perror("execl");
                _exit(1);
                // ==========================================
            }
            else
            {
                int status2;
                waitpid(pid, &status2, 0);
            }
            // ==============================================
        }
        // ==================================================
    }   
    // ======================================================

    // liberando a memoria alocada ==========================
    for (int i = 0; path[i] != NULL; i++) 
    {
        free(path[i]);
    }       
    free(path);
    // ======================================================

    // Limpando o Terminal ==================================
    system("clear");
    // ======================================================

    // Finalizando o programa ===============================
    printf("obrigado por usar nosso shell volte sempre \n");
    // ======================================================

    return 0;
}

// Função CD ================================================
char* cdfunction(char **path){

    // Declarando variaveis =================================
    if (chdir(path[1]) != 0) {
        printf("Erro ao mudar de diretório\n");
        return NULL;
    }
    // ======================================================

    // Declarando variaveis =================================
    char *path2;
    path2 = (char*)malloc(30*sizeof(char));
    // ======================================================

return path[1];
}
// ==========================================================


// Função PATH ==============================================
char* pathfunction(char *path)
{
    // Alocando memória para a nova variável PATH
    char *newPath = (char*)malloc((strlen(getenv("PATH")) + strlen(path) + 2) * sizeof(char));

    // Copiando o PATH atual para a nova variável
    strcpy(newPath, getenv("PATH"));

    // Adicionando o separador
    strcat(newPath, ":");

    // Adicionando o novo diretório
    strcat(newPath, path);

    // Configurando a nova variável PATH
    setenv("PATH", newPath, 1);

    // Liberando a memória alocada
    free(newPath);

    printf("O caminho %s foi adicionado ao PATH\n", path);
    

    return path;
}
// ==========================================================


// Função Separando entrada =================================
char** split_input(char *input) {

    // Declarando variaveis =================================
    char **path = malloc(MAX_path * sizeof(char *));// Aloca memória para um vetor de strings. O número máximo de palavras é definido por MAX_path
    char *word;
    int i = 0;
    // ======================================================

    // Separando a entrada ==================================
    word = strtok(input, " "); //a função strtok é usada para dividir a string em tokens
    // ======================================================

    // Separando a entrada ==================================
    while (word != NULL) 
    {
        path[i] = malloc(strlen(word) + 1); // Aloca memória para a palavra atual
        strcpy(path[i], word); // Copia a palavra atual para o vetor de palavras
        i++; 
        word = strtok(NULL, " "); // Chama a função strtok novamente para pegar a próxima palavra
    }
    // ======================================================

    // Marcando o final do vetor com NULL ===================
    path[i] = NULL; // Marca o final do vetor com NULL
    // ======================================================
    return path;
}
// ==========================================================