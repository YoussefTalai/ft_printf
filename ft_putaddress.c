/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytalai <ytalai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:51:43 by ytalai            #+#    #+#             */
/*   Updated: 2024/12/04 13:11:05 by ytalai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(void *ptr)
{
	unsigned long	addr;
	char			*hex;
	char			str[16];
	int				i;
	int				count;

	addr = (unsigned long)ptr;
	1 && (i = 0, count = 2, hex = "0123456789abcdef");
	write(1, "0x", 2);
	while (addr != 0)
	{
		str[i++] = hex[addr % 16];
		addr /= 16;
	}
	if (i == 0)
		str[i++] = '0';
	while (i > 0)
	{
		i--;
		write(1, &str[i], 1);
		count++;
	}
	return (count);
}
