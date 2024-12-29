/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:34:25 by alex              #+#    #+#             */
/*   Updated: 2024/12/29 19:22:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "../lib/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"

#define JULIA 1
#define MANDELBROT 0

typedef struct s_point
{
    double x;
    double y;
    int iteration;
}   t_point;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
	int width;
    int height;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     max_iter;
	int		fractol;
	double  zoom;
    double  offset_x;
    double  offset_y;
}   t_data;

typedef struct s_map
{
    int width;
    int height;
    double zoom;
    double offset_x;
    double offset_y;
}   t_map;
void prepare_image(t_data *data);
#endif