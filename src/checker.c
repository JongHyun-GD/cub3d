#include "parser.h"

void	error_exit(char *error_msg)
{
	printf("ERROR: %s\n", error_msg);
	exit(1);
}

void	check_param(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		error_exit("Invalid parameters.");
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 7) != 0)
			error_exit("Invalid parameters.");
	}
}

void	checker(int argc, char **argv)
{
	check_param(argc, argv);
}
