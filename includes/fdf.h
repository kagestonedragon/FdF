/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:46:49 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 20:20:22 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_WIDTH		1920
# define W_HEIGHT		1080
# define W_MENU_WIDTH	210
# define ERROR_MAP		-1

typedef enum{
	false,
	true
}	t_bool;

typedef struct			s_values{
	int					amount;
	int					*y;
	int					*color;
}						t_values;

typedef struct			s_point{
	double				x;
	double				y;
	double				z;
	int					color;
}						t_point;

typedef struct			s_vector{
	t_point				begin;
	t_point				end;
	int					dx;
	int					dy;
}						t_vector;

typedef struct			s_map{
	int					points;
	int					width;
	int					y_min;
	int					y_max;
	int					y_min_pos;
	int					y_max_pos;
	int					x_min_pos;
	int					x_max_pos;
	int					height;
	t_bool				color;
	int					color_v[5];
}						t_map;

typedef struct			s_image{
	void				*image;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_camera{
	double				aspect_ratio;
	double				alpha;
	double				beta;
	double				theta;
	float				size;
	float				top_size;
	int					x;
	int					y;

}						t_camera;

typedef struct			s_mouse{
	t_bool				left_click;
	t_bool				right_click;
	t_bool				scroll_click;
	int					old_x;
	int					old_y;
	int					x;
	int					y;
}						t_mouse;

typedef struct			s_window{
	void				*mlx;
	void				*win;
	t_values			*values;
	t_image				image;
	t_map				map;
	t_camera			camera;
	t_mouse				mouse;
}						t_window;

t_window				*create_window(char **argv);
int						close_window(int key, void *param);

int						reading(int fd, t_window *w);
t_values				*add_points(t_values *p, int s);
void					add_values_to_point(t_window *w, int p,
		int y, int color);

void					create_vectors(t_window *w);

void					projection(t_vector *v, t_window *w);

void					draw_background(t_window *w);
void					draw_instructions(t_window *w);
void					draw_info(t_window *w);
void					draw_xy(t_window *w);
void					bresenham_line(t_vector *v, t_window *w);

int						keyboard_control(int key, void *param);
void					zoom(int key, t_window *w);

int						mouse_click(int button, int x, int y, void *param);
int						mouse_unclick(int button, int x, int y, void *param);
int						mouse_move(int x, int y, void *param);

int						return_color(double y, t_window *w);
int						get_light(int start, int end, double percentage);
double					percent(int start, int end, int current);
void					pick_color(int key, t_window *w);
int						pixel_color(t_vector *v, int x, int y, int color);
int						ft_atoi_base(const char *str, int base);
int						ft_isnumber(char *str, int base);
void					new_color(int key, t_window *w);

int						close_window(int key, void *param);

int						abs(int x);
double					max_top(double x);
double					min_top(double x);
double					min_size(double x);

#endif
