/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:21:23 by alex              #+#    #+#             */
/*   Updated: 2025/01/05 15:57:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	calculate_color_burningship(t_data *data, int x, int y)
{
	int	iteration;

	data->z_re = (x - WIDTH / 2.0) * (4.0 / WIDTH)
		/ data->zoom + data->offset_x;
	data->z_im = (y - HIGHT / 2.0) * (4.0 / HIGHT)
		/ data->zoom + data->offset_y;
	data->c_re = data->z_re;
	data->c_im = data->z_im;
	iteration = 0;
	while (data->z_re * data->z_re + data->z_im
		* data->z_im <= 4 && iteration < MAX_ITER)
	{
		data->z_re2 = data->z_re * data->z_re
			- data->z_im * data->z_im + data->c_re;
		data->z_im2 = 2 * fabs(data->z_re) * fabs(data->z_im) + data->c_im;
		data->z_re = data->z_re2;
		data->z_im = data->z_im2;
		iteration++;
	}
	if (iteration == MAX_ITER)
		return (0x000000);
	return (choose_color(iteration, data->max_iter,
			data->color_shift, data->color_code));
}

void	burningship(t_data *data)
{
	int	color;

	data->y = 0;
	mlx_clear_window(data->mlx, data->win);
	while ((data->y) < HIGHT)
	{
		data->x = 0;
		while ((data->x) < WIDTH)
		{
			color = calculate_color_burningship(data, data->x, data->y);
			my_mlx_pixel_put(data, data->x, data->y, color);
			data->x++;
		}
		data->y++;
	}
}
