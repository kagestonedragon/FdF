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
# define MAP_WIDTH 1000;

typedef struct          s_window{
    void                *mlx_ptr;
    void                *win_ptr;
}                       t_window;

typedef struct          s_vector{
    int                 x0;
    int                 y0;
    int                 x1;
    int                 y1;
    int                 x;
    int                 y;
    int                 dx;
    int                 dy;
}                       t_vector;

#endif
