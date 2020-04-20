/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_next_line
*/

#include "../lib/struckt.h"

int command(char *str)
{
    int y = 0;
    int i = 0;
    pid_t  pid = 0; 
    extern char **environ;
    int line_path = check_extenv("PATH");
    char *tmp = malloc(sizeof(char) * my_strlen(str));
    char *command = malloc(sizeof(char) *my_strlen(str) + 2);
    char **args = malloc(sizeof(char *) * my_strlen(str) + 2);
    char *tmp_path = malloc(sizeof(char) * my_strlen(environ[line_path]) + 1);
    int h = 0;

    for (; *str == ';' || *str == '|'; *str++);
    for(int a = 0; str[a] != ';' && str[a] != '|' && str[a]; tmp[a] = str[a] ,a++);
    tmp[my_strlen(tmp) - 1] == ' ' ? tmp[my_strlen(tmp) - 1] = 0 : 0;
    suprr_space;
    for (; *tmp == ' '; *tmp++);
    recup_arg;
    if (access(my_strcatmall("/bin/",command), X_OK) == 0){
        if (fork() == 0){
            execve(my_strcatmall("/bin/", command), args, environ);
            free(args);
            free(command);
        return (0);
        }
        else waitpid(pid, &pid, WUNTRACED);
        return(0);
    }
    for (int a = 5, i = 0; tmp_path != NULL && environ[line_path][a]; a++, i++) {
        tmp_path[i] = environ[line_path][a];
        if (tmp_path[i] == ':') {
            tmp_path[i] = '/';
            tmp_path[i + 1] = '\0';
            my_strcat(tmp_path,command);
            tmp_path[strlen(tmp_path) + 1] = '\0';
            if (access(tmp_path, X_OK) == 0){
                if (fork() == 0){
                    execve(tmp_path, args, environ);
                    free(args);
                    free(command);
                    return (0);
                }
                else waitpid(pid, &pid, WUNTRACED);
                    return(0);
            }
            access(tmp_path,F_OK) == -1 ? i = 0 : 0;
        }
    }
    return (84);
}

int cd (char *str)
{
    int a = 0;
    int i = 3;
    int b = 0;
    char *path = malloc(sizeof(char) * my_strlen(str));

    suprr_space;
    if (my_strlen(str) == 2)
        return (0);
    while(str[i] && str[i] != ';') {
        path[b] = str[i];
        i++;
        b++;
    }
    for (; *path == ' '; *path++);
    a = chdir(path);
    if (a == -1) {
        my_putstr("cd: aucun fichier ou dossier de ce type: ");
        my_putstr(path);
        my_putstr("\n");
    }
}

void setenv__(char *str) 
{
    free(var->first_argu);
    free(var->second_argu);
    var->first_argu = malloc(sizeof(char *) * my_strlen(str));
    var->second_argu = malloc(sizeof(char *) * my_strlen(str));
    var->ep[var->fin_env] = malloc(sizeof(char *) * my_strlen(str) + 1);
    suprr_space;
    for (int a = 0; a < 7; a++, *str++);
    for (int a = 0, space = 0; a < my_strlen(str); a++) {
        str[a] == ' ' ? space++ : 0;
        if (space >= 2) { 
            my_putstr("setenv: Too many arguments.\n");
            return;
        }
    }
    1 ? first_argu(str), second_argu(str) : 0;
    if (0 != check_extenv(var->first_argu))
        var->ep[check_extenv(var->first_argu)] = my_strcat(var->first_argu,var->second_argu);
    else {
        var->ep[var->fin_env] = my_strcat(var->first_argu,var->second_argu);
        var->fin_env++;
    }
}

int check_extenv(char *str)
{
    int i = 0;
    int e = 0;

    while (i < var->fin_env) {
        while (var->ep[i][e] != '=' && (e++));
        if (0 == my_strncmp(str, var->ep[i], e))
            return (i);
        1 ? i++, e = 0 : 0;
    }
    return (0);
}

void unsetenv__(char *str)
{
    char **tmp_env;
    int a_tmp = 0;
    int b = 0;
    int i = 0;
    int a = 0;

    while (b <= var->fin_env)
        b++;
    suprr_space;
    for (int a = 0; a != 9; *str++, a++);
    suprr_space;
    tmp_env = malloc(sizeof(char *) * (b + 1));
    for (int a = 0; a < var->fin_env; a++)
        tmp_env[a] = malloc(sizeof(char *) * my_strlen(var->ep[a]) + 2);
    if (my_strlen(str) == 0 && (my_putstr("unsetenv: Command not found.\n")))
        return;
    a_tmp = check_extenv(str);
    if (a_tmp == -1)
        return;
    var->ep[a_tmp] = NULL;
    while (a < var->fin_env) {
        var->ep[a] == NULL ? i-- : 1 ? tmp_env[i] = var->ep[a] : 0;
        a++;
        i++;
    }
    for (int a = 0; a < var->fin_env; a++)
        var->ep[a] = tmp_env[a];
    var->fin_env = i;
    free(tmp_env);
}