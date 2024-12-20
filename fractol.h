/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:56:42 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/16 15:14:37 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH		1000
# define HEIGHT		1000

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define MAGENTA	0xFF00FF
# define LIME		0xCCFF00
# define PURPLE		0x660066
# define LIGHTPNK	0xFFB6C1
# define ORCHID		0xDABFD8
# define THISTLE	0xD8BFD8
# define GOLDBROWN	0xFFF8DC
# define GOLD		0xFFD966
# define GREY		0x808080

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connect;
	void	*mlx_win;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

//* INITIALISATION
void		fractal_creation(t_fractal *fractal);

//* RENDERING
void		fractal_rendering(t_fractal *fractal);
void		managing_pixel(int x, int y, t_fractal *fractal);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);

//* HOOK EVENTS
int			managing_key(int keysym, t_fractal *fractal);
int			managing_mouse(int button, int x, int y, t_fractal *fractal);
int			dynamic_julia(int x, int y, t_fractal *fractal);

//* CLOSING
int			closing(t_fractal *fractal);

//* UTILS
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		ft_atodbl(char *s);

#endif
