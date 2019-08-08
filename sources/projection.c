/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:42:20 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 20:27:29 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>

static void		rotation(t_point *p, t_window *w)
{
	double		x;
	double		y;

	y = p->y;
	p->y = y * cos(w->camera.alpha) + p->z * sin(w->camera.alpha);
	p->z = -y * sin(w->camera.alpha) + p->z * cos(w->camera.alpha);
	x = p->x;
	p->x = x * cos(w->camera.beta) + p->z * sin(w->camera.beta);
	p->z = -x * sin(w->camera.beta) + p->z * cos(w->camera.beta);
	x = p->x;
	y = p->y;
	p->x = x * cos(w->camera.theta) - y * sin(w->camera.theta);
	p->y = x * sin(w->camera.theta) + y * cos(w->camera.theta);
}

void			projection(t_vector *v, t_window *w)
{
	v->begin.y *= w->camera.top_size;
	v->end.y *= w->camera.top_size;
	rotation(&v->begin, w);
	rotation(&v->end, w);
	v->begin.x *= w->camera.aspect_ratio * w->camera.size * (double)W_WIDTH;
	v->end.x *= w->camera.aspect_ratio * w->camera.size * (double)W_WIDTH;
	v->begin.y *= w->camera.size * (double)W_HEIGHT;
	v->end.y *= w->camera.size * (double)W_HEIGHT;
	v->begin.x += w->camera.x;
	v->end.x += w->camera.x;
	v->begin.y += w->camera.y;
	v->end.y += w->camera.y;
	bresenham_line(v, w);
	free(v);
}
