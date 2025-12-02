/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:38:47 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:53 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	memchr_00(void);
int	memchr_01(void);
int	memchr_02(void);
int	memchr_03(void);
int	memchr_04(void);
int	memchr_05(void);

test_suite	memchr_tests = {memchr_00, memchr_01, memchr_02, memchr_03, memchr_04, memchr_05, NULL};

// check null handling
int	memchr_00(void)
{
	ft_memchr(NULL, 0, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	memchr_01(void)
{
	char	str[5] = {0, 0, -1, 1, 1};

	_ft_assert(ft_memchr(str, -1, 5) == memchr(str, -1, 5), RED);
	return (SUCCESS);
}

int	memchr_02(void)
{
	char	str[5] = {0, 0, -1, 1, 1};

	_ft_assert(ft_memchr(str, -1, 3) == memchr(str, -1, 3), RED);
	return (SUCCESS);
}

int	memchr_03(void)
{
	char	str[5] = {-1, -1, 0, -1, -1};

	_ft_assert(ft_memchr(str, 0, 5) == memchr(str, 0, 5), RED);
	return (SUCCESS);
}

int	memchr_04(void)
{
	char	str[5] = {3, 4, 5, 6, 2};

	_ft_assert(ft_memchr(str, 2, 4) == memchr(str, 2, 4), RED);
	return (SUCCESS);
}

int	memchr_05(void)
{
	char	str[2] = {0,-1};

	_ft_assert(ft_memchr(str, -1, 2) == memchr(str, -1, 2), RED);
	return (SUCCESS);
}
