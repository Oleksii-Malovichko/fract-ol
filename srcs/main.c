/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:48:03 by alex              #+#    #+#             */
/*   Updated: 2024/12/31 15:26:21 by alex             ###   ########.fr       */
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

void	check_arg(char *str, t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
	{
		ft_error(strerror(errno), *data);
		exit(1);
	}
	if (ft_strcmp(str, "julia") != 0 && ft_strcmp(str, "mandelbrot") != 0)
	{
		ft_error("Usage: ./fractol julia|mandelbrot", *data);
		exit(1);
	}
	else if (ft_strcmp(str, "julia") == 0)
		(*data)->fractol = JULIA;
	else
		(*data)->fractol = MANDELBROT;
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HIGHT, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	// data->max = 40;
	data->max_iter = 50;
	data->color = 0xFFFFFF;
}

int	close_window(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		close_window(data);
	}
	return (0);
}

void	mlx_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	render_fractal(data);
	mlx_loop(data->mlx);
}

int main(int n, char **args)
{
	t_data	*data;

	data = NULL;
	if (n == 2)
	{
		check_arg(args[1], &data);
		init_data(data);
		mlx_string_put(data->mlx, data->win, 100, 100, 0x000000FF, "hello");
		mlx_hooks(data);
		free(data);
	}
	else
		return (ft_printf("Usage: ./fractol julia|mandelbrot\n"), 1);
	return (0);
}