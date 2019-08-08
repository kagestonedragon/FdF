/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:37:20 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 20:02:34 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

static t_values		*create_points(int s)
{
	t_values		*o;

	o = (t_values *)malloc(sizeof(t_values));
	o->y = (int *)malloc(sizeof(int) * s);
	o->color = (int *)malloc(sizeof(int) * s);
	o->amount = s;
	return (o);
}

t_values			*add_points(t_values *p, int s)
{
	int				i;
	t_values		*o;

	if (p)
	{
		o = create_points(p->amount + s);
		i = -1;
		while (++i < p->amount)
		{
			o->y[i] = p->y[i];
			o->color[i] = p->color[i];
		}
		free(p->y);
		free(p->color);
		free(p);
	}
	else
		o = create_points(s);
	return (o);
}

void				add_values_to_point(t_window *w, int p, int y, int color)
{
	if (y < w->map.y_min)
		w->map.y_min = y;
	if (y > w->map.y_max)
		w->map.y_max = y;
	w->values->y[p] = y;
	w->values->color[p] = color;
}
