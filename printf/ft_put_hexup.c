/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:10:01 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/03 12:53:34 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_up(unsigned int nb)
{
	int		i;
	char	c;

	i = 0;
	if (nb >= 16)
		i += ft_puthex_up(nb / 16);
	if ((nb % 16) > 9 && (nb % 16) < 16)
		i += ft_putchar((nb % 16) + 55);
	else
	{
		c = nb % 16 + '0';
		write (1, &c, 1);
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main()
{
	int i;
	int o;

	i = ft_puthex_up(0);
	printf("\n");
	o = printf("%X", 0);
	printf("\n%d\n%d", o, i);
	return (0);
}*/
