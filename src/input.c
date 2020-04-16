/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** input
*/

#include "../lib/struckt.h"

int detect_input(char *str)
{
    suprr_space;
    if (str != NULL && my_strlen(str) > 0) {
        if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' \
        && str[3] == 't' && (str[4] == ' ' || str[4] == 0))
            return (1);
        if (str[0] == 'c' && str[1] == 'd')
            return (7);
        if (str[0] == 'e' && str[1] == 'n' && \
        str[2] == 'v' && (str[3] == 0))
            return (3);
        if (str[0] == 's' && str[1] == 'e' && str[2] == 't' && \
        str[3] == 'e' && str[4] == 'n' && str[5] == 'v' && \
        (str[6] == ' ' || str[6] == 0))
            return (6);
        if (str[0] == 'u' && str[1] == 'n' && str[2] == 's' && \
        str[3] == 'e' && str[4] == 't' && str[5] == 'e' && \
        str[6] == 'n' && str[7] == 'v' && str[8] == ' ' && str[9] == '*')
            return (9);
        if (str[0] == 'u' && str[1] == 'n' && str[2] == 's' && \
        str[3] == 'e' && str[4] == 't' && str[5] == 'e' && \
        str[6] == 'n' && str[7] == 'v' && (str[8] == ' ' || str[8] == 0))
            return (8);
        if (str[0] == '.' && str[1] == '/' )
            return(10);
        if (0 != command(str))
        return (9999);
    }
    return (0);
}

void input(int _input, char *str)
{
    extern char **environ;

    str[my_strlen(str) + 1] = '\0';
    if (_input == 9999) {
        my_putstr(str);
        write(0, ": Command not found.", 21);
        write(0, "\n", 1);
        poin_virgule;
    }
    if (_input == 1) {
        my_putstr("exit\n");
        exit(f_exit(str));
    }
    if (_input == 3) {
        env(str);
        poin_virgule;
    }
    if (_input == 6) {
        setenv__(str);
        poin_virgule;
    }
    if (_input == 7) {
        cd(str);
        poin_virgule;
    }
    if (_input == 8) {
        unsetenv__(str);
        poin_virgule;
    }
    if (_input == 9) {
        for (int a = 0; var->ep[a] != NULL; a++)
            var->ep[a] = malloc(sizeof(char *) * my_strlen(var->ep[a]) + 2);
        var->fin_env = 0;
        poin_virgule;
        return;
    }
    if (_input == 10)
        poin_slash(str);
        poin_virgule;
}