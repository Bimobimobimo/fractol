/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:12:10 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/16 13:23:38 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

static void	ft_mandelbrot_or_julia(t_complex *z, t_complex *c,
	t_fractal *fractal)
{
	if (!strncmp(fractal->name, "julia", 6))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	one_pixel(int x, int y, t_img *img, int color)
{
	int	pixel_memory_start;

	pixel_memory_start = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels + pixel_memory_start) = color;
}

void	managing_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	ft_mandelbrot_or_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, GOLD, GREY, fractal->iterations_definition);
			one_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	one_pixel(x, y, &fractal->img, BLACK);
}

void	fractal_rendering(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			managing_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connect, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
