/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_next_line
*/

#include "../lib/struckt.h"

int create_buffer(int fd, char *buffer, int f)
{
    char *buff = malloc(sizeof(char) * (10 * 3000));
    
    for (int j = 0, k = 0, fin = 1; fin > 0; j = 0) {
        for (int i = 0; i < (10); ++i)
            buff[i] = '\0';
        fin = read(fd, buff, 10);
        while (buff[j] != '\0' && fd != 0) {
            buff[j] == '\n' ? f++ : 0;
            buffer[k++] = buff[j++];
        }
        for (int j = 0; buff[j] != '\0' && fd == 0; j++) {
            if (buff[j] == '\n') {
                free(buff);
                buffer[k] = '\0';
                return (1);
            }
            buffer[k++] = buff[j];
        }
    }
    free(buff);
    return (f);
}

char *get_next_line(int fd)
{
    static char buffer[1000000];
    static int f = 1;
    char *buffer_empty = malloc(sizeof(char) * (50 * 3000));
    int i = 0;
    int j = 0;
    if (fd < 0 || 10 <= 0)
        return (NULL);
    f = create_buffer(fd, buffer, f);
    while (buffer[i] != '\n' && f > 0) {
        if (buffer[i] == '\0')
            break;
        buffer_empty[j++] = buffer[i++];
    }
    for (int j = 0, k = i + 1; buffer[j] && (buffer[j] = buffer[k]); j++, k++);
    f--;
    if (buffer_empty[0] == '\0' && f == 0)
        return (NULL);
    buffer_empty[j] = '\0';
    return (f < 0 ? NULL : buffer_empty);
}