/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:53:45 by hfhad             #+#    #+#             */
/*   Updated: 2024/11/05 15:11:48 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	count_words(char const *s1, char c)
{
	int	is_word;
	int	count;
	int	i;

	i = 0;
	is_word = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			is_word = 0;
		else
		{
			if (!is_word)
			{
				is_word = 1;
				count++;
			}
		}
		i++;
	}
	return (count);
}

static char	*create_word(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	fill_words(char const *s, char c, char **result)
{
	int		i;
	int		start;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[k] = create_word(s, start, i);
			if (!result[k++])
				return (free_words(result, k - 1), 0);
		}
		else
			i++;
	}
	result[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (!fill_words(s, c, result))
		return (NULL);
	return (result);
}
