/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:33:22 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:51 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strrchr_00(void);
int	strrchr_01(void);
int	strrchr_02(void);
int	strrchr_03(void);
int	strrchr_04(void);

test_suite	strrchr_tests = {strrchr_00, strrchr_01, strrchr_02, strrchr_03, strrchr_04, NULL};

// check null handling
int	strrchr_00(void)
{
	ft_strrchr(NULL, 0);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strrchr_01(void)
{
	char	str[5] = {1, 1, -1, 1, 1};

	_ft_assert(ft_strrchr(str, -1) == strrchr(str, -1), RED);
	return (SUCCESS);
}

int	strrchr_02(void)
{
	char	str[5] = {-1, -1, 0, -1, -1};

	_ft_assert(ft_strrchr(str, 0) == strrchr(str, 0), RED);
	return (SUCCESS);
}

int	strrchr_03(void)
{
	char	str[5] = {3, 4, 5, 6, 0};

	_ft_assert(ft_strrchr(str, 2) == strrchr(str, 2), RED);
	return (SUCCESS);
}

int	strrchr_04(void)
{
	char	str[2] = {0,-1};

	_ft_assert(ft_strrchr(str, -1) == strrchr(str, -1), RED);
	return (SUCCESS);
}
