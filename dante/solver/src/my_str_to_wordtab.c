/*
** EPITECH PROJECT, 2018
** my_str_to_wordtab
** File description:
** 
*/

#include <stdlib.h>
#include "../include/my.h"

char	*get_str(char *str, int col, int rst)
{
	static	int	i = 0;
	int		j = 0;
	char		*str2;

	if (rst == 1) {
		i = 0;
		return (0);
	}
	str2 = malloc(sizeof(char) * (col + 1));
	while (col != 0) {
		str2[j++] = str[i++];
		col--;
	}
	str2[j] = '\0';
	i++;
	return (str2);
}

int	get_col(char *str, char cara, int rst)
{
	static	int	i = 0;
	int		col = 0;

	if (rst == 1) {
		i = 0;
		return (0);
	}
	while (str[i] != cara && str[i] != '\0') {
		col++;
		i++;
	}
	i++;
	return (col);
}

int	get_line(char *str, char cara)
{
	int	i = 0;
	int	line = 0;

	while (str[i] != '\0') {
		if (str[i] == cara)
			line++;
		i++;
	}
	return (line + 1);
}

void	reset_static(void)
{
	get_col("\0", 'c', 1);
	get_str("\0", 0, 1);
}

char	**my_str_to_wordtab(char *str, char cara)
{
	int	i = 0;
	int	line = get_line(str, cara);
	int	col = 0;
	char 	**tab;

	tab = malloc(sizeof(char *) * (line + 1));
	while (i != line) {
		col = get_col(str, cara, 0);
		tab[i] = get_str(str, col, 0);
		i++;
	}
	tab[i] = NULL;
	reset_static();
	return (tab);
}