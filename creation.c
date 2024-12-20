/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:23:05 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/16 13:23:07 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Malloc error\n");
	exit (EXIT_FAILURE);
}

static void	data_creation(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 20;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_creation(t_fractal *fractal)
{
	mlx_hook (fractal->mlx_win, KeyPress, KeyPressMask, managing_key, fractal);
	mlx_hook (fractal->mlx_win, ButtonPress, ButtonPressMask, managing_mouse,
		fractal);
	mlx_hook (fractal->mlx_win, DestroyNotify, StructureNotifyMask, closing,
		fractal);
	mlx_hook (fractal->mlx_win, MotionNotify, PointerMotionMask, dynamic_julia,
		fractal);
}

void	fractal_creation(t_fractal *fractal)
{
	fractal->mlx_connect = mlx_init();
	if (fractal->mlx_connect == NULL)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_connect, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->mlx_win == NULL)
	{
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_connect, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_connect, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_connect);
		free(fractal->mlx_connect);
		malloc_error();
	}
	fractal->img.pixels = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp,
			&fractal->img.line_len,
			&fractal->img.endian);
	events_creation(fractal);
	data_creation(fractal);
}
