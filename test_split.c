/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:48:42 by sanglee2          #+#    #+#             */
/*   Updated: 2023/02/09 22:02:02 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	word_count(char *str, char c)
{
	int	str_cnt;
	int	flag;

	str_cnt = 0;
	flag = 1;
	while (*str)
	{
		if (flag == 1 && *str != '\0' && *str != c)
		{
			str_cnt++;
			flag = 0;
		}
		else if (*str == '\0' || *str == c)
			flag = 1;
		str++;
	}
	return (str_cnt);
}

static char	*str_word_print(char *s, char c)
{
	char	*word;
	int		lc;
	int		i;

	lc = 0;
	i = 0;
	while (s[lc] != '\0' && s[lc] != c)
		lc++;
	word = (char *)malloc(sizeof(char) * (lc + 1));
	if (!word)
		return (0);
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	len = word_count((char *)s, c); //단어 세주기.
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < len)
	{
		while (*s != '\0' && *s == c)
			s++;
		result[i] = str_word_print((char *)s, c);
		if (result[i] == 0)
		{
			while (--i >= 0)
				free(result[i]);
			free(result);
			return (0);
		}
		s = s + ft_strlen(result[i++]);
	}
	result[i] = NULL;
	return (result);
}