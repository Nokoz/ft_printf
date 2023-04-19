/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:00:02 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/19 15:57:10 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.c"

int	main(void)
{
	int		ret;
	char	c;
	char	str[20] = "string";
	
	ret = 0;
	c = 'a';
	ret = ft_printf("Bonjo%%ur char = %c\n str = %s\n p = %p\n", c, str, &c);
	printf("ft_ret = %d\n", ret);
	ret = printf("Bonjo%%ur char = %c\n str = %s\n p = %p\n", c, str, &c);
	printf("ret = %d\n", ret);
	return (0);
}
