/*
** EPITECH PROJECT, 2018
** built
** File description:
** builting maze functions
*/

#include <stdlib.h>
#include "generator.h"

void	check_direction(t_built *bt)
{
	if (bt->dir == 0) {
		bt->dir_x = 1;
	} else if (bt->dir == 1) {
		bt->dir_y = 1;
	} else if (bt->dir == 2) {
		bt->dir_x = -1;
	} else {
		bt->dir_y = -1;
	}
}

void	built_maze(t_gen *gen, int x, int y)
{
	t_built	*bt = malloc(sizeof(*bt));

	IS_IT_NULL(bt);
	init_built(bt);
	while (bt->count < 4) {
		bt->dir_x = 0;
		bt->dir_y = 0;
		check_direction(bt);
		bt->x1 = x + bt->dir_x;
		bt->y1 = y + bt->dir_y;
		bt->x2 = bt->x1 + bt->dir_x;
		bt->y2 = bt->y1 + bt->dir_y;
		if ((bt->x2 > 0 && bt->x2 < gen->w && bt->y2 > 0 && bt->y2 < gen->h) &&
		(gen->maze[bt->y1 * gen->w + bt->x1] == 1 && gen->maze[bt->y2 * gen->w + bt->x2] == 1)) {
			gen->maze[bt->y1 * gen->w + bt->x1] = 0;
			gen->maze[bt->y2 * gen->w + bt->x2] = 0;
			x = bt->x2;
			y = bt->y2;
			bt->dir = rand() % 4;
			bt->count = 0;
		} else {
			bt->dir = (bt->dir + 1) % 4;
			bt->count += 1;
		}
	}
}