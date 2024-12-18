/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:37:08 by mvannest          #+#    #+#             */
/*   Updated: 2024/11/03 13:18:55 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_printf(const char *format, ...);
int		ft_putdec(int nb);
int		ft_putint(int nb);
int		ft_putptr(unsigned long addr);
int		ft_putunsigned(unsigned int nb);
int		ft_puthex_up(unsigned int nb);
int		ft_puthex_down(unsigned long long nb);
int		ft_putnbr(int nb);
int		ft_putstr(const char *str);
int		ft_putchar(int c);
#endif
