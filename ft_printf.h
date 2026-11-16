/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzbair <mzbair@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 13:42:11 by mzbair            #+#    #+#             */
/*   Updated: 2026/11/16 11:49:21 by mzbair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_format(va_list ap, char c);
int	put_char(va_list ap);
int	put_str(va_list ap);
int	put_point(va_list ap);
int	put_nbr(va_list ap);
int	put_unsigned_nbr(va_list ap);
int	put_hex(va_list ap, int is_upper_case);

#endif
