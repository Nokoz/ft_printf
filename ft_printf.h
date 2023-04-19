/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:51:33 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/19 15:44:18 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_is_conv(const char *fmt);
int		ft_print_conv(const char *fmt, va_list ap, int *ret);
int		ft_print_char(int c, int *ret);
int		ft_print_str(char *s, int *ret);
int		ft_print_ptr(void *p, int *ret);
