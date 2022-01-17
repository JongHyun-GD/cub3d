#ifndef VEC2_H
# define VEC2_H

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

t_vec2	v2_plus(t_vec2 v1, t_vec2 v2);
t_vec2	v2_minus(t_vec2 v1, t_vec2 v2);
t_vec2	v2_scala(double a, t_vec2 v);

typedef struct s_vec2int
{
	int	x;
	int	y;
}	t_vec2int;

#endif
