/*
** EPITECH PROJECT, 2018
** main
** File description:
** main functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generator.h"

void	print_maze(const char *maze, int w, int h)
{
	int	col = (h % 2 == 0 ? h + 1 : h);
	int	line = (w % 2 == 0 ? w + 1 : w);

	for (int y = 0; y < col; y++) {
		for (int x = 0; x < line; x++)
			printf("%c", maze[y * w + x] == 1 ? 'X' : '*');
		printf("\n");
	}
}

void	generate_maze(t_gen *gen)
{
	for (int x = 0; x < gen->w * gen->h; x++) {
		gen->maze[x] = 1;
	}
	gen->maze[1 * gen->w + 1] = 0;
	srand(time(0));
	for (int y = 1; y < gen->h; y += 2) {
		for (int x = 1; x < gen->w; x += 2)
			built_maze(gen, x, y);
	}
	gen->maze[0 * gen->w] = 0;
	gen->maze[0 * gen->w + 1] = 0;
	gen->maze[(gen->h - 1) * gen->w + (gen->w - 1)] = 0;
	gen->maze[(gen->h - 2) * gen->w + (gen->w - 1)] = 0;
}

int	main(int ac, char **av)
{
	t_gen *gen = malloc(sizeof(*gen));

	IS_IT_NULL(gen);	
	if ((ac != 3 && ac != 4) || (ac == 4 && av[3][0] != 's'))
		exit(EXIT_FAILURE);
	init_gen(gen, av);
	generate_maze(gen);
	print_maze(gen->maze, gen->w, gen->h);
	free(gen);
	exit(EXIT_SUCCESS);
}