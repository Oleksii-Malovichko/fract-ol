/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:26:35 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 18:25:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	key_hook_helper(int keycode, t_data *data)
{
	if (keycode == 61)
		mouse_press(4, WIDTH / 2, HIGHT / 2, data);
	else if (keycode == 45)
		mouse_press(5, WIDTH / 2, HIGHT / 2, data);
	else if (keycode == 49)
		data->color_code = 0;
	else if (keycode == 50)
		data->color_code = 1;
	else if (keycode == 51)
		data->color_code = 2;
}

int	key_hook(int keycode, t_data *data)
{
	double	move_factor;

	move_factor = 0.1 / data->zoom;
	// printf("%d\n", keycode); // 65363 вправо. 65361 влево. 65362 вверх. 65364 вниз, + 61, - 45.
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65363) // Вправо
		data->offset_x += move_factor;
	else if (keycode == 65361) // Влево
		data->offset_x -= move_factor;
	else if (keycode == 65362) // Вверх
	{
		data->color_shift += 10;
		data->offset_y -= move_factor;
	}
	else if (keycode == 65364) // Вниз
	{
		data->color_shift -= 10;
		data->offset_y += move_factor;
	}
	else
		key_hook_helper(keycode, data);
	render_fractal(data);
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	if (button == 4)
	{
		data->zoom *= zoom_factor;
		data->offset_x += (x - WIDTH / 2) * (4.0 / WIDTH) / data->zoom;
		data->offset_y += (y - HIGHT / 2) * (4.0 / HIGHT) / data->zoom;
	}
	else if (button == 5)
	{
		data->zoom /= zoom_factor;
		data->offset_x += (x - WIDTH / 2) * (4.0 / WIDTH) / data->zoom;
		data->offset_y += (y - HIGHT / 2) * (4.0 / HIGHT) / data->zoom;
	}
	render_fractal(data);
	return (1);
}

void	render_fractal(t_data *data)
{
	if (data->fractol == MANDELBROT)
		mandelbrot(data);
	else if (data->fractol == JULIA)
		julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
