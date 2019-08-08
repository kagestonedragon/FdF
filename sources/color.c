/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:07:39 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 20:27:17 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"
#include "../includes/keys.h"

void			pick_color(int key, t_window *w)
{
	w->map.color_v[0] = (key == COLOR_2) ? COLOR_1_1 : w->map.color_v[0];
	w->map.color_v[1] = (key == COLOR_2) ? COLOR_1_2 : w->map.color_v[1];
	w->map.color_v[2] = (key == COLOR_2) ? COLOR_1_3 : w->map.color_v[2];
	w->map.color_v[3] = (key == COLOR_2) ? COLOR_1_4 : w->map.color_v[3];
	w->map.color_v[4] = (key == COLOR_2) ? COLOR_1_5 : w->map.color_v[4];
	w->map.color_v[0] = (key == COLOR_3) ? COLOR_2_1 : w->map.color_v[0];
	w->map.color_v[1] = (key == COLOR_3) ? COLOR_2_2 : w->map.color_v[1];
	w->map.color_v[2] = (key == COLOR_3) ? COLOR_2_3 : w->map.color_v[2];
	w->map.color_v[3] = (key == COLOR_3) ? COLOR_2_4 : w->map.color_v[3];
	w->map.color_v[4] = (key == COLOR_3) ? COLOR_2_5 : w->map.color_v[4];
	w->map.color_v[0] = (key == COLOR_4) ? COLOR_3_1 : w->map.color_v[0];
	w->map.color_v[1] = (key == COLOR_4) ? COLOR_3_2 : w->map.color_v[1];
	w->map.color_v[2] = (key == COLOR_4) ? COLOR_3_3 : w->map.color_v[2];
	w->map.color_v[3] = (key == COLOR_4) ? COLOR_3_4 : w->map.color_v[3];
	w->map.color_v[4] = (key == COLOR_4) ? COLOR_3_5 : w->map.color_v[4];
	w->map.color_v[0] = (key == COLOR_5) ? COLOR_4_1 : w->map.color_v[0];
	w->map.color_v[1] = (key == COLOR_5) ? COLOR_4_2 : w->map.color_v[1];
	w->map.color_v[2] = (key == COLOR_5) ? COLOR_4_3 : w->map.color_v[2];
	w->map.color_v[3] = (key == COLOR_5) ? COLOR_4_4 : w->map.color_v[3];
	w->map.color_v[4] = (key == COLOR_5) ? COLOR_4_5 : w->map.color_v[4];
}

int				return_color(double y, t_window *w)
{
	float		percentage;

	percentage = percent(w->map.y_min, w->map.y_max, (int)y);
	if (percentage < 0.2f)
		return (w->map.color_v[0]);
	else if (percentage < 0.4f)
		return (w->map.color_v[1]);
	else if (percentage < 0.6f)
		return (w->map.color_v[2]);
	else if (percentage < 0.8f)
		return (w->map.color_v[3]);
	else
		return (w->map.color_v[4]);
}

int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double			percent(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0f : (placement / distance));
}

int				pixel_color(t_vector *v, int x, int y, int color)
{
	int			red;
	int			green;
	int			blue;
	float		percentage;

	if (color == v->end.color)
		return (color);
	if (v->dx > v->dy)
		percentage = percent((int)v->begin.x, (int)v->end.x, x);
	else
		percentage = percent((int)v->begin.y, (int)v->end.y, y);
	red = get_light((v->begin.color >> 16) & 0xFF, (v->end.color >> 8) &
			0xFF, percentage);
	green = get_light((v->begin.color >> 8) & 0xFF, (v->end.color >> 8) &
			0xFF, percentage);
	blue = get_light(v->begin.color & 0xFF, v->end.color &
			0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
