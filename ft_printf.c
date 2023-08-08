/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:18:35 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/08 21:17:08 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formatchecker(const char *format, va_list arg, int i)
{
	if (format[i] == 's')
		return (ftt_putstr_fd(((char *)va_arg(arg, char *)), 1));
	else if (format[i] == 'c')
		return (ftt_putchar(((char)va_arg(arg, int)), 1));
	else if (format[i] == 'd')
		return (ftt_putnbr(va_arg(arg, int), 1));
	else if (format[i] == 'i')
		return (ftt_putnbr(va_arg(arg, int), 1));
	else if (format[i] == 'p')
		return ftt_printpointer(va_arg(arg, void *));
	else if (format[i] == 'u')
		return (ftt_putunsignednbr_fd(va_arg(arg, int), 1));
	else if (format[i] == 'x')
		return (ftt_printhex(va_arg(arg, int), format[i]));
	else if (format[i] == 'X')
		return (ftt_printhex(va_arg(arg, int), format[i]));
	else if (format[i] == '%')
		return (ftt_putchar('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += formatchecker(format, arg, i + 1);
		else 
			count += ftt_putchar(format[i], 1);
		if (format[i] == '%')
			i += 2;
		else
			i++;
	}
	va_end(arg);
	return (count);
}
