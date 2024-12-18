/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:43:05 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/03 14:02:39 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long addr)
{
	char	c;
	int		i;

	i = 0;
	if (addr == 0)
		return (write (1, "0x0", 3));
	if (addr < 16)
		i += ft_putstr("0x");
	if (addr >= 16)
		i += ft_putptr(addr / 16);
	if ((addr % 16) > 9 && (addr % 16) < 16)
		i += ft_putchar((addr % 16) + 87);
	else
	{
		c = addr % 16 + '0';
		write (1, &c, 1);
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int o = 0;
	char *ptr = NULL;
	i = printf("%p", &ptr);
	printf("\n");
	o = ft_putptr((unsigned long)&ptr);
	printf("\n%d", i);
	printf("\n%d\n", o);
	ft_putptr(3735928559);
	return 0;
}*/
