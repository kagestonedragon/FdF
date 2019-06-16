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
#include <stdbool.h>
#include "minilibx/mlx.h"
#include "fdf.h"

int            draw_figure(int key, void *params)
{
    static float i;
    // 3d points
    t_point2d   p1_3d;
    t_point2d   p2_3d;
    t_point2d   p3_3d;
    t_point2d   p4_3d;
    t_point2d   p5_3d;
    t_point2d   p6_3d;
    t_point2d   p7_3d;
    t_point2d   p8_3d;

    // init values for cube in 3d
    p1_3d.x = 0;
    p1_3d.y = 0;
    p1_3d.z = 0;

    p2_3d.x = 1;
    p2_3d.y = 0;
    p2_3d.z = 0;

    p3_3d.x = 1;
    p3_3d.y = 1;
    p3_3d.z = 0;

    p4_3d.x = 0;
    p4_3d.y = 1;
    p4_3d.z = 0;

    p5_3d.x = 0;
    p5_3d.y = 0;
    p5_3d.z = 1;

    p6_3d.x = 1;
    p6_3d.y = 0;
    p6_3d.z = 1;

    p7_3d.x = 1;
    p7_3d.y = 1;
    p7_3d.z = 1;

    p8_3d.x = 0;
    p8_3d.y = 1;
    p8_3d.z = 1;

    // rotation of 3d points
    t_point2d   p1_3d_r;
    t_point2d   p2_3d_r;
    t_point2d   p3_3d_r;
    t_point2d   p4_3d_r;
    t_point2d   p5_3d_r;
    t_point2d   p6_3d_r;
    t_point2d   p7_3d_r;
    t_point2d   p8_3d_r;

    // 2d point
    t_point2d   p1_2d;
    t_point2d   p2_2d;
    t_point2d   p3_2d;
    t_point2d   p4_2d;
    t_point2d   p5_2d;
    t_point2d   p6_2d;
    t_point2d   p7_2d;
    t_point2d   p8_2d;

    // vectors from points
    t_vector2d  v1;
    t_vector2d  v2;
    t_vector2d  v3;
    t_vector2d  v4;
    t_vector2d  v5;
    t_vector2d  v6;
    t_vector2d  v7;
    t_vector2d  v8;
    t_vector2d  v9;
    t_vector2d  v10;
    t_vector2d  v11;
    t_vector2d  v12;

    // create projection matrix
    t_matrix    p_m;

    // create rotation matrixes
    t_matrix    rz_m;
    t_matrix    rx_m;

    // init values to projection matrix
    projection_matrix(0.1f, 1000.0f, 30.0f, &p_m);

    t_window    *ws;
    ws = (t_window *)params;
        mlx_clear_window(ws->mlx_ptr, ws->win_ptr);
        rotation_matrix(&rz_m, &rx_m, i);
        i += 0.05f;

        // rotated x
        t_point2d   p1_3d_rx;
        t_point2d   p2_3d_rx;
        t_point2d   p3_3d_rx;
        t_point2d   p4_3d_rx;
        t_point2d   p5_3d_rx;
        t_point2d   p6_3d_rx;
        t_point2d   p7_3d_rx;
        t_point2d   p8_3d_rx;

        matrix_multiplication(p1_3d, &p1_3d_r, rz_m);
        matrix_multiplication(p2_3d, &p2_3d_r, rz_m);
        matrix_multiplication(p3_3d, &p3_3d_r, rz_m);
        matrix_multiplication(p4_3d, &p4_3d_r, rz_m);
        matrix_multiplication(p5_3d, &p5_3d_r, rz_m);
        matrix_multiplication(p6_3d, &p6_3d_r, rz_m);
        matrix_multiplication(p7_3d, &p7_3d_r, rz_m);
        matrix_multiplication(p8_3d, &p8_3d_r, rz_m);

        matrix_multiplication(p1_3d_r, &p1_3d_rx, rx_m);
        matrix_multiplication(p2_3d_r, &p2_3d_rx, rx_m);
        matrix_multiplication(p3_3d_r, &p3_3d_rx, rx_m);
        matrix_multiplication(p4_3d_r, &p4_3d_rx, rx_m);
        matrix_multiplication(p5_3d_r, &p5_3d_rx, rx_m);
        matrix_multiplication(p6_3d_r, &p6_3d_rx, rx_m);
        matrix_multiplication(p7_3d_r, &p7_3d_rx, rx_m);
        matrix_multiplication(p8_3d_r, &p8_3d_rx, rx_m);

        p1_3d_rx.z += 3.0f;
        p2_3d_rx.z += 3.0f;
        p3_3d_rx.z += 3.0f;
        p4_3d_rx.z += 3.0f;
        p5_3d_rx.z += 3.0f;
        p6_3d_rx.z += 3.0f;
        p7_3d_rx.z += 3.0f;
        p8_3d_rx.z += 3.0f;
   
    // 3d coordinates to 2d coordinates
        matrix_multiplication(p1_3d_rx, &p1_2d, p_m);
        matrix_multiplication(p2_3d_rx, &p2_2d, p_m);
        matrix_multiplication(p3_3d_rx, &p3_2d, p_m);
        matrix_multiplication(p4_3d_rx, &p4_2d, p_m);
        matrix_multiplication(p5_3d_rx, &p5_2d, p_m);
        matrix_multiplication(p6_3d_rx, &p6_2d, p_m);
        matrix_multiplication(p7_3d_rx, &p7_2d, p_m);
        matrix_multiplication(p8_3d_rx, &p8_2d, p_m);    

    // scale to the console
        p1_2d.x += 2.2f;
        p1_2d.y += 2.2f;
    
        p2_2d.x += 2.2f;
        p2_2d.y += 2.2f;

        p3_2d.x += 2.2f;
        p3_2d.y += 2.2f;
    
        p4_2d.x += 2.2f;
        p4_2d.y += 2.2f;
    
        p5_2d.x += 2.2f;
        p5_2d.y += 2.2f;

        p6_2d.x += 2.2f;
        p6_2d.y += 2.2f;

        p7_2d.x += 2.2f;
        p7_2d.y += 2.2f;

        p8_2d.x += 2.2f;
        p8_2d.y += 2.2f;

        p1_2d.x *= 0.2f * (float)MAP_WIDTH;
        p2_2d.x *= 0.2f * (float)MAP_WIDTH;
        p3_2d.x *= 0.2f * (float)MAP_WIDTH;
        p4_2d.x *= 0.2f * (float)MAP_WIDTH;
        p5_2d.x *= 0.2f * (float)MAP_WIDTH;
        p6_2d.x *= 0.2f * (float)MAP_WIDTH;
        p7_2d.x *= 0.2f * (float)MAP_WIDTH;
        p8_2d.x *= 0.2f * (float)MAP_WIDTH;

        p1_2d.y *= 0.2f * (float)MAP_HEIGHT;
        p2_2d.y *= 0.2f * (float)MAP_HEIGHT;
        p3_2d.y *= 0.2f * (float)MAP_HEIGHT;
        p4_2d.y *= 0.2f * (float)MAP_HEIGHT;
        p5_2d.y *= 0.2f * (float)MAP_HEIGHT;
        p6_2d.y *= 0.2f * (float)MAP_HEIGHT;
        p7_2d.y *= 0.2f * (float)MAP_HEIGHT;
        p8_2d.y *= 0.2f * (float)MAP_HEIGHT;

    // points to vector
        v1.x0 = p1_2d.x;
        v1.y0 = p1_2d.y;
        v1.x1 = p2_2d.x;
        v1.y1 = p2_2d.y;

        v2.x0 = p2_2d.x;
        v2.y0 = p2_2d.y;
        v2.x1 = p3_2d.x;
        v2.y1 = p3_2d.y;

        v3.x0 = p1_2d.x;
        v3.y0 = p1_2d.y;
        v3.x1 = p4_2d.x;
        v3.y1 = p4_2d.y;

        v4.x0 = p3_2d.x;
        v4.y0 = p3_2d.y;
        v4.x1 = p4_2d.x;
        v4.y1 = p4_2d.y;

        v5.x0 = p1_2d.x;
        v5.y0 = p1_2d.y;
        v5.x1 = p5_2d.x;
        v5.y1 = p5_2d.y;

        v6.x0 = p2_2d.x;
        v6.y0 = p2_2d.y;
        v6.x1 = p6_2d.x;
        v6.y1 = p6_2d.y;

        v7.x0 = p4_2d.x;
        v7.y0 = p4_2d.y;
        v7.x1 = p8_2d.x;
        v7.y1 = p8_2d.y;

        v8.x0 = p3_2d.x;
        v8.y0 = p3_2d.y;
        v8.x1 = p7_2d.x;
        v8.y1 = p7_2d.y;

        v9.x0 = p5_2d.x;
        v9.y0 = p5_2d.y;
        v9.x1 = p6_2d.x;
        v9.y1 = p6_2d.y;

        v10.x0 = p6_2d.x;
        v10.y0 = p6_2d.y;
        v10.x1 = p7_2d.x;
        v10.y1 = p7_2d.y;

        v11.x0 = p7_2d.x;
        v11.y0 = p7_2d.y;
        v11.x1 = p8_2d.x;
        v11.y1 = p8_2d.y;

        v12.x0 = p5_2d.x;
        v12.y0 = p5_2d.y;
        v12.x1 = p8_2d.x;
        v12.y1 = p8_2d.y;
        draw_line(&v1, (t_window *)params);
        draw_line(&v2, (t_window *)params);
        draw_line(&v3, (t_window *)params);
        draw_line(&v4, (t_window *)params);
        draw_line(&v5, (t_window *)params);
        draw_line(&v6, (t_window *)params);
        draw_line(&v7, (t_window *)params);
        draw_line(&v8, (t_window *)params);
        draw_line(&v9, (t_window *)params);
        draw_line(&v10, (t_window *)params);
        draw_line(&v11, (t_window *)params);
        draw_line(&v12, (t_window *)params);
        return (0);
}

