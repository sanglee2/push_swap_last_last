/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:04:01 by sanglee2          #+#    #+#             */
/*   Updated: 2023/02/12 15:07:24 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void ft_error(char *str)
// {
// 	size_t i;
// 	i = 0;

// 	while (str[i] != '\0')
// 	{
// 		ft_putchar(str[i]);
// 		i++;
// 	}
// }

void ft_error(int case)
{
	if (case)
		write(2, "Error\n", 6); // stderror로 출력하기. 표준출력으로.
	exit(1);
}