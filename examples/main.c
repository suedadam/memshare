/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:26:41 by asyed             #+#    #+#             */
/*   Updated: 2018/03/27 04:12:12 by asyed            ###   ########.fr       */
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
		sprintf(str, "Hello %d", 42 + i);
		i++;
		sleep(1);
	}
	mem_delete("strtest", str, 4096);
}