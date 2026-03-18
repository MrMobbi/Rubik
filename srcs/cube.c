
#include "../incl/rubik.h"

char	**ft_get_face(char *str)
{
	char	**face = calloc(3,sizeof(char *));
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
			if (*str != '\0')
				str++;
		}
		if (*str == '\n')
			str++;
	}
	return (face);
}

char	***ft_create_cube(char *str)
{
	char	***cube = calloc(6, sizeof(char **));
	char	**splt_str = ft_split(str, '-');

	for (int i = 0; i < 6; i++)
		cube[i] = ft_get_face(splt_str[i]);
	return (cube);
}
