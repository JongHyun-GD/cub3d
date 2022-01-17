#ifndef MLX_INFO_H
# define MLX_INFO_H

# define WIN_TITLE "cub3d"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct s_mlx_info
{
	void	*mlx;
	void	*mlx_win;
	int		win_height;
	int		win_width;
}	t_mlx_info;

#endif
