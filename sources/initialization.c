/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:28:27 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 20:26:02 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/keys.h"
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

int				close_window(int key, void *param)
{
	t_window	*w;

	w = (t_window *)param;
	if (key == ESC)
	{
		free(w->values->y);
		free(w->values->color);
		free(w->values);
		free(w);
	}
	exit(0);
}

static void		create_camera(t_window *w)
{
	w->camera.aspect_ratio = (double)W_HEIGHT / (double)W_WIDTH;
	w->camera.alpha = -0.698132;
	w->camera.beta = 2.44346;
	w->camera.theta = 3.57792;
	w->camera.size = 0.001;
	w->camera.x = (int)(0.5 * (W_WIDTH + W_MENU_WIDTH));
	w->camera.y = (int)(0.5 * W_HEIGHT);
	w->camera.top_size = 1.0;
	w->mouse.left_click = false;
	w->mouse.right_click = false;
	w->mouse.scroll_click = false;
}

static void		map_values(t_window *w)
{
	w->map.x_min_pos = W_WIDTH;
	w->map.x_max_pos = 0;
	w->map.y_min_pos = W_HEIGHT;
	w->map.y_max_pos = 0;
	w->values = NULL;
	w->map.color = false;
	w->map.width = 0;
	w->map.y_min = 0;
	w->map.y_max = 0;
	w->map.height = 0;
}

t_window		*create_window(char **argv)
{
	char		*name;
	t_window	*w;

	name = ft_strjoin("FdF - ", argv[1]);
	if (!(w = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	if (!(w->mlx = mlx_init()))
		return (NULL);
	if (!(w->win = mlx_new_window(w->mlx, W_WIDTH, W_HEIGHT, name)))
		return (NULL);
	if (!(w->image.image = mlx_new_image(w->mlx, W_WIDTH, W_HEIGHT)))
		return (NULL);
	w->image.data = mlx_get_data_addr(w->image.image, &w->image.bpp,
			&w->image.size_line, &w->image.endian);
	create_camera(w);
	map_values(w);
	free(name);
	return (w);
}
