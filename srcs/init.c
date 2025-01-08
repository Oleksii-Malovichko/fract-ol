/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:41:19 by alex              #+#    #+#             */
/*   Updated: 2025/01/08 13:26:23 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	ft_error(t_data *data)
{
	ft_printf("Usage: ./fractol mandelbrot|julia\n\nExamples:\n\
./fractol mandelbrot\n./fractol burningship\n./fractol julia -0.7 0.27015\n\
./fractol julia 0.335 0.355\n./fractol julia -0.4 0.6\n");
	free(data);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_arg_julia(char **str, t_data *data)
{
	if (ft_strcmp(str[2], "-0.7") == 0 && ft_strcmp(str[3], "0.27015") == 0)
	{
		data->fractol = JULIA;
		data->c_re = -0.7;
		data->c_im = 0.27015;
		return (1);
	}
	if (ft_strcmp(str[2], "0.335") == 0 && ft_strcmp(str[3], "0.355") == 0)
	{
		data->fractol = JULIA;
		data->c_re = 0.355;
		data->c_im = 0.355;
		return (1);
	}
	if (ft_strcmp(str[2], "-0.4") == 0 && ft_strcmp(str[3], "0.6") == 0)
	{
		data->fractol = JULIA;
		data->c_re = -0.4;
		data->c_im = 0.6;
		return (1);
	}
	return (0);
}

void	check_arg(char **str, t_data *data, int n)
{
	if (ft_strcmp(str[1], "mandelbrot") == 0 && n == 2)
		(data)->fractol = MANDELBROT;
	else if (ft_strcmp(str[1], "burningship") == 0 && n == 2)
		(data)->fractol = BURNINGSHIP;
	else if (ft_strcmp(str[1], "julia") == 0 && n == 4)
	{
		if (check_arg_julia(str, data) == 0)
			ft_error(data);
	}
	else
		ft_error(data);
}

void	init_data(t_data *data)
{
	data->zoom = 1.0;
	data->color_shift = 0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->max_iter = 50;
	data->color = 0xFFFFFF;
	data->color_code = 0;
}
