/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 19:24:07 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/10 18:09:49 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftt_printstring(const char *c)
{
	int	str_len;

	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_len = ftt_strlen(c);
	write(1, c, str_len);
	return (str_len);
}

int	ftt_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ftt_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ftt_putchar(int ch, int fd)
{
	char	x;

	x = ch;
	return (write(fd, &x, 1));
}
