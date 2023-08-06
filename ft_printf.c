/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:18:35 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/06 18:55:49 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int printhex(unsigned long long n, int small)
// {
	
// }

int	formatchecker(const char *format, va_list arg, int i)
{
	if (format[i] == 's')
		return (ftt_putstr_fd(((char *)va_arg(arg, char *)), 1));
	else if (format[i] == 'c')
		return (ftt_putchar(((char)va_arg(arg, int)), 1));
	else if (format[i] == 'd')
		return (ftt_putnbr_fd(((int)va_arg(arg, int)), 1));
	else if (format[i] == 'i')
		return (ftt_putnbr_fd(((int)va_arg(arg, int)), 1));
	else if (format[i] == 'p')
		return (0); 	// pointer argument in hexadecimal
	else if (format[i] == 'u')
		return (ftt_putunsignednbr_fd(va_arg(arg, int), 1));
	else if (format[i] == 'x')
		return (0); 	// hexadecmial conversion Lowercase
	else if (format[i] == 'X')
		return (0); 	//hexadecimal conversion Uppercase
	else if (format[i] == '%')
		return (ftt_putchar('%', 1));
	return (0);
}

int	ft_printf(char *format, ...)
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
		i++;
	}
	va_end(arg);
	return (count);
}
