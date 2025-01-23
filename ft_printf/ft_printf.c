/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:17:47 by axburin-          #+#    #+#             */
/*   Updated: 2024/11/08 13:45:40 by axburin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	convert(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count += print_adresse_pointer(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	if (c == 'x' )
		count += ft_putnbr_hex(va_arg(args, unsigned int));
	if (c == 'X')
		count += ft_putnbr_hex_maj(va_arg(args, unsigned int));
	return (count);
}

static	int	pourcent(va_list args, char prct)
{
	if (prct == '%')
		return (ft_putchar('%'));
	else
		return (convert(args, prct));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
			{
				count += pourcent(args, format[i]);
				i++;
			}
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	return (va_end(args), count);
}
// int main(void)
// {
// 	char	*format = "hello my name is %s and i'm %d years old \n";
// 	int age = 23;
// 	char *name = NULL;

// 	ft_printf(format, name, age);
// 	//printf("%d", ft_printf(format, name, age));

// 	printf(format, name, age);
// }
// int main() {	
// 	int nb = -2147483648;
//     printf("%d\n", printf(" %%%% "));
// 	ft_printf("%d\n", ft_printf(" %%%% "));
//     return 0;
// }