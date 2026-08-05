
#include "../incl/rubik.h"

static bool ft_is_correct_file(char *str)
{
	if (strlen(str) < 4)
		return (false);
	else if (strncmp(&str[strlen(str) - 4], ".txt", 4) == 0)
		return (true);
	return (false);
}

bool	ft_is_char_color(char c)
{
	if (c == 'W' || c == 'B' || c == 'R' || c == 'G' || c == '0' || c == 'Y')
		return (true);
	return (false);
}

static char	*ft_get_file(char *str)
{
	FILE *fd = fopen(str, "r");
	if (!fd)
		ft_print_error(ERR_MSG_FILE_OPEN);

	fseek(fd, 0, SEEK_END);
	size_t size = ftell(fd);
	rewind(fd);

	char *buffer = calloc(size +1, sizeof(char));
	if (!buffer)
		ft_print_error(ERR_MSG_MALLOC);
	fread(buffer,1, size, fd);
	printf("File opened:\n%s",buffer);
	fclose(fd);
	return (buffer);
}

static void	ft_check_cube_center(char ***face)
{
	for (int i = 0; i < 6; i++)
		if (!D_CHECK_FACE_CENTER(face[i], i))
			ft_print_error(ERR_MSG_CENTER_FACE);
}

static	void ft_check_colors(char *str)
{
	t_color	*color = calloc(sizeof(t_color), 1);

	while (*str != '\n') 
	{
		if (D_IS_COLOR(*str) == 'W')
			color->count_white++;
		else if (D_IS_COLOR(*str) == 'B')
			color->count_blue++;
		else if (D_IS_COLOR(*str) == 'R')
			color->count_red++;
		else if (D_IS_COLOR(*str) == 'G')
			color->count_green++;
		else if (D_IS_COLOR(*str) == 'O')
			color->count_orange++;
		else if (D_IS_COLOR(*str) == 'Y')
			color->count_yellow++;
		else
			ft_print_error("ERROR: Wrong number of colors\n");
	}
	if (color->count_white > 9)
		ft_print_error("ERROR: Wrong number of colors\n");
	else if (color->count_blue > 9)
		ft_print_error("ERROR: Wrong number of colors\n");
	else if (color->count_red > 9)
		ft_print_error("ERROR: Wrong number of colors\n");
	else if (color->count_green > 9)
		ft_print_error("ERROR: Wrong number of colors\n");
	else if (color->count_orange > 9)
		ft_print_error("ERROR: Wrong number of colors\n");
	else if (color->count_yellow > 9)
		ft_print_error("ERROR: Wrong number of colors\n");
}

static	void ft_check_buffer(char *str)
{
	ft_check_colors(str);
	bool	is_separator	= false;
	int		count_char_face	= 0;
	while (*str != '\n')
	{
		if (*str == '-')
			is_separator = true;
		else if (*str != '\n')
			count_char_face++;
		if (is_separator)
		{
			if (count_char_face != 9)
				ft_print_error("ERROR: Wrong file format\n");
			is_separator = false;
			count_char_face = 0;
		}
		if (count_char_face > 9)
			ft_print_error("ERROR: Wrong file format\n");
		str++;
	}
}

void	ft_check_file(int ac, char **av, t_cube *cube)
{
	if (ac != 2)
		ft_print_error(ERR_MSG_ARG);
	if (ft_is_correct_file(av[1]) == false)
		ft_print_error(ERR_MSG_FILE_TYPE);
	char	*buffer = ft_get_file(av[1]);
	if (strlen(buffer) != D_FILE_SIZE)
		ft_print_error(ERR_MSG_FILE_SIZE);
	ft_check_buffer(buffer);
	cube->face = ft_create_cube(buffer);
	free(buffer);
	ft_db_print_cube(cube);
	ft_check_cube_center(cube->face);
}
