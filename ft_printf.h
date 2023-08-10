/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:42:17 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/10 18:05:37 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ftt_putchar(int ch, int fd);
int	ftt_printchar(int c);
int	ftt_putnbr(int nbr, int fd);
int	ftt_putstr_fd(char *s, int fd);
int	ftt_putunsignednbr_fd(unsigned int n, int fd);
int	ftt_printhex(int nbr, char identifier);
int	ftt_printpointer(void *var);
int	address(unsigned long int Li);
int	ftt_strlen(char const *str);
int	ftt_printstring(const char *c);

#endif