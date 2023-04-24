/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:21 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/24 16:51:50 by gvardaki         ###   ########.fr       */
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
		ft_print_hexa(va_arg(*ap, unsigned long), ret, 0);
	}
	if (*fmt == 'd' || *fmt == 'i')
		ft_print_int(va_arg(*ap, int), ret);
	if (*fmt == 'u')
		ft_print_nbr(va_arg(*ap, unsigned int), ret);
	if (*fmt == 'x')
		ft_print_hexa(va_arg(*ap, unsigned long), ret , 0);
	if (*fmt == 'X')
		ft_print_hexa(va_arg(*ap, unsigned long), ret , 1);
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

void	ft_print_hexa(unsigned long n, int *ret, int maj)
{
	char	*hexa;

	if (maj == 0)
		hexa = "0123456789abcdef";
	if (maj == 1)
		hexa = "0123456789ABCDEF";
	if (n > 15)
		ft_print_hexa(n / 16, ret, maj);
	if (maj == 1)
		ft_putchar(ft_toupper(hexa[n % 16]));
	*ret += 1;
}

void	ft_print_int(int n, int *ret)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		*ret += 1;
	}
	ft_print_nbr(nbr, ret);
}

static void	ft_print_nbr(unsigned int n, int *ret)
{
	if (n > 9)
		ft_print_nbr(n / 10, ret);
	ft_putchar((n % 10) + 48);
	*ret += 1;
}
