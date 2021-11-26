/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:25:21 by suahn             #+#    #+#             */
/*   Updated: 2021/11/15 14:25:24 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

t_dir	init_dir(t_vars *vars)
{
	t_dir	dir;

	dir.rs = vars->r_start;
	dir.re = vars->r_end;
	dir.is = vars->i_start;
	dir.ie = vars->i_end;
	return (dir);
}

t_img	init_img(t_vars *vars)
{
	t_img	img;

	img.bpp = 32;
	img.size_line = W_WIDTH * 4;
	img.endian = 0;
	img.ptr = mlx_new_image(vars->mlx, W_WIDTH, W_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp,
			&img.size_line, &img.endian);
	img.x = 0;
	return (img);
}

t_vars	init_julia(void)
{
	t_vars	vars;

	vars.type = 2;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_WIDTH,
			W_HEIGHT, "julia set");
	vars.r_start = -2;
	vars.r_end = 2;
	vars.i_start = -1;
	vars.i_end = 1;
	vars.zoom = 1;
	vars.cr = 0;
	vars.ci = 0;
	return (vars);
}

t_vars	init_mandelbrot(void)
{
	t_vars	vars;

	vars.type = 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, W_WIDTH,
			W_HEIGHT, "mandelbrot set");
	vars.r_start = -2;
	vars.r_end = 2;
	vars.i_start = -1;
	vars.i_end = 1;
	vars.zoom = 1;
	return (vars);
}
