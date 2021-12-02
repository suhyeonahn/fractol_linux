/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:34:33 by suahn             #+#    #+#             */
/*   Updated: 2021/11/11 14:34:36 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	bright(t_img *img)
{
	img->bright = img->n / (double)MAX_ITER * 10;
	img->bright = sqrt(img->bright) * 255;
	if (img->n == MAX_ITER)
		img->bright = 0;
}

double	julia(t_complex z, t_vars *vars)
{
	double	rr;
	double	ii;
	double	two_ri;
	double	n;

	n = 0;
	while (ft_abs_complex(z) <= 2 && n < MAX_ITER)
	{
		rr = z.r * z.r;
		ii = z.i * z.i;
		two_ri = 2.0 * z.r * z.i;
		z.r = rr - ii + vars->cr;
		z.i = two_ri + vars->ci;
		n++;
	}
	return (n);
}

void	julia_set(t_vars *v)
{
	t_img		img;
	t_complex	z;

	img = init_img(v);
	while (img.x < W_WIDTH)
	{
		img.y = 0;
		while (img.y < W_HEIGHT)
		{
			z.r = (img.x / (double)W_WIDTH) * (v->r_end - v->r_start)
				* v->zoom + v->r_start * v->zoom;
			z.i = (img.y / (double)W_HEIGHT) * (v->i_end - v->i_start)
				* v->zoom + v->i_start * v->zoom;
			img.n = julia(z, v);
			bright(&img);
			img.data[(W_WIDTH * (int)img.y) + (int)img.x]
				= img.bright * 256 * 256 + img.bright * 256 + img.bright;
			img.y++;
		}
		img.x++;
	}
	mlx_put_image_to_window(v->mlx, v->win, img.ptr, 0, 0);
	mlx_destroy_image(v->mlx, img.ptr);
}

void	julia_main(void)
{
	t_vars	vars;

	vars = init_julia();
	julia_set(&vars);
	mlx_loop_hook(vars.mlx, mouse_move_hook, &vars);
	mlx_hook(vars.win, 4, (1L << 2), mouse_button_hook, &vars);
	mlx_hook(vars.win, 2, (1L << 0), key_press, &vars);
	mlx_loop(vars.mlx);
}
