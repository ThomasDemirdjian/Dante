/*
** EPITECH PROJECT, 2018
** generator
** File description:
** generator headers maccros structs and protos
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

typedef	struct	s_generator
{
	int	w;
	int	h;
	int	mod;
	char	*maze;
	int	perfect;
} t_gen;

typedef struct	s_built
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dir_x;
	int	dir_y;
	int	dir;
	int	count;
} t_built;

# define ADD_LINE(x)	(x % 2 == 0 ? x + 1 : x)
# define ADD_COL(y)	(y % 2 == 0 ? y + 1 : y)
# define IS_IT_NULL(ah)	if (ah == NULL) exit(EXIT_FAILURE);

void	print_maze(const char *, int, int);
void	built_maze(t_gen *, int, int);
void	check_direction(t_built *);
void	generate_maze(t_gen *);
void	init_gen(t_gen *, char **);
void	init_built(t_built *);

#endif /* !GENERATOR_H_ */
