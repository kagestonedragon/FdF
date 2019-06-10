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

#include <stdio.h>
#include <stdlib.h>
#include "minilibx/mlx.h"
#include "fdf.h"

static int      ft_abs(int input)
{
    if (input < 0)
        return (input * -1);
    return (input);
}

static void     swap(int *a, int *b)
{
    int         c;

    c = *a;
    *a = *b;
    *b = c;
}

int             coordinates(t_vector *vector)
{
    int         result;
    
    result = 0;
    if (ft_abs(vector->y1 - vector->y0) > ft_abs(vector->x1 - vector->x0))
    {
        result = 1;
        swap(&vector->x0, &vector->y0);
        swap(&vector->x1, &vector->y1);
    }
    if (vector->x0 > vector->x1)
    {
        swap(&vector->x0, &vector->x1);
        swap(&vector->y0, &vector->y1);
    }
    vector->dx = vector->x1 - vector->x0;
    vector->dy = ft_abs(vector->y1 - vector->y0);
    vector->x = vector->x0;
    vector->y = vector->y0;
    return (result);
}

void            Bresenham(t_vector *vector, t_window window)
{
    int         error;
    int         y_step;
    int         step;

    step = coordinates(vector);
    error = vector->dx / 2;
    y_step = (vector->y0 > vector->y1) ? 1 : -1;
    while (vector->x <= vector->x1)
    {
        mlx_pixel_put(window.mlx_ptr, window.win_ptr, step ? vector->y : vector->x, step ? vector->x : vector->y, 0xFFFF22);
        error -= vector->dy;
        if (error < 0)
        {
            vector->y -= y_step;
            error += vector->dx;
        }
        vector->x += 1;
    }
}

void            draw_simple_map(t_vector *vector, t_window window)
{
    int         x_s;
    int         y_s;
    int         x_e;
    int         y_e;
    int         i;

    x_s = 800;
    y_s = 400;
    x_e = 200;
    y_e = 600;
    vector->x0 = x_s;
    vector->y0 = y_s;
    vector->x1 = x_e;
    vector->y1 = y_e;
    i = -1;
    while (++i < 11)
    {
        Bresenham(vector, window);
        vector->x0 += 100;
        vector->x1 += 100;
    }
    vector->y0 = 400;
    vector->y1 = 400;
    vector->x0 = 800;
    vector->x1 = 1800;
    i = -1;
    while (++i < 11)
    {
        Bresenham(vector, window);
        vector->y0 += 20;
        vector->y1 += 20;
        vector->x0 -= 60;
        vector->x1 -= 60;
    }
    mlx_string_put(window.mlx_ptr, window.win_ptr, 800, 200, 0xFFFFFF, "PRIVET, RABOTYAGI");
}

int             main(void)
{
    t_window    window;
    t_vector    vector;

    window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, 2000, 1000, "FdF");
    //Bresenham(&vector, window);
    draw_simple_map(&vector, window);
    mlx_loop(window.mlx_ptr);
    return (0);
}
