/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:04:18 by suahn             #+#    #+#             */
/*   Updated: 2021/11/19 19:08:01 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_press(int keycode, t_vars *v)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		free(v->mlx);
		exit(0);
	}
	return (0);
}
