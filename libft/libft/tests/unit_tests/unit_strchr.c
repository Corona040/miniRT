/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:32:00 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:59 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strchr_00(void);
int	strchr_01(void);
int	strchr_02(void);
int	strchr_03(void);
int	strchr_04(void);

test_suite	strchr_tests = {strchr_00, strchr_01, strchr_02, strchr_03, strchr_04, NULL};

// check null handling
int	strchr_00(void)
{
	ft_strchr(NULL, 0);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strchr_01(void)
{
	char	str[5] = {1, 1, -1, 1, 1};

	_ft_assert(ft_strchr(str, -1) == strchr(str, -1), RED);
	return (SUCCESS);
}

int	strchr_02(void)
{
	char	str[5] = {-1, -1, 0, -1, -1};

	_ft_assert(ft_strchr(str, 0) == strchr(str, 0), RED);
	return (SUCCESS);
}

int	strchr_03(void)
{
	char	str[5] = {3, 4, 5, 6, 0};

	_ft_assert(ft_strchr(str, 2) == strchr(str, 2), RED);
	return (SUCCESS);
}

int	strchr_04(void)
{
	char	str[2] = {0,-1};

	_ft_assert(ft_strchr(str, -1) == strchr(str, -1), RED);
	return (SUCCESS);
}
