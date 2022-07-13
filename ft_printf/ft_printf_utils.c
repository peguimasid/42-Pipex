/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:07:40 by gmasid            #+#    #+#             */
/*   Updated: 2022/06/08 14:37:58 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i] != '\0')
		ft_putchar_fd(str[i++], 1);
	return (i);
}

int	ft_print_int(int nbr)
{
	int		nbr_len;
	char	*convert;

	nbr_len = 0;
	convert = ft_itoa(nbr);
	nbr_len = ft_print_str(convert);
	free(convert);
	return (nbr_len);
}

int	ft_print_uint(unsigned int n)
{
	int		nbr_len;
	char	*convert;

	if (n == 0)
		return (ft_putchar('0'));
	nbr_len = 0;
	convert = ft_utoa(n);
	nbr_len += ft_print_str(convert);
	free(convert);
	return (nbr_len);
}
