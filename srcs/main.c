
#include "../incl/rubik.h"

static void ft_cube_free(t_cube *cube)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
			free(cube->face[i][j]);
		free(cube->face[i]);
	}
}

int main(int ac, char **av)
{
	t_cube cube = {};
	ft_check_file(ac, av, &cube);
	ft_cube_free(&cube);
	return 0;
}
