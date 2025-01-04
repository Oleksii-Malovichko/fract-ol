/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:38:04 by alex              #+#    #+#             */
/*   Updated: 2025/01/04 16:42:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	get_color3(int iteration, int max_iter, int color_shift)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / max_iter;
	red = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * t * t * t * 255);
	red = (red + color_shift) % 256;
	green = (green + color_shift) % 256;
	blue = (blue + color_shift) % 256;
	return (red << 16 | green << 8 | blue);
}

int	get_color2(int iteration, int max_iter, int color_shift)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / max_iter;
	red = (int)(255 * (1 - t) * (1 - t));
	green = (int)(255 * t * t);
	blue = (int)(255 * t * t * (1 - t));
	red = (red + color_shift) % 256;
	green = (green + color_shift) % 256;
	blue = (blue + color_shift) % 256;
	return (red << 16 | green << 8 | blue);
}

int	get_color1(int iteration, int max_iter, int color_shift)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)iteration / max_iter;
	red = (int)(255 * t);
	green = (int)(255 * (1 - t));
	blue = (int)(128 + 127 * t);
	red = (red + color_shift) % 256;
	green = (green + color_shift) % 256;
	blue = (blue + color_shift) % 256;
	return (red << 16 | green << 8 | blue);
}
