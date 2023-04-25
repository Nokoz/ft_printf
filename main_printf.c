/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:00:02 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/25 13:55:47 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		ret;
	int		ft_ret;
	char	c;
	char	*str = "string";
	int		nbr = 2147483647;
	unsigned int		unb = 4294967295;
	int		hex = 123;
	int		hex1 = 456789;
	
	ret = 0;
	ft_ret = 0;
	c = 'a';
	ft_ret = ft_printf("\nBonjo%%ur char = %c\n str = %s\n p = %p\n decimal = %d\n int = %i\n unsigned int = %u\n hexa = %x\n HEXA = %X\n", c, str, &c, nbr, nbr, unb, hex, hex1);
	printf("ft_ret = %d\n", ft_ret);
	ret = printf("\nBonjo%%ur char = %c\n str = %s\n p = %p\n decimal = %d\n int = %i\n unsigned int = %u\n hexa = %x\n HEXA = %X\n", c, str, &c, nbr, nbr, unb, hex, hex1);
	printf("ret = %d\n", ret);
	return (0);
}
