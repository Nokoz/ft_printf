/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:21 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/19 16:05:52 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		while (fmt[i] != '%' && fmt[i] != '\0')
		{
			ft_putchar(fmt[i++]);
			ret += 1;
		}
		if (ft_is_conv(&fmt[i]))
			i += ft_print_conv(&fmt[i], ap, &ret);
	}
	va_end(ap);
	return (ret);
}

int	ft_is_conv(const char *fmt)
{
	int	res;

	res = 0;
	if (*fmt == 'c' || *fmt == 's' || *fmt == 'p' || *fmt == 'd'
		|| *fmt == 'i' || *fmt == 'u' || *fmt == 'x' || *fmt == 'X'
		|| *fmt == '%')
		return (1);
	return (0);
}

int	ft_print_conv(const char *fmt, va_list ap, int *ret)
{
	(void)ap;
	fmt++;
	if (*fmt == '%')
	{
		ft_putchar('%');
		*ret += 1;
		return (2);
	}
	if (*fmt == 'c')
		return (ft_print_char(va_arg(ap, int), ret));
	if (*fmt == 's')
		return (ft_print_str(va_arg(ap, char *), ret));
	if (*fmt == 'p')
		return (ft_print_ptr(va_arg(ap, void *), ret));
	return (0);
}

int	ft_print_char(int c, int *ret)
{
	ft_putchar(c);
	*ret += 1;
	return (2);
}

int	ft_print_str(char *s, int *ret)
{
	int	i;

	i = (int)ft_strlen(s);
	ft_putstr_fd(s, 1);
	*ret += i;
	return (2);
}

int	ft_print_ptr(void *p, int *ret)
{
	ft_putstr_fd(&p, 1);
	*ret += 14;
	return (2);
}
