/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:30:20 by suahn             #+#    #+#             */
/*   Updated: 2021/12/01 15:25:40 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	render(t_vars *vars)
{
	if (vars->type == 1)
		mandelbrot_set(vars);
	else if (vars->type == 2)
		julia_set(vars);
}

void	scroll(int button, t_vars *vars, t_dir dir)
{
	if (button == SCROLL_UP)
	{
		vars->r_start -= (dir.re - dir.rs) * 0.75;
		vars->i_start -= (dir.ie - dir.is) * 0.75;
		vars->r_end = vars->r_start + (dir.re - dir.rs) * 1.5;
		vars->i_end = vars->i_start + (dir.ie - dir.is) * 1.5;
		vars->zoom *= 1.5;
	}
	else if (button == SCROLL_DOWN)
	{
		vars->r_start -= (dir.re - dir.rs) / 3;
		vars->i_start -= (dir.ie - dir.is) / 3;
		vars->r_end = vars->r_start + (dir.re - dir.rs) / 1.5;
		vars->i_end = vars->i_start + (dir.ie - dir.is) / 1.5;
		vars->zoom /= 1.5;
	}
}

int	mouse_button_hook(int button, int x, int y, t_vars *vars)
{
	t_dir	dir;

	dir = init_dir(vars);
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		vars->r_start = (double)x / (double)W_WIDTH
			* (dir.re - dir.rs) + dir.rs;
		vars->i_start = (double)y / (double)W_HEIGHT
			* (dir.ie - dir.is) + dir.is;
		scroll(button, vars, dir);
		render(vars);
	}
	return (0);
}

int	mouse_move_hook(t_vars *vars)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	vars->cr = (double)x / (double)W_WIDTH * (R_END_J - R_START_J);
	vars->ci = (double)y / (double)W_HEIGHT * (I_END_J - I_START_J);
	julia_set(vars);
	return (0);
}
