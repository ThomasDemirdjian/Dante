/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#ifndef MY_H_
# define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_maze
{
	char	**maze;
	int	**m;
	int	x_max;
	int	y_max;
} t_maze;

int	my_strlen(char *str);
void	print_map(t_maze *m);
void	get_maze(t_maze *maze, char *path);
void	algo(t_maze *m);
void	prepa_maze(t_maze *m);
char	*gnl(int fd);
char	**my_str_to_wordtab(char *str, char cara);

#endif /* !MY_H_ */
