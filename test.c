/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:00:02 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/24 09:06:23 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.c"

int	main(void)
{
	int		ret;
	char	str[6] = "string";
	
	ret = 0;
	ret = ft_printf("Bonjo%%ur\n str = %s\n decimal = %%\n", str);
	printf("ft_ret = %d\n", ret);
	ret = printf("Bonjo%%ur\n str = %s\n decimal = %%\n", str);
	printf("ret = %d\n", ret);
	return (0);
}
