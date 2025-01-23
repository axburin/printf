/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:09:12 by axburin-          #+#    #+#             */
/*   Updated: 2024/11/08 13:38:23 by axburin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calcul_size_hex(long nb)
{
	unsigned int	size;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	if (nb == 0)
		size++;
	if (nb > 0)
	{
		while (nb)
		{
			nb = nb / 16;
			size++;
		}
	}
	return (size);
}

int	calcul_size(long int nb)
{
	int	size;

	size = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

//------------------------------------------------------------------
int	ft_putnbr_unsigned(unsigned int n)
{
	calcul_size(n);
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (calcul_size(n));
}
//------------------------------------------------------------------

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		return (1 + ft_putnbr(n));
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return (1);
	}
	return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
}
