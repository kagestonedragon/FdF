/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:31:31 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 20:20:40 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <unistd.h>

int				open_file(int argc, char **argv)
{
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(1, "No such file or directory.\n", 27);
			return (ERROR_MAP);
		}
		return (fd);
	}
	else
	{
		write(1, "Usage: ./fdf file\n", 18);
		return (ERROR_MAP);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_window	*w;
	int			fd;

	if ((fd = open_file(argc, argv)) == ERROR_MAP)
		return (0);
	else
	{
		w = create_window(argv);
		if (reading(fd, w) == ERROR_MAP)
		{
			write(1, "Error, check your map.\n", 23);
			return (0);
		}
	}
	create_vectors(w);
	mlx_hook(w->win, 2, 0, keyboard_control, (void *)w);
	mlx_hook(w->win, 17, 0, close_window, (void *)w);
	mlx_hook(w->win, 4, 0, mouse_click, (void *)w);
	mlx_hook(w->win, 5, 0, mouse_unclick, (void *)w);
	mlx_hook(w->win, 6, 0, mouse_move, (void *)w);
	mlx_loop(w->mlx);
	return (0);
}
