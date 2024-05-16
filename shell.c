#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <linux/limits.h>

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


    // Laço infinito ========================================
    while(strcmp(input, "exit") != 0)
    {
        
        // Limpando o Terminal ==============================
        //system("clear"); // DESCOMENTAR ANTES DE ENTREGAR
        // ==================================================

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
        for (int i = 0; path[i] != NULL; i++) { // TIRE ANTES DE ENTREGAR
            printf("Palavra %d: %s\n", i, path[i]);
        }
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
    printf("obrigado volte sempre \n");
    // ======================================================

    return 0;
}

// Função CD ================================================
char* cdfunction(char **path){

    //printf("ola vc esta np cd ps tirar isso depois"); // TIRE ANTES DE ENTREGAR
    chdir(path[1]);    

    for (int i = 0; path[i] != NULL; i++) { // TIRE ANTES DE ENTREGAR
        printf("Palavra %d: %s\n", i, path[i]);
    }

    // Declarando variaveis =================================
    char *path2;
    path2 = (char*)malloc(30*sizeof(char));
    // ======================================================


return path[1];
}
// ==========================================================


// Função PATH ==============================================
char* pathfunction(char *path){

    printf("ola vc esta np path");    


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


// partes do codigo que foram comentadas para serem implementadas depois
// ou que deram errado mesmo
/*
    // Crinado processo para funcão CD ==============
    pid_t pid = fork();
    // ==============================================

    // Verificando se o processo foi criado =========
    if (pid < 0)
    {
        perror("fork");
        return NULL;
    }
    // ==============================================

    // Processo filho executa cd ====================
    if (pid == 0)
    {
        printf("ola vc esta np cd");
        exit(0);
    }
    else
    {
        wait(NULL);
    }
    // ============================================== 

    // Verificando se o diretório existe ====================
    while(flag == 1)
    {
        if(chdir(path) != 0) 
        {
            perror("chdir");
            flag = 1;
            printf("Diretório não encontrado, tente novamente:\n>");
            scanf("%s", path);
        }
    }
    // ======================================================
    printf("Agora você está no diretório %s\n", path);

    // Recebendo o caminho do diretório e tratando entrada ==
    while (flag == 0)
    {
        printf("\n cd>");
        scanf("%s", path);

        // Verificando se o diretório existe ================
        if (chdir(path) == 0)
        {
            flag = 1;
        }
        else
        {
            printf("\n diretorio nao encontrado \n");
        }
        // ==================================================
    }
    // ======================================================




        // Crinado processo para funcão CD ======================
    pid_t pid = fork();
    // ======================================================

    // Verificando se o processo foi criado =================
    if (pid < 0)
    {
        perror("fork");
        return path2;
    }
    // ======================================================  

    // Processo filho executa cd ============================
    if (pid == 0)
    {
        printf("ola vc esta np cd");
        // procurando o diretório ===========================
        if(chdir(path) != 0) 
        {
            perror("chdir");
            return path;
        }
        //printf("Agora você está no diretório %s\n", path);
        return path;
        // ==================================================
    }
    else
    {
        wait(NULL);
    }

    // ======================================================


    // Função Separando entrada =================================
    void split_input(char *input, char *instruction, char *path) {

    // Declarando variaveis =================================
    char *token = strtok(input, " "); //a função strtok é usada para dividir a string em tokens
    // ======================================================

    // Separando a entrada ==================================
    if (token != NULL) //verifica se a primeira palavra esta vazia
    {
        strcpy(instruction, token);// copiando a primeira palavra para a variavel instruction
        token = strtok(NULL, " ");// chamando a função strtok novamente para pegar a segunda palavra
    }

    if (token != NULL)  // segundo if para ver se o resto da string esta vazia
    {
        strcpy(path, token); // copiando a segunda palavra para a variavel path (resto da frase)
    }
    // ======================================================
}
// ==========================================================

*/