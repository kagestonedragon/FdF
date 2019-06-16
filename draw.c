/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:09:32 by emedea            #+#    #+#             */
/*   Updated: 2019/06/05 13:44:11 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"

static int          coordinates(t_vector2d *v, int *x, int *y)
{
    int             direction;

    direction = 0;
    if (ft_abs(v->y1 - v->y0) > ft_abs(v->x1 - v->x0))
    {
        direction = 1;
        swap(&v->x0, &v->y0);
        swap(&v->x1, &v->y1);
    }
    if (v->x0 > v->x1)
    {
        swap(&v->x0, &v->x1);
        swap(&v->y0, &v->y1);
    }
    v->dx = v->x1 -v->x0;
    v->dy = ft_abs(v->y1 - v->y0);
    *x = v->x0;
    *y = v->y0;
    return (direction);
}

void                draw_line(t_vector2d *v, t_window *w)
{
    int             error;
    int             y_step;
    int             step;
    int             x;
    int             y;

    step = coordinates(v, &x, &y);
    error = v->dx / 2;
    y_step = (v->y0 > v->y1) ? 1 : -1;
    while (x <= v->x1)
    {
        mlx_pixel_put(w->mlx_ptr, w->win_ptr, step ? y : x, step ? x : y, 0xFFFF22);
        error -= v->dy;
        if (error < 0)
        {
            y -= y_step;
            error += v->dx;
        }
        x += 1;
    }
}
