/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:37:01 by emedea            #+#    #+#             */
/*   Updated: 2019/07/24 19:43:46 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		abs(int x)
{
	if (x < 0)
		return (x * (-1));
	return (x);
}

double	max_top(double x)
{
	if (x > 3)
		return (3);
	return (x);
}

double	min_top(double x)
{
	if (x < 0)
		return (0);
	return (x);
}

double	min_size(double x)
{
	if (x < 0)
		return (0);
	return (x);
}
