#ifndef RUBIK_H
# define RUBIK_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ERR_MSG_ARG "Error: only one argument is needed"
# define ERR_MSG_FILE "Error: file must be a .txt"
# define ERR_MSG_FILE_OPEN "Error: fopen failed"
# define ERR_MSG_MALLOC "Error: Malloc failed"

typedef struct s_cube {
	char			**face;	
	struct s_cube	*next;
}	t_cube;

void	ft_check_file(int ac, char **av, t_cube *cube);
t_cube	*ft_create_cube(char *str);

void	ft_print_error(char *str);

#endif
