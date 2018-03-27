/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memshare.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 03:37:36 by asyed             #+#    #+#             */
/*   Updated: 2018/03/27 03:53:59 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMSHARE_H
# define FT_MEMSHARE_H
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <sys/stat.h>
# include <fcntl.h>

int		alignment(size_t size);
void	*mem_create(char *name, size_t size);
void	mem_delete(char *name, void *mem, size_t size);

#endif