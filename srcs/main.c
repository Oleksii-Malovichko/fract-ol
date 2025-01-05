/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:48:03 by alex              #+#    #+#             */
/*   Updated: 2025/01/05 15:27:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

void	mlx_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	render_fractal(data);
}

int	main(int n, char **args)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_printf("Error: %s\n", strerror(errno));
	if (n > 1)
	{
		check_arg(args, data, n);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, WIDTH, HIGHT, "Fractol");
		data->img = mlx_new_image(data->mlx, WIDTH, HIGHT);
		data->addr = mlx_get_data_addr(data->img, &data->bpp,
				&data->line_length, &data->endian);
		init_data(data);
		mlx_hooks(data);
		mlx_loop(data->mlx);
	}
	else
		ft_error(data);
	free(data);
	return (0);
}
