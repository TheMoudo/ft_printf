/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <mzbair@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 11:14:00 by mzbair            #+#    #+#             */
/*   Updated: 2026/11/16 16:07:54 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calcule_len(unsigned long nb)
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

int	put_point(va_list *ap)
{
	unsigned long	ptr;
	char			point_buffer[18];
	char			*hex_base;
	int				len;
	int				i;

	ptr = (unsigned long) va_arg(*ap, void *);
	hex_base = "0123456789abcdef";
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	point_buffer[0] = '0';
	point_buffer[1] = 'x';
	len = calcule_len(ptr) + 2;
	i = len -1;
	while (i >= 2)
	{
		point_buffer[i--] = hex_base[ptr % 16];
		ptr = ptr / 16;
	}
	return (write(1, point_buffer, len));
}
