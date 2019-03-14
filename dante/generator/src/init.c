/*
** EPITECH PROJECT, 2018
** init
** File description:
** initialization functions
*/

#include <stdlib.h>
#include "generator.h"

void	init_gen(t_gen *gen, char **av)
{
	gen->w = atoi(av[1]);
	gen->h = atoi(av[2]);
	(gen->w % 2 == 0 ? gen->w += 1 : gen->w);
	(gen->h % 2 == 0 ? gen->h += 1 : gen->h);
	gen->mod = (av[3] != NULL ? 1 : 0);
	if(gen->w < 2 || gen->h < 2)
		exit(EXIT_FAILURE);
	gen->maze = malloc(sizeof(char *) * gen->w * gen->h);
	IS_IT_NULL(gen->maze);
}

void	init_built(t_built *bt)
{
	bt->x1 = 0;
	bt->y1 = 0;
	bt->x2 = 0;
	bt->y2 = 0;
	bt->dir_x = 0;
	bt->dir_y = 0;
	bt->dir = rand() % 4;
	bt->count = 0;
}