/*
** EPITECH PROJECT, 2018
** tools
** File description:
** tools
*/

#include "../include/my.h"

char	*gnl(int fd)
{
	int	ret = 0;
	int	i = 0;
	char	buff = '0';
	char	*str = malloc(sizeof(char) * 10000);
	char	*str2;

	while (buff != '\n') {
		ret = read(fd, &buff, 1);
		if (ret == 0) {
			free(str);
			return (NULL);
		}
		if (buff != '\n')
			str[i++] = buff;
	}
	str[i] = '\0';
	str2 = malloc(sizeof(char) * my_strlen(str) + 1);
	str2 = strcpy(str2, str);
	free(str);
	return (str2);
}

int	my_strlen(char *str)
{
	int	i = 0;

	if (str != NULL) {
		while (str[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

void	print_map(t_maze *m)
{
	int	i = 0;

	while (m->maze[i] != NULL)
		printf("%s\n", m->maze[i++]);
}