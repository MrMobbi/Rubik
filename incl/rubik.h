#ifndef RUBIK_H
# define RUBIK_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ERR_MSG_ARG "Error: only one argument is needed"
# define ERR_MSG_STR_FILL "Error: String ended in the middle of the fill"
# define ERR_MSG_FILE_TYPE "Error: file must be a .txt"
# define ERR_MSG_FILE_SIZE "Error: File must be 60 bytes"
# define ERR_MSG_FILE_OPEN "Error: fopen failed"
# define ERR_MSG_MALLOC "Error: Malloc failed"
# define ERR_MSG_CENTER_FACE "Error: Wrong center color"

# define D_WHITE	"\033[0m"
# define D_BLUE		"\033[34m"
# define D_RED		"\033[31m"
# define D_GREEN	"\033[32m"
# define D_ORANGE	"\033[38;5;208mO\033[0m"
# define D_YELLOW	"\033[33m"

# define D_FILE_SIZE 60

# define D_FACE_COLOR(face_nb)\
	((face_nb == E_WHITE) ? 'W' : \
	 (face_nb == E_BLUE) ? 'B' : \
	 (face_nb == E_RED) ? 'R' : \
	 (face_nb == E_GREEN) ? 'G' : \
	 (face_nb == E_ORANGE) ? 'O' : \
	 (face_nb == E_YELLOW) ? 'Y' : '?')

#define D_CHECK_FACE_CENTER(face, face_nb) \
    ((face)[1][1] == D_FACE_COLOR(face_nb))

typedef struct s_cube {
	int		moves;
	char	***face;
}	t_cube;

enum e_color {
	E_WHITE = 0,
	E_BLUE = 1,
	E_RED = 2,
	E_GREEN = 3,
	E_ORANGE = 4,
	E_YELLOW = 5,
};

enum e_orientaion {
	E_UP = 0,
	E_RIGHT = 1,
	E_LEFT = 2,
	E_BACK = 3,
	E_FRONT = 4,
	E_DOWN = 5,
};


void	ft_check_file(int ac, char **av, t_cube *cube);
char	***ft_create_cube(char *str);
bool	ft_is_char_color(char c);

void	ft_db_print_cube(t_cube *cube);
void	ft_print_error(char *str);

char	**ft_split(char const *str,  char c);

#endif
