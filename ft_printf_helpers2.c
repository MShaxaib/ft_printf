/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:02:29 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/10 20:27:21 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftt_putnbr(int n, int fd)
{
	char	c;
	int		ctr;

	ctr = 0;
	c = '0';
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		ctr += 11;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ctr += 1;
		ctr += ftt_putnbr(n * -1, fd);
	}
	else if (n < 10)
	{
		c += n;
		write(fd, &c, 1);
		ctr += 1;
	}
	else
		ctr = ftt_putnbr(n / 10, fd) + ftt_putnbr(n % 10, fd);
	return (ctr);
}

int	ftt_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != 0)
			write(fd, &s[i++], 1);
	}
	else
	{
		write(fd, "(null)", 6);
		return (6);
	}
	return (i);
}

int	ftt_putunsignednbr_fd(unsigned int n, int fd)
{
	int		count;
	char	c;

	c = '0';
	count = 0;
	if (n < 10)
	{
		c += n;
		count += ftt_putchar(c, 1);
	}
	else
	{
		count += ftt_putnbr(n / 10, fd);
		count += ftt_putnbr(n % 10, fd);
	}
	return (count);
}

int	ftt_printhex(int nbr, char identifier)
{
	char			*hexadecimalbase;
	int				i;
	unsigned int	num;

	if (identifier == 'x')
		hexadecimalbase = "0123456789abcdef";
	else
		hexadecimalbase = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)nbr;
	if (num > 15)
		i += ftt_printhex(num / 16, identifier);
	i += ftt_printchar(hexadecimalbase[num % 16]);
	return (i);
}
