/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:18:14 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 18:43:09 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "../includes/color.h"

static void			pixel_put(t_window *w, int x, int y, int color)
{
	int				i;

	if (x >= W_MENU_WIDTH && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		(w->map.x_min_pos > x) ? w->map.x_min_pos = x : 0;
		(w->map.x_max_pos < x) ? w->map.x_max_pos = x : 0;
		(w->map.y_min_pos > y) ? w->map.y_min_pos = y : 0;
		(w->map.y_max_pos < y) ? w->map.y_max_pos = y : 0;
		i = (x * w->image.bpp / 8) + (y * w->image.size_line);
		w->image.data[i] = color;
		w->image.data[++i] = color >> 8;
		w->image.data[++i] = color >> 16;
		w->image.data[++i] = 0;
	}
}

void				bresenham_line(t_vector *v, t_window *w)
{
	int				s[2];
	int				error[2];
	int				x;
	int				y;
	int				color;

	v->dx = abs((int)v->end.x - (int)v->begin.x);
	v->dy = -abs((int)v->end.y - (int)v->begin.y);
	s[0] = (int)v->begin.x < (int)v->end.x ? 1 : -1;
	s[1] = (int)v->begin.y < (int)v->end.y ? 1 : -1;
	x = (int)v->begin.x;
	y = (int)v->begin.y;
	error[0] = v->dx + v->dy;
	color = v->begin.color;
	while ((x - s[0]) != (int)v->end.x && (y - s[1]) != (int)v->end.y)
	{
		color = pixel_color(v, x, y, color);
		pixel_put(w, x, y, color);
		error[1] = 2 * error[0];
		error[0] += (error[1] >= v->dy) ? v->dy : 0;
		x += (error[1] >= v->dy) ? s[0] : 0;
		error[0] += (error[1] <= v->dx) ? v->dx : 0;
		y += (error[1] <= v->dx) ? s[1] : 0;
	}
}

void				draw_instructions(t_window *w)
{
	mlx_string_put(w->mlx, w->win, 15, 10, GRAY, "Keyboard control");
	mlx_string_put(w->mlx, w->win, 15, 35, GRAY, "Rotation: ");
	mlx_string_put(w->mlx, w->win, 75, 55, GRAY, "X Axis: 2/8 ");
	mlx_string_put(w->mlx, w->win, 75, 75, GRAY, "Y Axis: 4/6 ");
	mlx_string_put(w->mlx, w->win, 75, 95, GRAY, "Z Axis: 1/3 ");
	mlx_string_put(w->mlx, w->win, 15, 120, GRAY, "Move: ");
	mlx_string_put(w->mlx, w->win, 75, 140, GRAY, "Arrows");
	mlx_string_put(w->mlx, w->win, 75, 160, GRAY, "WASD");
	mlx_string_put(w->mlx, w->win, 15, 185, GRAY, "Top: ");
	mlx_string_put(w->mlx, w->win, 75, 205, GRAY, "</>");
	mlx_string_put(w->mlx, w->win, 15, 230, GRAY, "Size: ");
	mlx_string_put(w->mlx, w->win, 75, 250, GRAY, "-/+");
	mlx_string_put(w->mlx, w->win, 15, 275, GRAY, "Center: ");
	mlx_string_put(w->mlx, w->win, 75, 295, GRAY, "C ");
	mlx_string_put(w->mlx, w->win, 15, 320, GRAY, "Projection:");
	mlx_string_put(w->mlx, w->win, 75, 340, GRAY, "I/P ");
	mlx_string_put(w->mlx, w->win, 15, 365, GRAY, "Color: ");
	mlx_string_put(w->mlx, w->win, 75, 385, GRAY, "1 - Default");
	mlx_string_put(w->mlx, w->win, 75, 405, GRAY, "2 - Custom");
	mlx_string_put(w->mlx, w->win, 75, 425, GRAY, "3 - Custom");
	mlx_string_put(w->mlx, w->win, 75, 445, GRAY, "4 - Custom");
	mlx_string_put(w->mlx, w->win, 75, 465, GRAY, "5 - Custom");
}

void				draw_background(t_window *w)
{
	int				i;
	int				*data;

	data = (int *)w->image.data;
	i = -1;
	while (++i < W_HEIGHT * W_WIDTH)
		data[i] = (i % W_WIDTH < W_MENU_WIDTH) ? MENU_BACKGROUND : BACKGROUND;
}
