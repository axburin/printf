/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:16:27 by axburin-          #+#    #+#             */
/*   Updated: 2024/11/08 13:32:54 by axburin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	print_adresse_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putnbr_hex((unsigned long)ptr);
	return (count);
}

// int main (void)
// {
//    char const *ptr = NULL;
// 	// print_adresse_pointer(ptr);
//    	// printf ("%p\n", (void *) ptr);
// 	// printf ("%d\n",print_adresse_pointer(ptr));
// 	printf ("%d\n",(ptr));
//    return 0;
// }