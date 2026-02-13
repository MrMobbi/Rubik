#ifndef RUBIK_H
# define RUBIK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

# define ERR_MSG_ARG "Error: only one argument is needed"
# define ERR_MSG_FILE "Error: file must be a .txt"
# define ERR_MSG_FILE_OPEN "Error: fopen failed"
# define ERR_MSG_MALLOC "Error: Malloc failed"

void	ft_check_file(int ac, char **av);

void	ft_print_error(char *str);

#endif
