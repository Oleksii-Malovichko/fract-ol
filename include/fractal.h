#ifndef FRACTOL_H
#define FRACTOL_H

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/ft_printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#define HIGHT	600
#define WIDTH	1000
#define MAX_ITER 100
typedef struct s_data
{
	void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     fractol;
    double  zoom;
    double  offset_x;
    double  offset_y;
    int     max_iter;
    int     color;
    int     bpp;
    int     line_length;
    int     endian;
    double  start_x;  // добавьте координаты области фрактала
    double  end_x;
    double  start_y;
    double  end_y;
	int		max;
} t_data;

#define MANDELBROT 1
#define JULIA 2
void	mlx_hooks(t_data *data);
void	mlx_hooks(t_data *data);
void		zoom(t_data *data, double x, double y, double zoom);
void	render_fractal(t_data *data);
void mandelbrot(t_data *data);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
int close_window(t_data *data);
void init_data(t_data *data);
int key_hook(int keycode, t_data *data);
int			mouse_press(int button, int x, int y, t_data *data);

#endif
