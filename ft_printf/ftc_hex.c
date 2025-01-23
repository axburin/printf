/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftc_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:25:41 by axburin-          #+#    #+#             */
/*   Updated: 2024/11/08 13:53:29 by axburin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_maj(unsigned long nbr)
{
	char	*hex_digits;
	char	hex_rep[16];
	int		i;
	int		count;

	hex_digits = "0123456789ABCDEF";
	i = 0;
	count = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	while (nbr > 0)
	{
		hex_rep[i++] = hex_digits[nbr % 16];
		nbr /= 16;
	}
	while (--i >= 0)
		count += write(1, &hex_rep[i], 1);
	return (count);
}

int	ft_putnbr_hex(unsigned long nbr)
{
	char	*hex_digits;
	char	hex_rep[16];
	int		i;
	int		count;

	hex_digits = "0123456789abcdef";
	i = 0;
	count = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	while (nbr > 0)
	{
		hex_rep[i++] = hex_digits[nbr % 16];
		nbr /= 16;
	}
	while (--i >= 0)
		count += write(1, &hex_rep[i], 1);
	return (count);
}
