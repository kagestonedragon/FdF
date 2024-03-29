/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:56:36 by emedea            #+#    #+#             */
/*   Updated: 2019/05/17 10:36:43 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_begin;

	s1_begin = s1;
	while (*s1 != '\0')
	{
		s1++;
	}
	while (*s2 != '\0' && n-- > 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (s1_begin);
}
