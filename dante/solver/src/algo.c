/*
** EPITECH PROJECT, 2018
** algo
** File description:
** algo
*/

#include "../include/my.h"

void	fill_nbr(int i, int j, int nbr, t_maze *m)
{
	nbr += 1;
	if (i > 0 && (m->m[i - 1][j] == 0))
		m->m[i - 1][j] = nbr;
	if (j > 0 && (m->m[i][j - 1] == 0))
		m->m[i][j - 1] = nbr;
	if (i < (m->y_max - 1) && (m->m[i + 1][j] == 0))
		m->m[i + 1][j] = nbr;
	if (j < (m->x_max - 1) && (m->m[i][j + 1] == 0))
		m->m[i][j + 1] = nbr;
}

void	find_nbr(t_maze *m, int nbr)
{
	int	i = 0;
	int	j = 0;

	while (i != (m->y_max - 1)) {
		while (j != m->x_max) {
			if (m->m[i][j] == nbr)
				fill_nbr(i, j, nbr, m);
			j++;
		}
		j = 0;
		i++;
	}
}

void	fill_good_path(t_maze *m)
{
	int	i = (m->y_max - 1);
	int	j = (m->x_max - 1);
	int	nbr = m->m[i][j];

	m->maze[i][j] = 'o';
	while (nbr != 0) {
		if (i > 0 && (m->m[i - 1][j] == nbr - 1))
			i--;
		else if (j > 0 && (m->m[i][j - 1] == nbr - 1))
			j--;
		else if (i < (m->y_max - 1) && (m->m[i + 1][j] == nbr - 1))
			i++;
		else if (j < m->x_max && (m->m[i][j + 1] == nbr - 1))
			j++;
		m->maze[i][j] = 'o';
		nbr--;
	}
}

void	algo(t_maze *m)
{
	int	nbr = 1;

	m->m[0][0] = 1;
	while (m->m[m->y_max - 1][m->x_max - 1] == 0) {
		find_nbr(m, nbr);
		nbr++;
	}
	fill_good_path(m);
}