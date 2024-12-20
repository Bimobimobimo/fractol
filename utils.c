/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:23:54 by lcollong          #+#    #+#             */
/*   Updated: 2024/12/16 15:16:37 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.y * z.x;
	return (result);
}

static double	ft_fraction(char *s)
{
	double	fract;
	double	pow;
	int		i;

	i = 0;
	fract = 0;
	pow = 1;
	while (s[i] != '\0')
	{
		pow /= 10;
		fract = fract + (s[i] - '0') * pow;
		i++;
	}
	return (fract);
}

static void	ft_isvalid_nbr(char *s)
{
	int	i;
	int	coma;

	i = 0;
	coma = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if ((!ft_isdigit(s[i]) && s[i] != '.') || (s[i] == '.' && coma == 1))
		{
			ft_putstr_fd("Argument error, rerun with ", 2);
			ft_putstr_fd("<julia> <number> <number>\n", 2);
			exit (EXIT_FAILURE);
		}
		if (s[i] == '.')
			coma = 1;
		i++;
	}
}

double	ft_atodbl(char *s)
{
	long	int_part;
	double	fract;
	int		sign;
	int		i;

	i = 0;
	int_part = 0;
	fract = 0;
	sign = 1;
	ft_isvalid_nbr(s);
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	while (s[i] != '.' && s[i] != '\0')
		int_part = (int_part * 10) + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	fract = ft_fraction(s + i);
	return ((int_part + fract) * sign);
}
