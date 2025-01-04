/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:45:03 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 20:26:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
#include <string.h>
# define HIGHT	600
# define WIDTH	1000
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		fractol;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iter;
	int		color;
	int		bpp;
	int		line_length;
	int		endian;
	int		color_shift;
	int		color_code;
	double	c_re;
	double	c_im;
	int		x;
	int		y;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
}	t_data;

# define MANDELBROT 1
# define JULIA 2

// Colors config
int		choose_color(int iteration, int max_iter,
			int color_shift, int color_code);
int		get_color1(int iteration, int max_iter, int color_shift);
int		get_color2(int iteration, int max_iter, int color_shift);
int		get_color3(int iteration, int max_iter, int color_shift);

// Hooks
int		key_hook(int keycode, t_data *data);
void	mlx_hooks(t_data *data);
void	mlx_hooks(t_data *data);
int		key_hook(int keycode, t_data *data);
int		close_window(t_data *data);
int		mouse_press(int button, int x, int y, t_data *data);

// Fractals
void	mandelbrot(t_data *data);
void	julia(t_data *data);

// Init
void	render_fractal(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_error(char *str, t_data *data);
int		check_arg_julia(char **str, t_data *data);
void	check_arg(char **str, t_data *data, int n);
void	init_data(t_data *data);
int		ft_strcmp(char *s1, char *s2);

#endif
