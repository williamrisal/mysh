/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** function_sys
*/

#include "../lib/struckt.h"

int	my_getnbr(char *str)
{
    int	nb = 0;
    int	isneg = 1;
    int	i = 0;

    while (str[i] == '+' || str[i] == '-')
        str[i] == '-' ? isneg = isneg * -1, i++ : i++;
    while (str[i] != '\0') {
        if (str[i] < '0' && str[i] > '9') {
            return (nb * isneg);
        }
	    nb = nb * 10;
	    nb = nb + str[i] - '0';
	    i++;
    }
    return (nb * isneg);
}

int my_strlen(char * str)
{
    int y = 0;

    while (str[y] != '\0')
        y++;
    return (y);
}

void my_put_nbr(int nb)
{
    int	mod;

    nb < 0 ? my_putchar('-'), nb = nb * (-1) : 0;
    nb >= 0 ? nb >= 10 ? mod = (nb % 10), nb = (nb - mod) / 10, \
    my_put_nbr(nb), my_putchar(48 + mod) : my_putchar(48 + nb % 10) : 0;
}

int my_putstr(char *str)
{
    if (str == NULL)
        return (-1);
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (1);
}

void my_putchar(char c)
{
    write(0, &c, 1);
}