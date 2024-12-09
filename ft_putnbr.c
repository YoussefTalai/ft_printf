/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytalai <ytalai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:58:08 by ytalai            #+#    #+#             */
/*   Updated: 2024/12/06 14:31:37 by ytalai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		i;
	char	str[12];
	long	nb;
	int		count;

	1 && (nb = n, count = 0);
	if (n < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		count++;
	}
	i = 0;
	while ((nb / 10) != 0)
	{
		str[i++] = ((nb % 10) + '0');
		nb = nb / 10;
	}
	str[i] = ((nb % 10) + '0');
	while (i >= 0)
	{
		write(1, &str[i--], 1);
		count++;
	}
	return (count);
}
