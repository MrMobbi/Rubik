
#include "../incl/rubik.h"

static bool ft_is_correct_file(char *str)
{
	if (strlen(str) < 4)
		return (false);
	else if (strncmp(&str[strlen(str) - 4], ".txt", 4) == 0)
		return (true);
	return (false);
}


void ft_check_file(int ac, char **av)
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

	free(buffer);
	fclose(fd);
}
