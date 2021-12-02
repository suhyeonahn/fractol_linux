/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:34:46 by suahn             #+#    #+#             */
/*   Updated: 2021/11/11 14:34:49 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_mandelbrot(t_complex c)
{
	t_complex	z;
	int			n;

	z.r = c.r;
	z.i = c.i;
	n = 1;
	while (ft_abs_complex(z) <= 2 && n < MAX_ITER)
	{
		z = ft_multiple_complex(z, z);
		z.r += c.r;
		z.i += c.i;
		n++;
	}
	return (n);
}

void	mandelbrot_set(t_vars *v)
{
	t_img		img;
	t_complex	c;

	img = init_img(v);
	while (img.x < W_WIDTH)
	{
		img.y = 0;
		while (img.y < W_HEIGHT)
		{
			c.r = (img.x / (double)W_WIDTH) * (v->r_end - v->r_start)
				* v->zoom + v->r_start * v->zoom;
			c.i = (img.y / (double)W_HEIGHT) * (v->i_end - v->i_start)
				* v->zoom + v->i_start * v->zoom;
			img.n = ft_mandelbrot(c);
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

void	mandelbrot_main(void)
{
	t_vars	vars;

	vars = init_mandelbrot();
	mandelbrot_set(&vars);
	mlx_hook(vars.win, 4, 1L << 2, mouse_button_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_loop(vars.mlx);
}
