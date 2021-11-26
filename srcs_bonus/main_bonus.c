/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <suahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:24:30 by suahn             #+#    #+#             */
/*   Updated: 2021/11/15 14:24:32 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/fractol_bonus.h"

void	error_detected_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		error_detected_exit("Type a fractal set : 'mandelbrot' / 'julia'.\n");
	else if (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia"))
		error_detected_exit("Type a fractal set : 'mandelbrot' / 'julia'.\n");
	else if (!ft_strcmp(argv[1], "julia"))
	{
		if (argc != 2)
			error_detected_exit("Too many arguments. Type only 'julia'\n");
	}
	else if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		if (argc != 2)
			error_detected_exit("Too many arguments. Type only 'mandelbrot'.\n");
	}
	if (argc == 2 && !ft_strcmp(argv[1], "julia"))
		julia_main();
	else if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		mandelbrot_main();
	return (0);
}
