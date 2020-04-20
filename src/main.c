/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include "../lib/struckt.h"

void fonction_sys(char *str)
{
   // char **sys = malloc(sizeof(char *) * 1000);
    
    //execve(,,)
}

void env(char *str)
{
    suprr_space;
    for (int a = 0; a != var->fin_env; a++) {
        my_putstr(var->ep[a]);
        write(0, "\n", 1);
    }
}

int main(void)
{
    var->ep = NULL;
    char *str = malloc(sizeof(char) * 501);
    int _input = 0;
    extern char **environ;
    int b = 0;
    int z = 0;

    while (environ[b] != NULL)
        b++;
    var->ep = malloc(sizeof(char *) * (b + 1));
    compt_ligne();
    do {
        write(0 , "ZshOlette >> $ ", 16);
        z = read(0, str,500);
        if (z <= 0)
            return(0);
        str[z - 1] = '\0';
        fonction_sys(str);
        _input = detect_input(str);
        input(_input, str);
        _input = 0;
    } while (str);
    return (0);
}

void compt_ligne(void)
{
    int a = 0;
    extern char **environ;

    while (environ[a] != NULL) {
        var->ep[a] = malloc(sizeof(char *) * my_strlen(environ[a]) + 2);
        var->ep[a] = environ[a];
        a++;
    }
    var->fin_env = a;
}

int poin_slash(char *str)
{
    char **args = malloc(sizeof(char *) * my_strlen(str) + 2);
    char *command = malloc(sizeof(char) *my_strlen(str) + 2);
    char *tmp = malloc(sizeof(char) * my_strlen(str));
    extern char **environ;
    int y = 0;
    pid_t  pid = 0;
    for(int a = 0; str[a] != ';' && str[a] != '|' && str[a]; tmp[a] = str[a] ,a++);
    tmp[my_strlen(tmp) - 1] = '\0';
    suprr_space;
    recup_arg;
    args[0] = "";
    suprr_space;
    if (access(tmp, X_OK) != 0) {
        my_putstr(tmp);
        my_putstr(": Command not found.");
        my_putstr("\n");
    }
    if (access(tmp, X_OK) == 0) {
        if (fork() == 0) {
            execve(tmp, args, environ);
            return (0);
        }
        else { 
            waitpid(pid, &pid, WUNTRACED);
            if (WIFSIGNALED(pid))
                WTERMSIG(pid) == 11 ?\
                my_putstr("Segmentation fault (core dumped)\n") :\
                WTERMSIG(pid) == 8 ? my_putstr("Arithmetic error\n") : 0;
                else if (WIFSTOPPED(pid))
                my_putstr("Stopped\n");
        }
    }
}