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

#ifndef FDF_H
# define FDF_H
# define MAP_HEIGHT 1000;
# define MAP_WIDTH 2000;


typedef struct          s_window{
    void                *mlx_ptr;
    void                *win_ptr;
}                       t_window;

typedef struct          s_point2d{
    float               x;
    float               y;
    float               z;
    float               w;
}                       t_point2d;

typedef struct          s_vector2d{
    int                 x0;
    int                 y0;
    int                 x1;
    int                 y1;
    int                 dx;
    int                 dy;
}                       t_vector2d;

typedef struct          s_matrix{
    float               m[4][4];
}                       t_matrix;

int                     ft_abs(int nb);
void                    swap(int *a, int *b);

void                    projection_matrix(float z_near, float z_far, float fov, t_matrix *m);
void                    rotation_matrix(t_matrix *z, t_matrix *x, float theta);

void                    matrix_multiplication(t_point2d p3d, t_point2d *p2d, t_matrix m);
void                    init_matrix(t_matrix *m);

void                    draw_line(t_vector2d *v, t_window *w);

#endif
