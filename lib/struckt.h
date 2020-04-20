/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** struckt
*/

#ifndef STRUCKT_H_
#define STRUCKT_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define var mglobal()
#define vag jglobal()
#define poin_virgule for (int a = 0; *str != ';' &&*str != '|' && *str != '\0' && *str != 0; *str++,a++); \
                     detect_input(str);
#define suprr_space for (; *str == ' '; *str++);
#define recup_arg for (int a = 0; tmp[a] != ' ' && tmp[a]; a++) \
    command[a] = tmp[a]; \
    command[my_strlen(command)] = '\0'; \
    for (int i = 0, x = 0; i <= my_strlen(tmp); x = 0, i++, y++) { \
        args[y] = malloc(sizeof(char) * 501); \
        for (;tmp[i] != ' ' && tmp[i] && tmp[i] != ';' && tmp[i] != '|' && tmp[i] != '\n'; x++, i++){ \
        args[y][x] = tmp[i];\
        }\
        args[y][x] = '\0'; \
    }
    
int create_buffer(int fd, char *buffer, int f);
char *get_next_line(int fd);

int	my_getnbr(char *str);
int my_strlen(char * str);
int poin_slash(char *str);
void my_put_nbr(int nb);
int my_putstr(char *str);
void my_putchar(char c);

int cd(char *str);
void input(int _input, char *str);
int detect_input(char *str);
void env(char *str);
void checksetenv(void);
struct gb *mglobal(void);
int	my_strcmp(char *s1, char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char *src);
int copy_first(char *str, char dest);
int command(char *str);
int my_strncmp(char *s1, char *s2, int n);
void setenv__(char *str);
int check_extenv(char *str);
void unsetenv__(char *str);
void first_argu(char *str);
int second_argu(char *str);
void compt_ligne(void);
char *my_strcatmall(char *dest, char *src);
int f_exit(char *str);

typedef struct gb {
    char **ep;
    int fin_env;
    char *first_argu;
    char *second_argu;
}glb;

#endif /* !STRUCKT_H_ */