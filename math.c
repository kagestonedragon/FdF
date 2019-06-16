/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:46:21 by emedea            #+#    #+#             */
/*   Updated: 2019/05/17 13:00:09 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void                rotation_matrix(t_matrix *z, t_matrix *x, float theta)
{
    init_matrix(z);
    z->m[0][0] = cos(theta);
    z->m[0][1] = sin(theta);
    z->m[1][0] = -sin(theta);
    z->m[1][1] = cos(theta);
    z->m[2][2] = 1.0f;
    z->m[3][3] = 1.0f;

    init_matrix(x);
    x->m[0][0] = 1.0f;
    x->m[1][1] = cos(theta * 0.5f);
    x->m[1][2] = sin(theta * 0.5f);
    x->m[2][1] = -sin(theta * 0.5f);
    x->m[2][2] = cos(theta * 0.5f);
    x->m[3][3] = 1.0f;
}

void                projection_matrix(float z_near, float z_far, float fov, t_matrix *m)
{
    float           height;
    float           width;
    float           fov_rad;

    height = (float)MAP_HEIGHT;
    width = (float)MAP_WIDTH;
    fov_rad = 1.0f / tan(fov * 0.5f / 180.0f * 3.14159f);
    init_matrix(m);
    m->m[0][0] = (height / width) * fov_rad;
    m->m[1][1] = fov_rad; 
    m->m[2][2] = z_far / (z_far - z_near);
    m->m[3][2] = (z_far * z_near * (-1)) / (z_far - z_near);
    m->m[2][3] = 1.0f;
    m->m[3][3] = 0.0f;
}
