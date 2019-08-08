/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:50:47 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 19:44:12 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx/mlx.h"
#include "../includes/keys.h"
#include <stdlib.h>

static void		color(t_vector *v, int i, int position, t_window *w)
{
	if (w->map.color)
	{
		v->begin.color = return_color(w->values->y[i], w);
		v->end.color = return_color(w->values->y[i + position], w);
	}
	else
	{
		v->begin.color = w->values->color[i];
		v->end.color = w->values->color[i + position];
	}
}

static t_vector	*new_vector_vectical(int x, int z, int i, t_window *w)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	v->begin.x = x;
	v->begin.y = w->values->y[i];
	v->begin.z = z;
	v->end.x = (double)x;
	v->end.y = (double)w->values->y[i + w->map.width];
	v->end.z = (double)z + 1;
	color(v, i, w->map.width, w);
	return (v);
}

static t_vector	*new_vector_horizontal(int x, int z, int i, t_window *w)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	v->begin.x = x;
	v->begin.y = w->values->y[i];
	v->begin.z = z;
	v->end.x = (double)x + 1;
	v->end.y = (double)w->values->y[i + 1];
	v->end.z = (double)z;
	color(v, i, 1, w);
	return (v);
}

void			create_vectors(t_window *w)
{
	int			i;
	int			x;
	int			z;

	mlx_clear_window(w->mlx, w->win);
	draw_background(w);
	i = -1;
	z = -(w->map.height / 2);
	x = -(w->map.width / 2);
	while (++i < w->map.points)
	{
		if (i < w->map.points - w->map.width)
			projection(new_vector_vectical(x, z, i, w), w);
		if ((i + 1) % w->map.width)
			projection(new_vector_horizontal(x++, z, i, w), w);
		else
		{
			x = -(w->map.width / 2);
			z++;
		}
	}
	mlx_put_image_to_window(w->mlx, w->win, w->image.image, 0, 0);
	draw_instructions(w);
	draw_info(w);
}
