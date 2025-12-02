/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 23:00:30 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/24 23:08:41 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

extern int	fail_malloc;

extern void	*__libc_malloc(size_t size);

void	*malloc(size_t size)
{
	if (fail_malloc)
		return (NULL);
	return (__libc_malloc(size));
}
