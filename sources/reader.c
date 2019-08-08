/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:46:23 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 20:18:44 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int		line_width(char **v)
{
	int			i;

	i = 0;
	while (v[i])
		i++;
	return (i);
}

static void		free_values(char **v)
{
	int			i;

	i = -1;
	while (v[++i])
		free(v[i]);
	free(v);
}

static int		parsing(char **v, t_window *w)
{
	int			i;
	int			line_size;
	char		**parts;

	line_size = line_width(v);
	w->values = add_points(w->values, line_size);
	if (!w->map.width)
		w->map.width = line_size;
	else if (w->map.width != line_size)
		return (ERROR_MAP);
	i = -1;
	while (v[++i])
	{
		if (!(parts = ft_strsplit(v[i], ',')))
			return (ERROR_MAP);
		if (!(ft_isnumber(parts[0], 10)))
			return (ERROR_MAP);
		if (parts[1] && !ft_isnumber(parts[1], 16))
			return (ERROR_MAP);
		add_values_to_point(w, (w->values->amount - line_size--),
				ft_atoi(parts[0]), (parts[1]) ?
				ft_atoi_base(parts[1], 16) : GRAY);
		free_values(parts);
	}
	return (0);
}

int				reading(int fd, t_window *w)
{
	int			result;
	char		*line;
	char		**values;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(values = ft_strsplit(line, ' ')))
			return (0);
		if (parsing(values, w) == ERROR_MAP)
			return (ERROR_MAP);
		free_values(values);
		free(line);
		w->map.height++;
	}
	w->map.points = w->map.height * w->map.width;
	return (result);
}
