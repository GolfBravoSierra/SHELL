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
int main(int argc, char *argv[]) {
    struct dirent *de;  // Ponteiro para entrada do diretório
    int flag = 0;
    struct stat fileStat;
    struct tm lt;
    struct passwd *pwd;
    struct group *grp;
        // opendir() retorna um ponteiro de DIR. 
    DIR *dr = opendir(".");
    if (argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-a") == 0)
            {
                if(flag == 2)
                {
                    flag = 3;
                }
                else
                {
                    flag = 1;
                }
            }
            if (strcmp(argv[i], "-l") == 0)
            {
                if(flag == 1)
                {
                    flag = 3;
                }
                else
                {
                    flag = 2;
                }
            }
            if (strcmp(argv[i], "-la") == 0 || strcmp(argv[i], "-al") == 0)
            {
                flag = 3;
            }
        }
        
    }


    switch (flag)
    {
        case 1:
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
        break;
    case 2:
        if (dr == NULL)  // Se não foi possível abrir o diretório
        {
            printf("Não foi possível abrir o diretório atual" );
            return 1;
        }

        // para readdir()
        while ((de = readdir(dr)) != NULL)
        {
            if (de->d_name[0] != '.')
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
        }
        closedir(dr);

        break;
    case 3:
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
        break;
    default:
            if (dr == NULL)  // Se não foi possível abrir o diretório
        {
            printf("Não foi possível abrir o diretório atual" );
        }

        // para readdir()
        while ((de = readdir(dr)) != NULL)
        {
            if (de->d_name[0] != '.')
                printf("%s\n", de->d_name);
        }
        closedir(dr);  
        break;
    }

  

    return 0;
}
// ==========================================================