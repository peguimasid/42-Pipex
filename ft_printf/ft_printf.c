/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:18:50 by gmasid            #+#    #+#             */
/*   Updated: 2022/06/17 13:35:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_parse_flag(va_list *args, char match)
{
	int	result;

	result = 0;
	if (match == 'c')
		result += ft_putchar(va_arg(*args, int));
	if (match == 'i' || match == 'd')
		result += ft_print_int(va_arg(*args, int));
	if (match == 'u')
		result += ft_print_uint(va_arg(*args, unsigned int));
	if (match == 's')
		result += ft_print_str(va_arg(*args, char *));
	if (match == 'p')
		result += ft_print_ptr(va_arg(*args, unsigned long long));
	if (match == 'x' || match == 'X')
		result += ft_print_hexa(va_arg(*args, unsigned long long), match);
	if (match == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	args;
	int		i;

	result = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			result += ft_parse_flag(&args, s[++i]);
		else
			result += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (result);
}
