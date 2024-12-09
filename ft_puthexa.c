/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytalai <ytalai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:05:12 by ytalai            #+#    #+#             */
/*   Updated: 2024/12/04 13:12:04 by ytalai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_puthexa(unsigned int n)
{
	char	*hex;
	char	str[9];
	int		i;
	int		count;

	hex = "0123456789abcdef";
	i = 0;
	count = 0;
	while (n / 16 != 0)
	{
		str[i++] = hex[n % 16];
		n /= 16;
	}
	str[i++] = hex[n % 16];
	while (i > 0)
	{
		write(1, &str[--i], 1);
		count++;
	}
	return (count);
}
