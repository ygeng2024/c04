/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 06:33:32 by ygeng             #+#    #+#             */
/*   Updated: 2024/09/18 06:33:37 by ygeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}
/*
int	main(void)
{
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-12345);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(5);
	return (0);
}*/
