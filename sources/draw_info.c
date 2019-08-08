/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:10:28 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 19:19:44 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "../includes/color.h"
#include <stdlib.h>

void				draw_xy(t_window *w)
{
	char			*cat_x_angle;
	char			*x_angle;
	char			*cat_y_angle;
	char			*y_angle;

	x_angle = ft_itoa((int)(w->camera.alpha * 57.2859) % 360);
	cat_x_angle = ft_strjoin("X-Angle:    ", x_angle);
	y_angle = ft_itoa((int)(w->camera.beta * 57.2859) % 360);
	cat_y_angle = ft_strjoin("Y-Angle:    ", y_angle);
	mlx_string_put(w->mlx, w->win, 15, 920, GRAY, cat_x_angle);
	mlx_string_put(w->mlx, w->win, 15, 940, GRAY, cat_y_angle);
	free(x_angle);
	free(cat_x_angle);
	free(y_angle);
	free(cat_y_angle);
}

void				draw_z(t_window *w)
{
	char			*cat_z_angle;
	char			*z_angle;

	z_angle = ft_itoa((int)(w->camera.theta * 57.2859) % 360);
	cat_z_angle = ft_strjoin("Z-Angle:    ", z_angle);
	mlx_string_put(w->mlx, w->win, 15, 960, GRAY, cat_z_angle);
	free(z_angle);
	free(cat_z_angle);
}

void				draw_xymouse(t_window *w)
{
	char			*cat_x_angle;
	char			*x_angle;
	char			*cat_y_angle;
	char			*y_angle;

	x_angle = ft_itoa(w->mouse.x - (int)(0.5 * W_WIDTH));
	cat_x_angle = ft_strjoin("X-Mouse:    ", x_angle);
	y_angle = ft_itoa((int)(0.5 * W_HEIGHT) - w->mouse.y);
	cat_y_angle = ft_strjoin("Y-Mouse:    ", y_angle);
	mlx_string_put(w->mlx, w->win, 15, 980, GRAY, cat_x_angle);
	mlx_string_put(w->mlx, w->win, 15, 1000, GRAY, cat_y_angle);
	free(x_angle);
	free(cat_x_angle);
	free(y_angle);
	free(cat_y_angle);
}

void				draw_xylocation(t_window *w)
{
	char			*cat_x_location;
	char			*x_location;
	char			*cat_y_location;
	char			*y_location;

	x_location = ft_itoa(w->camera.x - (int)(0.5 * W_WIDTH));
	cat_x_location = ft_strjoin("X-Location: ", x_location);
	y_location = ft_itoa((int)(0.5 * W_HEIGHT) - w->camera.y);
	cat_y_location = ft_strjoin("Y-Location: ", y_location);
	mlx_string_put(w->mlx, w->win, 15, 1020, GRAY, cat_x_location);
	mlx_string_put(w->mlx, w->win, 15, 1040, GRAY, cat_y_location);
	free(x_location);
	free(cat_x_location);
	free(y_location);
	free(cat_y_location);
}

void				draw_info(t_window *w)
{
	int				y;

	y = -1;
	while (++y <= W_HEIGHT)
		mlx_pixel_put(w->mlx, w->win, W_MENU_WIDTH, y, LINE_COLOR);
	mlx_string_put(w->mlx, w->win, 15, 550, GRAY, "Mouse control");
	mlx_string_put(w->mlx, w->win, 15, 575, GRAY, "Rotation:");
	mlx_string_put(w->mlx, w->win, 75, 595, GRAY, "Right button");
	mlx_string_put(w->mlx, w->win, 15, 620, GRAY, "Move:");
	mlx_string_put(w->mlx, w->win, 75, 640, GRAY, "Left button");
	mlx_string_put(w->mlx, w->win, 15, 665, GRAY, "Size:");
	mlx_string_put(w->mlx, w->win, 75, 685, GRAY, "Scroll");
	mlx_string_put(w->mlx, w->win, 15, 710, GRAY, "Top:");
	mlx_string_put(w->mlx, w->win, 75, 730, GRAY, "Scroll P");
	mlx_string_put(w->mlx, w->win, 15, 755, GRAY, "Color:");
	mlx_string_put(w->mlx, w->win, 15, 785, GRAY, "1   2   3   4   5");
	mlx_string_put(w->mlx, w->win, 15, 900, GRAY, "Information");
	draw_xy(w);
	draw_z(w);
	draw_xylocation(w);
	draw_xymouse(w);
}
