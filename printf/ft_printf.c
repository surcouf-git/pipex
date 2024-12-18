/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:57:03 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/03 14:33:01 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_pointer(void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	else
		return (ft_putptr((unsigned long)ptr));
}

static int	ft_type(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (str[i] == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str[i] == 'p')
		i += ft_handle_pointer(va_arg(args, void *));
	else if (str[i] == 'd')
		i += ft_putdec(va_arg(args, int));
	else if (str[i] == 'i')
		i += ft_putint(va_arg(args, int));
	else if (str[i] == 'u')
		i += ft_putunsigned(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		i += ft_puthex_down(va_arg(args, unsigned int));
	else if (str[i] == 'X')
		i += ft_puthex_up(va_arg(args, unsigned int));
	else if (str[i] == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX%", *str))
				i += ft_type(str, args);
		}
		else
			i += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (i);
}
/*
#include <stdio.h>
int main()
{
	char *ptr = NULL;
	char *str = "OUI";
	char *str2 = "de caracteres";
	int a = 1;

	int value = ft_printf("Ceci %s est %d chaine %s %p", str, a, str2, &ptr);
	printf("\n%d", value);
	ft_printf("blabla %p %p blabla", 0, 0);
	return (0);
}*/