void            cube_2d(t_window w)
{
    void        *params;

    params = (void *)malloc(sizeof(void) * 2);
    // init values to rotation matrixes

    // info for debug
    /*
    printf("p1: x = %0.2f, y = %0.2f\n", p1_2d.x, p1_2d.y);
    printf("p2: x = %0.2f, y = %0.2f\n", p2_2d.x, p2_2d.y);
    printf("p3: x = %0.2f, y = %0.2f\n", p3_2d.x, p3_2d.y);
    printf("p4: x = %0.2f, y = %0.2f\n", p4_2d.x, p4_2d.y);
    printf("p5: x = %0.2f, y = %0.2f\n", p5_2d.x, p5_2d.y);
    printf("p6: x = %0.2f, y = %0.2f\n", p6_2d.x, p6_2d.y);
    printf("p7: x = %0.2f, y = %0.2f\n", p7_2d.x, p7_2d.y);
    printf("p8: x = %0.2f, y = %0.2f\n", p8_2d.x, p8_2d.y);
*/
    // draw points
    /*
    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p1_2d.x, p1_2d.y, 0xFFFF22);
    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p2_2d.x, p2_2d.y, 0xFFFF22);
    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p3_2d.x, p3_2d.y, 0xFFFF22);
    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p4_2d.x, p4_2d.y, 0xFFFF22);

    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p5_2d.x, p5_2d.y, 0xFFFF22);
    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p6_2d.x, p6_2d.y, 0xFFFF22);
    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p7_2d.x, p7_2d.y, 0xFFFF22);
    mlx_pixel_put(w.mlx_ptr, w.win_ptr, p8_2d.x, p8_2d.y, 0xFFFF22);
    */

    // rotation
    params = &w;

    mlx_key_hook(w.win_ptr, draw_figure, params);
    //mlx_loop_hook(w.win_ptr, draw_figure, params);
    mlx_loop(w.mlx_ptr); 
    // draw vectors
     

}

int             main(void)
{
    t_window    window;
   
    window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, 2000, 1000, "FdF");
    cube_2d(window);
    
    mlx_loop(window.mlx_ptr);
    return (0);
}
