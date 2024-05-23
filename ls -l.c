#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

// Função LS ================================================
int main() {
    struct dirent *de;  // Ponteiro para entrada do diretório
    struct stat fileStat;
    struct tm lt;
    struct passwd *pwd;
    struct group *grp;

    // opendir() retorna um ponteiro de DIR. 
    DIR *dr = opendir(".");

    if (dr == NULL)  // Se não foi possível abrir o diretório
    {
        printf("Não foi possível abrir o diretório atual" );
        return 1;
    }

    // para readdir()
    while ((de = readdir(dr)) != NULL)
    {
        stat(de->d_name, &fileStat);

        /* Print file type */
        printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
        printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
        printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
        printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
        printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
        printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
        printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
        printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
        printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
        printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");

        printf(" %ld", fileStat.st_nlink);

        if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
            printf(" %s", pwd->pw_name);
        else
            printf(" %d", fileStat.st_uid);

        if ((grp = getgrgid(fileStat.st_gid)) != NULL)
            printf(" %s", grp->gr_name);
        else
            printf(" %d", fileStat.st_gid);

        printf(" %5d", (int)fileStat.st_size);

        localtime_r(&fileStat.st_mtime, &lt);
        char timbuf[80];
        strftime(timbuf, sizeof(timbuf), "%c", &lt);

        printf(" %s", timbuf);

        printf(" %s\n", de->d_name);
    }
    closedir(dr);    

    return 0;
}
// ==========================================================