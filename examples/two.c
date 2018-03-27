/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:26:41 by asyed             #+#    #+#             */
/*   Updated: 2018/03/27 03:57:27 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memshare.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = mem_create("strtest", 4096)))
	{
		printf("%s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	while(1)
	{
		write(1, &str, 1);
		printf("str = \"%s\"\n", str);
		sleep(1);
	}
}