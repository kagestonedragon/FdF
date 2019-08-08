/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:32:57 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 19:20:12 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"
#include "../minilibx/mlx.h"

static int		position_check(t_window *w, int x, int y)
{
	if ((x >= w->map.x_min_pos && x <= w->map.x_max_pos)
			&& (y >= w->map.y_min_pos && y <= w->map.y_max_pos))
	{
		w->map.x_min_pos = W_WIDTH;
		w->map.x_max_pos = 0;
		w->map.y_min_pos = W_HEIGHT;
		w->map.y_max_pos = 0;
		return (1);
	}
	return (0);
}

static int		color_check(int x, int y)
{
	if (x > 0 && x < 42 && y >= 715 && y <= 915)
		return (COLOR_1);
	else if (x > 0 && x < 84 && y >= 765 && y <= 915)
		return (COLOR_2);
	else if (x > 0 && x < 126 && y >= 765 && y <= 915)
		return (COLOR_3);
	else if (x > 0 && x < 168 && y >= 765 && y <= 915)
		return (COLOR_4);
	else if (x > 0 && x < 210 && y >= 765 && y <= 915)
		return (COLOR_5);
	return (0);
}

int				mouse_click(int button, int x, int y, void *param)
{
	t_window	*w;

	w = (t_window *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, w);
	else if (button == MOUSE_LEFT_BUTTON && position_check(w, x, y))
		w->mouse.left_click = true;
	else if (button == MOUSE_LEFT_BUTTON && color_check(x, y))
		new_color(color_check(x, y), w);
	else if (button == MOUSE_RIGHT_BUTTON && position_check(w, x, y))
		w->mouse.right_click = true;
	else if (button == MOUSE_SCROLL_BUTTON && position_check(w, x, y))
		w->mouse.scroll_click = true;
	return (0);
}

int				mouse_unclick(int button, int x, int y, void *param)
{
	t_window	*w;

	w = (t_window *)param;
	(void)button;
	(void)x;
	(void)y;
	w->mouse.left_click = false;
	w->mouse.right_click = false;
	w->mouse.scroll_click = false;
	return (0);
}

int				mouse_move(int x, int y, void *param)
{
	t_window	*w;

	w = (t_window *)param;
	w->mouse.old_x = w->mouse.x;
	w->mouse.old_y = w->mouse.y;
	w->mouse.x = x;
	w->mouse.y = y;
	if (w->mouse.right_click)
	{
		w->camera.alpha -= (y - w->mouse.old_y) * 0.003;
		w->camera.beta += (x - w->mouse.old_x) * 0.003;
	}
	else if (w->mouse.left_click)
	{
		w->camera.x += (x - w->mouse.old_x);
		w->camera.y += (y - w->mouse.old_y);
	}
	else if (w->mouse.scroll_click)
		w->camera.top_size = min_top(w->camera.top_size -
				(y - w->mouse.old_y) * 0.005);
	create_vectors(w);
	return (0);
}
