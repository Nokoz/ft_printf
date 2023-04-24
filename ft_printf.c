/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:21 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/24 09:27:34 by gvardaki         ###   ########.fr       */
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
			i += ft_print_conv(&fmt[i], &ap, &ret);
	}
	va_end(ap);
	return (ret);
}

int	ft_is_conv(const char *fmt)
{
	if (*fmt == 'c' || *fmt == 's' || *fmt == 'p' || *fmt == 'd'
		|| *fmt == 'i' || *fmt == 'u' || *fmt == 'x' || *fmt == 'X'
		|| *fmt == '%')
		return (1);
	return (0);
}

int	ft_print_conv(const char *fmt, va_list *ap, int *ret)
{
	fmt++;
	if (*fmt == '%')
	{
		ft_putchar('%');
		*ret += 1;
	}
	if (*fmt == 'c')
		(ft_print_char(va_arg(*ap, int), ret));
	if (*fmt == 's')
		(ft_print_str(va_arg(*ap, char *), ret));
	if (*fmt == 'p')
	{
		ft_putstr_fd("0x", 1);
		*ret += 2;
		ft_print_ptr(va_arg(*ap, unsigned long), ret);
	}
	if (*fmt == 'd' || *fmt == 'i')
		ft_print_int(va_arg(*ap, int), ret);
	return (2);
}

void	ft_print_char(int c, int *ret)
{
	ft_putchar(c);
	*ret += 1;
}

void	ft_print_str(char *s, int *ret)
{
	int	i;

	i = (int)ft_strlen(s);
	ft_putstr_fd(s, 1);
	*ret += i;
}

void	ft_print_ptr(unsigned long n, int *ret)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n > 15)
		ft_print_ptr(n / 16, ret);
	ft_putchar(hexa[n % 16]);
	*ret += 1;
}

void	ft_print_int(int n, int *ret)
{
	(void)n;
	(void)ret;
}
