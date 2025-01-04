/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:48:03 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 17:41:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	close_window(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
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
	mlx_loop(data->mlx);
}

int	main(int n, char **args)
{
	t_data	*data;

	data = NULL;
	check_arg(args, &data, n);
	init_data(data);
	mlx_hooks(data);
	free(data);
	return (0);
}
