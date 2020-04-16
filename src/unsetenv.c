/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019 [WSL: Debian]
** File description:
** unsetenv.c
*/

#include "../lib/struckt.h"

int second_argu(char *str) 
{
    suprr_space;
    for (int a = 0; a < my_strlen(var->first_argu); a++)
        *str++;
    if (my_strlen(str) == 0){
        return (4);
    }
    var->second_argu = str;
    var->second_argu[my_strlen(str) + 1] = '\0';
    return (0);
}

void first_argu(char *str)
{
    int i = 0;
    suprr_space;
    while (i < my_strlen(str) && str[i] != ' ') {
        var->first_argu[i] = str[i];
        i++;
    }
    var->first_argu[i] = '=';
    var->first_argu[i + 1] = '\0';
}

int f_exit(char *str)
{
    char *string = malloc(sizeof(str));
    suprr_space;
    for (unsigned long i = 0; i < sizeof(str); ++i)
        string[i] = '\0';
    if (my_strlen(str) == 4) {
        free(string);
        return (0);
    }
    for (int a = 0, b = 0; a < my_strlen(str); a++) {
        if (a > 5)
            b++;
        string[b] = str[a];
    }
    free(str);
    return (my_getnbr(string));
}