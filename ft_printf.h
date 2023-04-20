/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:51:33 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/20 14:29:09 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_is_conv(const char *fmt);
int		ft_print_conv(const char *fmt, va_list ap, int *ret);
void	ft_print_char(int c, int *ret);
void	ft_print_str(char *s, int *ret);
void	ft_print_ptr(unsigned long n, int *ret);
void	ft_print_int(int n, int *ret);
