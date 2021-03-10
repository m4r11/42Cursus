/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/09 18:09:35 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static fptr get_converter[] =
	{
		&conv_itoa,
		&conv_itoa,
		&conv_xtoa,
		&conv_Xtoa,
		&conv_uitoa,
		&conv_ftoa,
		&conv_fetoa,
		&conv_fetoa,
		&print_str,
		&print_str,
		&print_c,
		&conv_fetoa,
		//&conv_otoa,
		//&print_ptr,
		//&print_n,

};

int ft_printf(const char *format, ...)
{
	va_list args;
	va_list args2;
	t_struct v;
	type_f t_f;
	t_type type;

	va_start(args, format);
	va_copy(args2, args);

	v.i = 0;
	v.f = ft_strdup(format);
	t_f = d;
	v.c = 0;
	while (v.f[v.i])
	{
		if (v.f[v.i] != '%')
		{
			ft_putc(v.f[v.i]);
		}
		else
		{
			v.i++;
			v.j = 0;
			while (CONV_S[v.j])
			{
				if (CONV_S[v.j] == v.f[v.i])
				{
					get_converter[v.j](type, args2);
				}
				v.j++;
			}
		}
		v.i++;
	}
	va_end(args);
	free(v.f);
/* 	if (v.c == 0)
		return (0);
	else  */
		return (counter(0));
}