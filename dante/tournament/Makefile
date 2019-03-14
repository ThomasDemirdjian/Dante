##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## push_swap
##

all:
	$(MAKE) -C ../generator
	$(MAKE) -C ../solver

clean:
	$(MAKE) clean -C ../generator/
	$(MAKE) clean -C ../solver/

fclean:	clean
	$(MAKE) fclean -C ../generator/
	$(MAKE) fclean -C ../solver/

re:     fclean all

.PHONY: all clean fclean re