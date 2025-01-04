/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:41:19 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 17:41:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	ft_error(char *str, t_data *data)
{
	ft_printf("%s\n", str);
	if (data)
		free(data);
	exit(1);
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

void	check_arg(char **str, t_data **data, int n)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		ft_error(strerror(errno), *data);
	if (ft_strcmp(str[1], "mandelbrot") == 0 && n == 2)
		(*data)->fractol = MANDELBROT;
	else if (ft_strcmp(str[1], "julia") == 0 && n == 4)
	{
		if (check_arg_julia(str, *data) == 0)
			ft_error("Usage: ./fractol mandelbrot|julia\n\nExamples:\n\
./fractol mandelbrot\n./fractol julia -0.7 0.27015\n\
./fractol julia 0.335 0.355\n./fractol julia -0.4 0.6\n", *data);
	}
	else
		ft_error("Usage: ./fractol mandelbrot|julia\n\nExamples:\n\
./fractol mandelbrot\n./fractol julia -0.7 0.27015\n\
./fractol julia 0.335 0.355\n./fractol julia -0.4 0.6\n", *data);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HIGHT, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
	data->zoom = 1.0;
	data->color_shift = 0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->max_iter = 50;
	data->color = 0xFFFFFF;
	data->color_code = 0;
}
