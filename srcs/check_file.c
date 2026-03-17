
#include "../incl/rubik.h"
#include <stdio.h>
void	ft_cube_free(t_cube *cube);

static bool ft_is_correct_file(char *str)
{
	if (strlen(str) < 4)
		return (false);
	else if (strncmp(&str[strlen(str) - 4], ".txt", 4) == 0)
		return (true);
	return (false);
}

void	ft_check_file(int ac, char **av, t_cube *cube)
{
	if (ac != 2)
		ft_print_error(ERR_MSG_ARG);
	if (ft_is_correct_file(av[1]) == false)
		ft_print_error(ERR_MSG_FILE);
	FILE *fd = fopen(av[1], "r");
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

	cube = ft_create_cube(buffer);
	ft_cube_free(cube);
	free(buffer);
	fclose(fd);
}

static bool	ft_is_char_color(char c)
{
	if (c == 'W' || c == 'B' || c == 'R' || c == 'G' || c == '0' || c == 'Y')
		return (true);
	return (false);
}

static char	*ft_go_to_next_face(char *str)
{
	while (*str != '\0' && !ft_is_char_color(*str))
		str++;
	return (str);
}

char	**ft_get_face(char *str)
{
	char	**face = calloc(4,sizeof(char *));
	if (!face)
		ft_print_error(ERR_MSG_MALLOC);
	for (int i = 0; i < 3; i++)
	{
		face[i] = calloc(4, sizeof(char));
		if (!face[i])
			ft_print_error(ERR_MSG_MALLOC);
		for (int j = 0; j < 3; j++)
		{
			face[i][j] = *str;
			str++; //TODO check str for no seg fault
		}
		if (*str == '\n')
			str++;
		printf("face[%d] : [%s]\n", i, face[i]);	
	}
	return (face);
}

t_cube	*ft_create_cube(char *str)
{
	t_cube	*cube = malloc(sizeof(t_cube));
	if (!cube)
		ft_print_error(ERR_MSG_MALLOC);
	str = ft_go_to_next_face(str);
	cube->face = ft_get_face(str);
	cube->next = NULL;
	printf("\n\n--- \ntest :%s", str);
	return (cube);
}

void	ft_cube_free(t_cube *cube)
{
	free(cube);
}
