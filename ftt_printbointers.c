/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_printbointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:00:02 by mshazaib          #+#    #+#             */
/*   Updated: 2023/08/08 21:05:44 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	address(unsigned long int Li)
{
	char *hexadecimalbase;
	int	i;
	hexadecimalbase = "0123456789abcdef";
	i = 0;

	if(Li > 15)
	
		i += address(Li / 16);
	i += ftt_printchar(hexadecimalbase[Li % 16]);
	return(i);
 
}

int ftt_printpointer(void *var)
{
	unsigned long int nbr;
	int l;
	
	nbr = (unsigned long int)var;
	l = 0;
	l += ftt_printstring("0x");
	l += address(nbr);
	return(l);
}