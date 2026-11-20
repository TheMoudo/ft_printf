/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <mzbair@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 11:28:47 by mzbair            #+#    #+#             */
/*   Updated: 2026/11/15 17:15:38 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_positf_nb(long nb)
{
	long	nb_cpy;
	int		len;
	int		i;
	char	str_nb[10];

	len = 1;
	nb_cpy = nb;
	while (nb_cpy > 9)
	{
		len++;
		nb_cpy = nb_cpy / 10;
	}
	i = len - 1;
	while (i >= 0)
	{
		str_nb[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (write(1, str_nb, len));
}

int	put_nbr(va_list *ap)
{
	long	nb;
	int		signe;
	int		is_print;

	signe = 0;
	nb = va_arg(*ap, int);
	if (nb < 0)
	{
		nb = -nb;
		if (write(1, "-", 1) == -1)
			return (-1);
		signe = 1;
	}
	is_print = write_positf_nb(nb);
	if (is_print == -1)
		return (-1);
	return (signe + is_print);
}
