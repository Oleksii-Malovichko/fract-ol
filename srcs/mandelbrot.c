/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:05:37 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 20:02:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	calculate_color_mandelbrot(t_data *data)
{
	int	iteration;

	data->c_re = (data->x - WIDTH / 2.0) * (4.0 / WIDTH)
		/ data->zoom + data->offset_x;
	data->c_im = (data->y - HIGHT / 2.0) * (4.0 / HIGHT)
		/ data->zoom + data->offset_y;
	data->z_re = 0;
	data->z_im = 0;
	iteration = 0;
	while (data->z_re * data->z_re + data->z_im
		* data->z_im <= 4 && iteration < data->max_iter)
	{
		data->z_re2 = data->z_re * data->z_re
			- data->z_im * data->z_im + data->c_re;
		data->z_im2 = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = data->z_re2;
		data->z_im = data->z_im2;
		iteration++;
	}
	if (iteration == data->max_iter)
		return (0x000000);
	return (choose_color(iteration, data->max_iter,
			data->color_shift, data->color_code));
}

void	mandelbrot(t_data *data)
{
	int	color;

	data->y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->y < HIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			color = calculate_color_mandelbrot(data);
			my_mlx_pixel_put(data, data->x, data->y, color);
			data->x++;
		}
		data->y++;
	}
}
