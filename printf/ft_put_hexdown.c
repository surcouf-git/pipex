/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexdown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:45:21 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/03 12:26:40 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_down(unsigned long long nb)
{
	int		i;
	char	c;

	i = 0;
	if (nb >= 16)
		i += ft_puthex_down(nb / 16);
	if ((nb % 16) > 9 && (nb % 16) < 16)
		i += ft_putchar((nb % 16) + 87);
	else
	{
		c = nb % 16 + '0';
		write(1, &c, 1);
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

	i = ft_puthex_down(3735928559);
	printf("\n");
	o = printf("%lx", 3735928559);
	printf("\n%d\n%d", o, i);
	return (0);
}*/
