/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:26:56 by zouddach          #+#    #+#             */
/*   Updated: 2024/05/12 17:59:40 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_checksep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	ft_countwords(char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_checksep(str[i], sep))
			i++;
		if (str[i] && !ft_checksep(str[i], sep))
		{
			i++;
			words++;
		}
		while (str[i] && !ft_checksep(str[i], sep))
			i++;
	}
	return (words);
}

static int	ft_sstrlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !ft_checksep(str[i], c))
		i++;
	return (i);
}

static char	*ft_mallocwords(char *str, char **words, char c, int t)
{
	int		i;
	int		j;
	char	*word;

	j = 0;
	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_sstrlen(str, c) + 1));
	if (!word)
	{
		while (i < t)
			free(words[i++]);
		return (NULL);
	}
	while (str[i] && !ft_checksep(str[i], c))
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
		while (*str && ft_checksep(*str, c))
			str++;
		if (*str && !ft_checksep(*str, c))
		{
			words[j] = ft_mallocwords(str, words, c, j);
			if (!words[j])
				return (free(words), NULL);
			j++;
		}
		while (*str && !ft_checksep(*str, c))
			str++;
	}
	words[j] = NULL;
	return (words);
}
