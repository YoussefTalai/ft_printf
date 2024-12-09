/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytalai <ytalai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:27:23 by ytalai            #+#    #+#             */
/*   Updated: 2024/12/06 18:50:02 by ytalai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char f, va_list args)
{
	int	count;

	count = 0;
	if (f == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (f == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (f == 'p')
		count += ft_putaddress(va_arg(args, void *));
	else if (f == 'u')
		count += ft_unsigned(va_arg(args, unsigned int));
	else if (f == 'X')
		count += ft_puthexau(va_arg(args, unsigned int));
	else if (f == 'x')
		count += ft_puthexa(va_arg(args, unsigned int));
	else if (f == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(f);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += check_format(*format, args);
		}
		else
			count += write(1, format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}
