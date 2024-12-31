/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:05:37 by alex              #+#    #+#             */
/*   Updated: 2024/12/31 15:26:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	render_fractal(t_data *data)
{
	if (data->fractol == MANDELBROT)
		mandelbrot(data);
	// else if (data->fractol == JULIA)
		// julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int get_color1(int iteration, int max_iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / max_iter;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (red << 16 | green << 8 | blue);
}

int get_color2(int iteration, int max_iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

    t = (double)iteration / max_iter;
    red = (int)(255 * (1 - t));
    green = (int)(255 * t);
    blue = (int)(255 * (t * t));
    return (red << 16 | green << 8 | blue);
}

int get_color(int iteration, int max_iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / max_iter;
	red = (int)(255 * t);
	green = (int)(255 * (1 - t));
	blue = (int)(128 + 127 * t);
	return (red << 16 | green << 8 | blue);
}

void mandelbrot(t_data *data)
{
    int x, y;
    double c_re, c_im, z_re, z_im, z_re2, z_im2;
    int iteration;

    for (y = 0; y < HIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            c_re = (x - WIDTH / 2.0) * (4.0 / WIDTH) / data->zoom + data->offset_x;
            c_im = (y - HIGHT / 2.0) * (4.0 / HIGHT) / data->zoom + data->offset_y;
            z_re = 0;
            z_im = 0;
            iteration = 0;
            while (z_re * z_re + z_im * z_im <= 4 && iteration < data->max_iter)
            {
                z_re2 = z_re * z_re - z_im * z_im + c_re;
                z_im2 = 2 * z_re * z_im + c_im;
                z_re = z_re2;
                z_im = z_im2;
                iteration++;
            }
            int color = iteration == data->max_iter ? 0x000000 : get_color(iteration, data->max_iter);
            my_mlx_pixel_put(data, x, y, color);
        }
    }
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HIGHT)
    {
        dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

int mouse_press(int button, int x, int y, t_data *data)
{
    double zoom_factor;

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
