/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:36:31 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:59 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	memcmp_00(void);
int	memcmp_01(void);
int	memcmp_02(void);
int	memcmp_03(void);
int	memcmp_04(void);

test_suite	memcmp_tests = {memcmp_00, memcmp_01, memcmp_02, memcmp_03, memcmp_04, NULL};

// check null handling
int	memcmp_00(void)
{
	char	str[1] = {0};

	ft_memcmp(NULL, NULL, 1);
	ft_memcmp(NULL, NULL, 1);
	ft_memcmp(NULL, str, 1);
	ft_memcmp(str, NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	memcmp_01(void)
{
	int		result = 1;
	char	str1[1] = {0};
	char	str2[1] = {-1};

	result = result && (ft_memcmp(str1, str1, 0) == memcmp(str1, str1, 0));
	result = result && (ft_memcmp(str1, str2, 0) == memcmp(str1, str2, 0));

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memcmp_02(void)
{
	int		result = 1;
	char	str1[2] = {0, 0};
	char	str2[2] = {0, 0};

	result = result && (ft_memcmp(str1, str1, 2) == memcmp(str1, str1, 2));
	result = result && (ft_memcmp(str1, str2, 2) == memcmp(str1, str2, 2));

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memcmp_03(void)
{
	int		result = 1;
	char	str1[4] = {-1, -2, 0, -3};
	char	str2[4] = {-1, -2, 0, -4};

	result = result && (ft_memcmp(str1, str1, 3) == memcmp(str1, str1, 3));
	result = result && (ft_memcmp(str1, str2, 4) == memcmp(str1, str2, 4));

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memcmp_04(void)
{
	int		result = 1;
	char	str1[4] = {-1, -2, -3, 0};
	char	str2[4] = {-1, -2, 0};

	result = result && (ft_memcmp(str1, str1, 2) == memcmp(str1, str1, 2));
	result = result && (ft_memcmp(str1, str2, 3) == memcmp(str1, str2, 3));

	_ft_assert(result, RED);
	return (SUCCESS);
}
