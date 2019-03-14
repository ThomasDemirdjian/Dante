/*
** EPITECH PROJECT, 2018
** prepa_maze.c
** File description:
** prepa_maze
*/

#include "../include/my.h"

void	get_size_maze(t_maze *m)
{
	int	i = 0;

	while (m->maze[i] != NULL)
		i++;
	m->y_max = i;
	m->x_max = my_strlen(m->maze[0]);
}

int	check_maze_cara(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] != 'X' && str[i] != '*' && str[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	*fill_line(char *str, int *m)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] == '*')
			m[i] = 0;
		else
			m[i] = -1;
		i++;
	}
	return (m);
}

void	prepa_maze(t_maze *m)
{
	int	i = 0;

	m->m = malloc(sizeof(int *) * m->y_max);
	while (i != m->y_max) {
		m->m[i] = malloc(sizeof(int) * m->x_max);
		m->m[i] = fill_line(m->maze[i], m->m[i]);
		i++;
	}
}

void	get_maze(t_maze *maze, char *path)
{
	int	fd = open(path, O_RDONLY);
	char	*str = malloc(sizeof(char) * 1);
	char	*tmp;

	if (fd == -1)
		return ;
	str[0] = '\0';
	while ((tmp = gnl(fd)) != NULL) {
		str = realloc(str, (my_strlen(str) + my_strlen(tmp) + 2));
		str = strcat((str = strcat(str, tmp)), "\n");
		free(tmp);
	}
	if (check_maze_cara(str) == -1)
		return ;
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	maze->maze = my_str_to_wordtab(str, '\n');
	free(str);
	get_size_maze(maze);
}