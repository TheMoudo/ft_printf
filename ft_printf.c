/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <mzbair@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:21:57 by mzbair            #+#    #+#             */
/*   Updated: 2026/11/12 21:17:21 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bt_count;
	int		i;

	bt_count = 0;
	i = 0;
	va_start(ap, format);
	while(format[i])
	{
		if (format[i] == '%')
			bt_count += print_forma(ap, format[++i]);
		else
			bt_count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (bt_count);
}

int	print_forma(va_list ap, char c)
{
	int bt_count;

	if (c == 'c')
		bt_count = put_char(ap);
	else if (c == 's')
		bt_count = put_str(ap);
	// else if (c == 'p')
	// 	bt_count = put_point(ap);
	// else if (c == 'd' || c == 'i')
	// 	bt_count = put_nbr(ap);
	// else if (c == 'u')
	// 	bt_count = put_unsigned_nbr(ap);
	// else if (c == 'x')
	// 	bt_count = put_lowe_hex(ap);
	// else if (c == 'X')
	// 	bt_count = put_upper_hex(ap);
	else if (c == '%')
		bt_count = write(1, "%", 1);
	return (bt_count);
}
