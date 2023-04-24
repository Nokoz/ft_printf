/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:00:02 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/24 15:31:51 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.c"

int	main(void)
{
	int		ret;
	int		ft_ret;
	char	c;
	char	*str = "string";
	int		nbr = 2147483647;
	
	ret = 0;
	ft_ret = 0;
	c = 'a';
	ft_ret = ft_printf("\nBonjo%%ur char = %c\n str = %s\n p = %p\n decimal = %d\n int = %i\n", c, str, &c, nbr, nbr);
	printf("ft_ret = %d\n", ft_ret);
	ret = printf("\nBonjo%%ur char = %c\n str = %s\n p = %p\n decimal = %d\n int = %i\n", c, str, &c, nbr, nbr);
	printf("ret = %d\n", ret);
	return (0);
}
