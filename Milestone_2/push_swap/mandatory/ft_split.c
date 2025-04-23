/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfhad <hfhad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:01:05 by hfhad             #+#    #+#             */
/*   Updated: 2025/01/07 16:08:52 by hfhad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	strcount;
	int	in_string;
	int	i;

	i = 0;
	strcount = 0;
	in_string = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
			in_string = 0;
		else
		{
			if (!in_string)
			{
				in_string = 1;
				strcount++;
			}
		}
		i++;
	}
	return (strcount);
}

char	*creat_fill_string(char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *) malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	word[i] = '\0';
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**allocate_words(char *str, char *charset, char **rslt)
{
	char	**result;
	int		i;
	int		k;
	int		start;

	i = 0;
	start = 0;
	k = 0;
	result = rslt;
	while (str[i])
	{
		if (is_sep(str[i], charset))
		{
			if (i > start)
				result[k++] = creat_fill_string(str, start, i);
			start = i + 1;
		}
		i++;
	}
	if (i > start)
		result[k++] = creat_fill_string(str, start, i);
	result[k] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**result;

	i = 0;
	result = (char **) malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!result)
		return (NULL);
	result = allocate_words(str, charset, result);
	return (result);
}
