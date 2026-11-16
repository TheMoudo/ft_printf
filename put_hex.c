/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <mzbair@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 09:58:49 by mzbair            #+#    #+#             */
/*   Updated: 2026/11/16 16:00:21 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calcule_len(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb > 15)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

int	put_hex(va_list ap, int is_upper_case)
{
	unsigned int	nb;
	char			*hex_base;
	char			str_nb[8];
	int				len;
	int				i;

	nb = va_arg(ap, unsigned int);
	if (is_upper_case)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	len = calcule_len(nb);
	i = len -1;
	while (i >= 0)
	{
		str_nb[i--] = hex_base[nb % 16];
		nb = nb / 16;
	}
	return (write(1, str_nb, len));
}
