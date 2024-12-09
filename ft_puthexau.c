/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytalai <ytalai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 23:49:40 by ytalai            #+#    #+#             */
/*   Updated: 2024/12/04 13:12:42 by ytalai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexau(unsigned int n)
{
	char	*hexu;
	char	str[9];
	int		i;
	int		count;

	hexu = "0123456789ABCDEF";
	i = 0;
	count = 0;
	while (n / 16 != 0)
	{
		str[i++] = hexu[n % 16];
		n /= 16;
	}
	str[i++] = hexu[n % 16];
	while (i > 0)
	{
		write(1, &str[--i], 1);
		count++;
	}
	return (count);
}
