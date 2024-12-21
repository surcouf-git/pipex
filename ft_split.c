/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvannest <mvannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:41:09 by mvannest          #+#    #+#             */
/*   Updated: 2024/12/21 15:41:10 by mvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	return (word_len);
}

static size_t	ft_wordcnt(const char *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

static void	ft_freeall(char **tableau, size_t i)
{
	while (i > 0)
	{
		i--;
		free(tableau[i]);
	}
	free(tableau);
}

static int	ft_fillwords(char **tableau, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			word_len = ft_wordlen(s + j, c);
			tableau[i] = malloc((word_len + 1) * sizeof(char));
			if (!tableau[i])
				return (0);
			ft_strlcpy(tableau[i++], s + j, word_len + 1);
			j = j + ft_wordlen(s + j, c);
		}
		else
			j++;
	}
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t		word_count;
	char		**tableau;

	word_count = ft_wordcnt(s, c);
	tableau = malloc((word_count + 1) * sizeof(char *));
	if (!tableau)
		return (NULL);
	tableau[word_count] = NULL;
	if (!ft_fillwords(tableau, s, c))
	{
		ft_freeall(tableau, word_count);
		return (NULL);
	}
	return (tableau);
}
