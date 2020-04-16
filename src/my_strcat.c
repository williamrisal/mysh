/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019 [WSL: Debian]
** File description:
** my_strcat.c
*/

#include "../lib/struckt.h"

char *my_strcatmall(char *dest, char *src)
{
    char *str = malloc(sizeof(char) * ((sizeof(dest) + sizeof(src)) * 4) + 1);
    int e = 0;
 
    for (int i = 0; dest[i]; i++)
        str[e++] = dest[i]; 
    for (int i = 0; src[i]; i++)
        str[e++] = src[i];
    str[e] = '\0';
    return (str);
}

char *my_strcat(char *dest, char *src)
{
    int	i;
    int	j;

    j = 0;
    i = my_strlen(dest);
    while (src[j] != '\0') {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}