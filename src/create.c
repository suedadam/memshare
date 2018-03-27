/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 03:27:44 by asyed             #+#    #+#             */
/*   Updated: 2018/03/27 03:52:35 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memshare.h"

int		alignment(size_t size)
{
	static size_t pagesize = 0;

	if (!pagesize)
		pagesize = getpagesize();
	return (size + (size % pagesize));
}

void	*mem_create(char *name, size_t size)
{
	int			fd;
	struct stat	stbuf;

	if ((fd = shm_open(name, O_RDWR | O_CREAT, S_IRWXU)) == -1)
		return (NULL);
	if (size)
	{
		size = alignment(size);
		ftruncate(fd, size);
	}
	else
	{
		if (fstat(fd, &stbuf) == -1)
			return (NULL);
		size = alignment(stbuf.st_size);
	}
	return (mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0));
}