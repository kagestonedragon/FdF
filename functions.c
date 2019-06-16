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

int     ft_abs(int nb)
{
    if (nb < 0)
        return (nb * (-1));
    return (nb);
}

void    swap(int *a, int *b)
{
    int c;
    
    if (!a || !b)
        return ;
    c = *a;
    *a = *b;
    *b = c;
}

void    matrix_multiplication(t_point2d p3d, t_point2d *p2d, t_matrix m)
{
    p2d->x = (float)p3d.x * m.m[0][0] + (float)p3d.y * m.m[1][0] + (float)p3d.z * m.m[2][0] + m.m[3][0];
    p2d->y = (float)p3d.x * m.m[0][1] + (float)p3d.y * m.m[1][1] + (float)p3d.z * m.m[2][1] + m.m[3][1];
    p2d->z = (float)p3d.x * m.m[0][2] + (float)p3d.y * m.m[1][2] + (float)p3d.z * m.m[2][2] + m.m[3][2];
    p2d->w = (float)p3d.x * m.m[0][3] + (float)p3d.y * m.m[1][3] + (float)p3d.z * m.m[2][3] + m.m[3][3];

    if (p2d->w != 0.0f)
    {
        p2d->x /= p2d->w;
        p2d->y /= p2d->w;
        p2d->z /= p2d->w;
    }
}

void    init_matrix(t_matrix *m)
{
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            m->m[i][j] = 0.0f;
    }
}
