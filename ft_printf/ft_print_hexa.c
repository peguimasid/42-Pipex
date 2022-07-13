/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:41:53 by gmasid            #+#    #+#             */
/*   Updated: 2022/06/09 13:23:46 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, int is_upper)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, is_upper);
		n %= 16;
	}
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		if (is_upper)
			ft_putchar(n - 10 + 'A');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_hexalen(unsigned int n)
{
	int	result;

	result = 0;
	while (n != 0)
	{
		result++;
		n /= 16;
	}
	return (result);
}

int	ft_print_hexa(unsigned int n, char match)
{
	int	result;

	result = 0;
	if (n == 0)
		return (result += ft_putchar('0'));
	ft_puthexa(n, match == 'X');
	result += ft_hexalen(n);
	return (result);
}
