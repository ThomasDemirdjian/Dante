/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "../include/my.h"

int	check_maze_size(t_maze *m)
{
	int	size = my_strlen(m->maze[0]);
	int	i = 0;

	while (m->maze[i] != NULL) {
		if (my_strlen(m->maze[i]) != size)
			return (-1);
		i++;
	}
	return (0);
}

void	free_all(t_maze *m)
{
	int	i = 0;

	while (m->maze[i] != NULL) {
		free(m->m[i]);
		free(m->maze[i]);
		i++;
	}
	free(m->m);
	free(m->maze);
	free(m);
}

int	main(int ac, char **av)
{
	t_maze	*maze = malloc(sizeof(*maze));

	if (ac != 2)
		return (84);
	get_maze(maze, av[1]);
	if (maze->maze == NULL)
		return (84);
	prepa_maze(maze);
	if (maze->m == NULL || check_maze_size(maze) == -1)
		return (84);
	algo(maze);
	print_map(maze);
	free_all(maze);
}