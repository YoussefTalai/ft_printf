/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytalai <ytalai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 00:01:06 by ytalai            #+#    #+#             */
/*   Updated: 2024/12/03 00:01:09 by ytalai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	int		i;
	char	str[12];
	int		count;

	i = 0;
	count = 0;
	while (n / 10 != 0)
	{
		str[i] = (n % 10) + '0';
		i++;
		n = n / 10;
	}
	str[i] = (n % 10) + '0';
	while (i >= 0)
	{
		write(1, &str[i], 1);
		count++;
		i--;
	}
	return (count);
}
