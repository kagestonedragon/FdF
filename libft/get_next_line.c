/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:11:51 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 18:26:47 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

static char		**check_empty_string(char **stack)
{
	if (!(*stack))
		*stack = ft_strnew(0);
	return (stack);
}

static int		generate_new_line(char **stack, char **line)
{
	char		*temporary;

	if (!(*stack)[0])
		return (0);
	if (ft_strchr(*stack, '\n'))
	{
		*(ft_strchr(*stack, '\n')) = '\0';
		*line = ft_strdup(*stack);
		temporary = ft_strdup(ft_strchr(*stack, '\0') + 1);
		free(*stack);
		if (temporary)
		{
			*stack = ft_strdup(temporary);
			free(temporary);
		}
	}
	else
	{
		*line = ft_strdup(*stack);
		ft_memdel((void **)stack);
	}
	return (1);
}

static void		generate_new_string(char **stack, char *buffer)
{
	char		*temporary;

	temporary = ft_strjoin(*stack, buffer);
	free(*stack);
	*stack = ft_strdup(temporary);
	free(temporary);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stack[FD_MAX];
	char		buffer[BUFF_SIZE + 1];
	int			amount;

	if (fd < 0 || read(fd, buffer, 0) || !line || fd > FD_MAX)
		return (-1);
	check_empty_string(&(stack[fd]));
	while (!(ft_strchr(stack[fd], '\n')))
	{
		amount = read(fd, buffer, BUFF_SIZE);
		buffer[amount] = '\0';
		if (!amount)
			break ;
		generate_new_string(&(stack[fd]), buffer);
	}
	return (generate_new_line(&(stack[fd]), line));
}
