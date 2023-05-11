/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:45 by sanglee2          #+#    #+#             */
/*   Updated: 2023/02/18 17:42:58 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 공백문자인지 아닌지 체크하는 함수
// 공백을 체크해주는 부분이 atoi와 겹치는데 어떻게 생각하는지..
int	ft_iswhitespace(int c)
{
	if (c == 32 || c >= 9 && c <= 13)
		return (1);
	return (0);
}


// av[1][j] 문자하나를 정수로 변환해주는 함수
int	ft_atoi(const char *nptr)
{
	size_t			i;
	size_t			j;
	int				sign;
	long long int	num_integer;

	i = 0;
	sign = 1;
	num_integer = 0;
	while (ft_iswhitespace(*nptr))
		nptr++;
	if (nptr == '-' )
	{
		sign = -1;
		nptr++;
	}
	else if (nptr == '+')
		nptr++;
	while (nptr == '0')
		nptr++;
	j = 0;
	while (nptr != '\0' && j < 11 && !(ft_iswhitespace(nptr[i]))) // return 값으로 들어감
	{
		if(ft_isdigit(nptr[i]))
		{
			num_integer = num_integer * 10 + nptr[i] - '0';
			i++;
			j++;
		}
		else
			ft_error("Error\n");
	}
	while(nptr != '\0')
	{
		if(ft_iswhitespace(nptr[i]))
			i++;
		else
			ft_error()
	}
	num_integer = num_integer * sign;
	if(num_integer < INT_MIN || num_integer > INT_MAX)
		ft_error("Error\n");
	return ((int)num_integer);
}

long int ft_atoi(const char *str)
{   
    long int nb;
    int      sign;
    int      i;

    nb = 0;
    sign = 1;
    i = 0;

    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        sign = sign * -1;
        i++;
    }
    while (is_digit(str[i]))
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
	nb = nb * sign;
	if(nb < INT_MIN || nb > INT_MAX)
		ft_error("Error\n");
    return (nb * sign);
}
