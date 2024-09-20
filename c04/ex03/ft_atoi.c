/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:33:35 by ygeng             #+#    #+#             */
/*   Updated: 2024/09/18 12:08:58 by ygeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	rep;

	i = 0;
	s = 1;
	rep = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rep = rep * 10 + (str[i] - '0');
		i++;
	}
	return (rep * s);
}
/*
int	main(void)
{
	char	*test1 = "----654812";
	char	*test2 = "   +123abc";
	char	*test3 = "42";
	char	*test4 = "   \t\n\r\v\f-42";
	printf("Result of ft_atoi(test1): %d\n", ft_atoi(test1));
	printf("Result of ft_atoi(test2): %d\n", ft_atoi(test2));
	printf("Result of ft_atoi(test3): %d\n", ft_atoi(test3));
	printf("Result of ft_atoi(test4): %d\n", ft_atoi(test4));
	return (0);
}*/
