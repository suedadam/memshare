/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 03:50:28 by asyed             #+#    #+#             */
/*   Updated: 2018/03/27 04:10:02 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memshare.h"

void	mem_delete(char *name, void *mem, size_t size)
{
	munmap(mem, alignment(size));
	shm_unlink(name);
}
