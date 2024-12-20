/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:22:55 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/16 15:13:54 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.name = argv[1];
		if (argv[2] && argv[3])
		{
			fractal.julia_x = ft_atodbl(argv[2]);
			fractal.julia_y = ft_atodbl(argv[3]);
		}
		fractal_creation(&fractal);
		fractal_rendering(&fractal);
		mlx_loop(fractal.mlx_connect);
	}
	else
	{
		ft_putstr_fd("Argument error, rerun with <mandelbrot>", 2);
		ft_putstr_fd(" or <julia number number>\n", 2);
		return (EXIT_FAILURE);
	}
	return (0);
}
