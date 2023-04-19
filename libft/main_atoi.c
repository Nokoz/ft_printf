/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <gvardaki@student.42.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:57:50 by gvardaki          #+#    #+#             */
/*   Updated: 2023/04/12 11:41:06 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_atoi.c"

int	main(int ac, char **av)
{
	(void)ac;
	printf("ft_return = %d\n", ft_atoi(av[1]));
	printf("return = %d\n", atoi(av[1]));
	return (0);
}
