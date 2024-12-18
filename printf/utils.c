/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:14:32 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/02 17:19:49 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	c;
	int		value;

	value = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		value++;
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		value += ft_putnbr (nb / 10);
	}
	c = nb % 10 + '0';
	write (1, &c, 1);
	value++;
	return (value);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ca;

	ca = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ca)
			return ((char *)s);
		s++;
	}
	if (ca == '\0')
		return ((char *)s);
	return (NULL);
}
