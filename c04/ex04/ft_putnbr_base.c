/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:20:40 by ygeng             #+#    #+#             */
/*   Updated: 2024/09/18 12:22:27 by ygeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_error(char *base, int *error)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		*error = 1;
	while (base[i] && *error == 0)
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				*error = 1;
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
			|| base[i] == '/' || base[i] == '*' || base[i] == '='
			|| base[i] == ',' || base[i] == '.' || base[i] < 33
			|| base[i] > 126)
			*error = 1;
		else
			i++;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;
	int	error;

	l = 0;
	error = 0;
	ft_error(base, &error);
	if (error == 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		while (base[l] != '\0')
			l++;
		if (nbr < l)
			ft_putchar(base[nbr]);
		else
		{
			ft_putnbr_base((nbr / l), base);
			ft_putchar(base[nbr % l]);
		}
	}
}
/*
int	main(void)
{
	int	number = 20;

	printf("Number %d in base %s\n", number, "01");
	ft_putnbr_base(number, "01");
	ft_putchar('\n');
	printf("Number %d in base %s\n", number, "0123456789ABCDEF");
	ft_putnbr_base(number, "0123456789ABCDEF");
	ft_putchar('\n');
	printf("Number %d in base %s\n", number, "0123456789");
	ft_putnbr_base(number, "0123456789");
	ft_putchar('\n');
	printf("Number %d in base %s\n", number, "poneyvif");
	ft_putnbr_base(number, "poneyvif");
	ft_putchar('\n');
	printf("Number %d in base %s\n", number, "012345677");
	ft_putnbr_base(number, "012345677");
	ft_putchar('\n');
	printf("Number %d in base %s\n", number, "abcd+");
	ft_putnbr_base(number, "abcd+");
	ft_putchar('\n');
	number = -12;
	printf("Number %d in base %s\n", number, "01");
	ft_putnbr_base(number, "01");
	ft_putchar('\n');
	number = 12;
	printf("Number %d in base %s\n", number, "01");
	ft_putnbr_base(number, "01");
	ft_putchar('\n');
	ft_putchar('\n');
}*/
