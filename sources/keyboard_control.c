/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:41:08 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 19:38:42 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

static void		rotation(int key, t_window *w)
{
	w->camera.theta -= (key == NUMLOCK_1
			|| key == NUMLOCK_7) ? 0.0174533 * 3 : 0.0;
	w->camera.theta += (key == NUMLOCK_3
			|| key == NUMLOCK_9) ? 0.0174533 * 3 : 0.0;
	w->camera.alpha -= (key == NUMLOCK_2) ? 0.0174533 * 3 : 0.0;
	w->camera.alpha += (key == NUMLOCK_8) ? 0.0174533 * 3 : 0.0;
	w->camera.beta -= (key == NUMLOCK_4) ? 0.0174533 * 3 : 0.0;
	w->camera.beta += (key == NUMLOCK_6) ? 0.0174533 * 3 : 0.0;
	w->camera.x += (key == ARROW_RIGHT || key == D) ? 5 : 0;
	w->camera.x -= (key == ARROW_LEFT || key == A) ? 5 : 0;
	w->camera.y -= (key == ARROW_UP || key == W) ? 5 : 0;
	w->camera.y += (key == ARROW_DOWN || key == S) ? 5 : 0;
	w->camera.x += (key == ARROW_RIGHT || key == D) ? 5 : 0;
	w->camera.x -= (key == ARROW_LEFT || key == A) ? 5 : 0;
	w->camera.y -= (key == ARROW_UP || key == W) ? 5 : 0;
	w->camera.y += (key == ARROW_DOWN || key == S) ? 5 : 0;
}

void			zoom(int key, t_window *w)
{
	w->camera.size *= (key == NUMLOCK_PLUS || key == PLUS ||
			(key == MOUSE_SCROLL_DOWN && !w->mouse.scroll_click))
		? 1.04 : 1;
	w->camera.size = (key == NUMLOCK_MINUS || key == MINUS ||
			(key == MOUSE_SCROLL_UP && !w->mouse.scroll_click)) ?
		min_size(w->camera.size) / 1.04 : w->camera.size;
	(key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
		? create_vectors(w) : 0;
	w->camera.top_size = (key == MORE || (key == MOUSE_SCROLL_DOWN
				&& w->mouse.scroll_click)) ?
		max_top(w->camera.top_size + 0.01) : w->camera.top_size;
	w->camera.top_size = (key == LESS || (key == MOUSE_SCROLL_DOWN
				&& w->mouse.scroll_click)) ?
		min_top(w->camera.top_size - 0.01) : w->camera.top_size;
}

static void		project(int key, t_window *w)
{
	w->camera.alpha = (key == I) ? -0.698132 : w->camera.alpha;
	w->camera.beta = (key == I) ? 2.44346 : w->camera.beta;
	w->camera.theta = (key == I) ? 3.57792 : w->camera.theta;
	w->camera.alpha = (key == P) ? -1.5708 : w->camera.alpha;
	w->camera.beta = (key == P) ? 3.14159 : w->camera.beta;
	w->camera.theta = (key == P) ? 3.14159 : w->camera.theta;
	w->camera.x = (key == C) ? (int)(0.5 * (W_WIDTH + W_MENU_WIDTH))
		: w->camera.x;
	w->camera.y = (key == C) ? (int)(0.5 * W_HEIGHT) : w->camera.y;
}

void			new_color(int key, t_window *w)
{
	if (key == COLOR_1)
		w->map.color = false;
	else if (key == COLOR_2 || key == COLOR_3 ||
			key == COLOR_4 || key == COLOR_5)
	{
		w->map.color = true;
		pick_color(key, w);
	}
}

int				keyboard_control(int key, void *param)
{
	t_window	*w;

	w = (t_window *)param;
	rotation(key, w);
	zoom(key, w);
	(key == ESC) ? close_window(key, param) : 0;
	new_color(key, w);
	project(key, w);
	create_vectors(w);
	return (0);
}
