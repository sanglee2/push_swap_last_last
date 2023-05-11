/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:08:44 by sanglee2          #+#    #+#             */
/*   Updated: 2023/02/09 22:17:57 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>

int j 선언.


ft_iswhitespace(str[j])

int	check_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	str_cnt;
	int	flag;

	str_cnt = 0;
	flag = 1;
	while (*str)
	{
		if (flag == 1 && !check_charset(*str, charset))
		{
			str_cnt++;
			flag = 0;
		}
		else if (check_charset(*str, charset))
			flag = 1;
		str++;
	}
	return (str_cnt);
}

char	*str_word_print(char *str, char *charset)
{
	char	*word;
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	while (str[wc] && !check_charset(str[wc], charset))
		wc++;
	word = (char *)malloc(sizeof(char) * (wc + 1));
	if (!word)
		return (0);
	while (str[i] && !check_charset(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;
	int		len;

	len = word_count(str);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (*str)
	{
		while (check_charset(*str, charset) && *str)
			str++;
		if (!check_charset(*str, charset) && *str)
		{
			result[i] = str_word_print(str, charset);
			i++;
			if (result[i] == 0)
			{
			while (--i >= 0)
				free(result[i]);
			free(result);
			return (0);
			}
		}
		while (!check_charset(*str, charset) && *str)
			str++;
	}
	result[i] = NULL;
	return (result);
}