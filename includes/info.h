#ifndef INFO_H
# define INFO_H

# include "mlx_info.h"
# include "vec2.h"

typedef struct s_info
{
	t_mlx_info	mlx_info;
	t_vec		vec;
	int			map_width;
	int			map_height;
}	t_info;

#endif
