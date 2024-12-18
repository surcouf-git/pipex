/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:06:19 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/02 17:21:33 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	char	c;
	int		i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_putunsigned(nb / 10);
	}
	c = nb % 10 + '0';
	write(1, &c, 1);
	i++;
	return (i);
}
/*
#include <stdio.h>
int main()
{
	int i = ft_putunsigned(123456);
	printf("\n");
	int o = printf("%u", -123456);
	printf("\n%u\n%u", i, o);
	return (0);
}*/
