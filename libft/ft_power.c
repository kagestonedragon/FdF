/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:22:01 by emedea            #+#    #+#             */
/*   Updated: 2019/05/17 12:11:34 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		if (power % 2 == 0)
			return (nb * nb * ft_power(nb, power - 2));
		else
			return (nb * nb * ft_power(nb, power - 1));
	}
}
