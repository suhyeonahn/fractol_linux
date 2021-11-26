/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:35:39 by suahn             #+#    #+#             */
/*   Updated: 2021/11/17 09:57:16 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_click_hook(int button, int x, int y, t_vars *vars)
{
	if (x >= 0 && y >= 0)
	{
		if (button == SCROLL_UP)
			vars->zoom *= 1.2;
		else if (button == SCROLL_DOWN)
			vars->zoom /= 1.2;
		if (vars->type == 1)
			mandelbrot_set(vars);
		else if (vars->type == 2)
			julia_set(vars);
	}
	return (0);
}

int	mouse_move_hook(t_vars *vars)
{
	int x;
	int y;

	mlx_mouse_get_pos(vars->win, &x, &y);
	vars->cr = (double)x / (double)W_WIDTH * (R_END_J - R_START_J);
	vars->ci = (double)y / (double)W_HEIGHT * (I_END_J - I_START_J);
	julia_set(vars);
	return (0);
}