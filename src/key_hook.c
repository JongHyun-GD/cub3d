#include "key_hook.h"

int	key_hook(int keycode, t_info *info)
{
	double	rot_speed;
	t_vec2	old_dir;
	t_vec2	old_fov;

	rot_speed = 0.3;
	if (keycode == KEY_ESC)
        exit(0);
	if (keycode == KEY_W) {
		printf("Key W pressed\n");
		info->p_pos = v2_plus(info->p_pos, info->p_dir);
		render(info);
	}
	if (keycode == KEY_S) {
		printf("Key S pressed\n");
		info->p_pos = v2_minus(info->p_pos, info->p_dir);
		render(info);
	}
	if (keycode == KEY_A) {
		printf("Key A pressed\n");
		old_dir = info->p_dir;
		old_fov = info->p_fov;
		info->p_dir.x = old_dir.x * cos(rot_speed) - old_dir.y * sin(rot_speed);
      	info->p_dir.y = old_dir.x * sin(rot_speed) + old_dir.y * cos(rot_speed);
      	info->p_fov.x = old_fov.x * cos(rot_speed) - old_fov.y * sin(rot_speed);
    	info->p_fov.y = old_fov.x * sin(rot_speed) + old_fov.y * cos(rot_speed);
		render(info);
	}
	if (keycode == KEY_D) {
		printf("Key D pressed\n");
		old_dir = info->p_dir;
		old_fov = info->p_fov;
		info->p_dir.x = old_dir.x * cos(-rot_speed) - old_dir.y * sin(-rot_speed);
      	info->p_dir.y = old_dir.x * sin(-rot_speed) + old_dir.y * cos(-rot_speed);
      	info->p_fov.x = old_fov.x * cos(-rot_speed) - old_fov.y * sin(-rot_speed);
    	info->p_fov.y = old_fov.x * sin(-rot_speed) + old_fov.y * cos(-rot_speed);
		render(info);
	}
	return (0);
}
