/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:41:53 by gmasid            #+#    #+#             */
/*   Updated: 2022/06/09 12:00:55 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		num %= 16;
	}
	if (num < 10)
		ft_putchar(num + '0');
	else
		ft_putchar(num - 10 + 'a');
}

int	ft_ptrlen(uintptr_t num)
{
	int	result;

	result = 0;
	while (num != 0)
	{
		result++;
		num /= 16;
	}
	return (result);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	result;

	result = 0;
	result += write(1, "0x", 2);
	if (ptr == 0)
		return (result += ft_putchar('0'));
	ft_putptr(ptr);
	result += ft_ptrlen(ptr);
	return (result);
}
