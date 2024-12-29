/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:39:14 by alex              #+#    #+#             */
/*   Updated: 2024/12/29 20:17:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void draw_mandelbrot(t_data *data)
{
    int     x, y;
    double  zx, zy, cx, cy;
    int     iteration;
    double  temp;
    int     color;

    // Подготовка изображения
    prepare_image(data);

    // Предварительные расчеты для масштабирования
    double scale_x = 1.5 / (0.5 * data->zoom * data->width);
    double scale_y = 1.0 / (0.5 * data->zoom * data->height);

    // Итерации по каждому пикселю
    for (y = 0; y < data->height; y++)
    {
        for (x = 0; x < data->width; x++)
        {
            cx = (x - data->width / 2) * scale_x + data->offset_x;
            cy = (y - data->height / 2) * scale_y + data->offset_y;

            zx = 0;
            zy = 0;
            iteration = 0;

            // Алгоритм Мандельброта
            while (zx * zx + zy * zy < 4 && iteration < data->max_iter)
            {
                temp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = temp;
                iteration++;
            }

            // Определяем цвет
            if (iteration == data->max_iter)
                color = 0x000000; // Черный для точек внутри фрактала
            else
                color = 0xFFFFFF - iteration * 255 / data->max_iter;

            // Записываем цвет в буфер
            *(unsigned int *)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;
        }
    }

    // Отправляем изображение в окно
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}


int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

void	parse_data(int n, char **args, t_data *data)
{
	if (n != 2)
	{
		ft_printf("Usage: ./fractol mandelbrot|julia\n");
		exit(1);
	}
	if (ft_strncmp(args[1], "mandelbrot", ft_strlen(args[1])) == 0)
		data->fractol = MANDELBROT;
	else if (ft_strncmp(args[1], "julia", ft_strlen(args[1])) == 0)
		data->fractol = JULIA;
	else
	{
		ft_printf("Invalid fractal type. Use 'mandelbrot' or 'julia'.\n");
		exit(1);
	}
}

void prepare_image(t_data *data)
{
    if (data->img)
        mlx_destroy_image(data->mlx, data->img); // Удаляем старое изображение
    data->img = mlx_new_image(data->mlx, data->width, data->height);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
                                   &data->line_length, &data->endian);
}

void init_data(t_data *data)
{
	data->width = 800;
	data->height = 800;
	data->zoom = 1.0;
	data->offset_x = -0.5;
	data->offset_y = 0.0;
	data->max_iter = 100; // число итераций
	data->img = NULL;
	data->addr = NULL;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307) // esc
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data);
		exit(0);
	}
	return (0);
}

void adjust_iterations(t_data *data)
{
    if (data->zoom > 1)
        data->max_iter = 100 + (int)(data->zoom * 10);
    else
        data->max_iter = 100;
}

int mouse_hook(int button, int x, int y, t_data *data)
{
    double prev_zoom = data->zoom;
    if (button == 4)
        data->zoom *= 1.1;
    else if (button == 5)
        data->zoom /= 1.1;
    data->offset_x += (x - data->width / 2) / (0.5 * prev_zoom * data->width) -
                      (x - data->width / 2) / (0.5 * data->zoom * data->width);
    data->offset_y += (y - data->height / 2) / (0.5 * prev_zoom * data->height) -
                      (y - data->height / 2) / (0.5 * data->zoom * data->height);
	adjust_iterations(data);
	if (data->fractol == MANDELBROT)		
		draw_mandelbrot(data);
	else
		return 0;
    return (0);
}


int main(int n, char **args)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_printf("Memory allocation failed.\n"), 1);
	parse_data(n, args, data);
	init_data(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "fractol");
	if (data->fractol == MANDELBROT)
		draw_mandelbrot(data);
	else
		return (1);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}

