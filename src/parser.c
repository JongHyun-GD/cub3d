#include "parser.h"

void	parser(int argc, char **argv, t_info *info)
{
	info->p_pos.x = 20;
	info->p_pos.y = 12;
	info->p_dir.x = -1;
	info->p_dir.y = 0;
	info->p_fov.x = 0;
	info->p_fov.y = 0.66;
	info->map_height = 24;
	info->map_width = 24;
	(void)argc;
	(void)argv;
	return ;
}
