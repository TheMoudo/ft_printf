/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <mzbair@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:21:57 by mzbair            #+#    #+#             */
/*   Updated: 2026/11/16 16:09:07 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bt_count;
	int		i;
	int		is_print;

	if (!format)
		return (-1);
	bt_count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			is_print = print_format(ap, format[++i]);
		else
			is_print = write(1, &format[i], 1);
		if (is_print == -1)
		{
			va_end(ap);
			return (-1);
		}
		bt_count += is_print + 0 * i++;
	}
	va_end(ap);
	return (bt_count);
}

int	print_format(va_list ap, char c)
{
	int	bt_count;

	bt_count = 0;
	if (c == 'c')
		bt_count = put_char(ap);
	else if (c == 's')
		bt_count = put_str(ap);
	else if (c == 'p')
		bt_count = put_point(ap);
	else if (c == 'd' || c == 'i')
		bt_count = put_nbr(ap);
	else if (c == 'u')
		bt_count = put_unsigned_nbr(ap);
	else if (c == 'x')
		bt_count = put_hex(ap, 0);
	else if (c == 'X')
		bt_count = put_hex(ap, 1);
	else if (c == '%')
		bt_count = write(1, "%", 1);
	return (bt_count);
}
