/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:26:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/03/24 23:25:50 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checksep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	ft_countwords(char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && checksep(str[i], sep))
			i++;
		if (str[i] && !checksep(str[i], sep))
		{
			i++;
			words++;
		}
		while (str[i] && !checksep(str[i], sep))
			i++;
	}
	return (words);
}

static int	sstrlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !checksep(str[i], c))
		i++;
	return (i);
}

static char	*mallocwords(char *str, char **words, char c, int t)
{
	int		i;
	int		j;
	char	*word;

	j = 0;
	i = 0;
	word = (char *)malloc(sizeof(char) * (sstrlen(str, c) + 1));
	if (!word)
	{
		while (i < t)
			free(words[i++]);
		return (NULL);
	}
	while (str[i] && !checksep(str[i], c))
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	char	**words;
	int		j;

	j = 0;
	if (!str)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (ft_countwords(str, c) + 1));
	if (!words)
		return (NULL);
	while (*str)
	{
		while (*str && checksep(*str, c))
			str++;
		if (*str && !checksep(*str, c))
		{
			words[j] = mallocwords(str, words, c, j);
			if (!words[j])
				return (free(words), NULL);
			j++;
		}
		while (*str && !checksep(*str, c))
			str++;
	}
	words[j] = NULL;
	return (words);
}
