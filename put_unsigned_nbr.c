/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <mzbair@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 20:23:41 by mzbair            #+#    #+#             */
/*   Updated: 2026/11/15 22:13:26 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calcule_len(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb > 9)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

int	put_unsigned_nbr(va_list ap)
{
	unsigned int	nb;
	char			str_nb[10];
	int				len;
	int				i;

	nb = va_arg(ap, unsigned int);
	len = calcule_len(nb);
	i = len - 1;
	while (i >= 0)
	{
		str_nb[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (write(1, str_nb, len));
}
