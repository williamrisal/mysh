#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(char **av,int ac, char **env)
{
	int a = 0;
	int b = 5;
	int c = 0;
	char **path = malloc(sizeof(char *) *1000);

	path[0] = malloc(sizeof(char *) *1000);
	while(env[a] != NULL){
		if(env[a][0] == 'P' && env[a][1] == 'A' && env[a][2] == 'T')
			while(1){
				path[0][c] = env[a][b];
				b++;
			}
				a++;
	}
	printf("%s\n", path[0] );
	return(0);
}