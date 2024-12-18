/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:17:36 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/02 15:03:36 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(int nb)
{
	int	i;

	i = ft_putnbr(nb);
	return (i);
}
/*
#include <stdio.h>
int main()
{
	int i;
	
	i = ft_putdec(15648);
	printf("\n%d", i);
	return (0);
}*/
