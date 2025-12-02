/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:41:56 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:18 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	memcpy_00(void);
int	memcpy_01(void);
int	memcpy_02(void);

test_suite	memcpy_tests = {memcpy_00, memcpy_01, memcpy_02, NULL};

// check null handling
int	memcpy_00(void)
{
	char	str[1] = {0};

	ft_memcpy(NULL, NULL, 1);
	ft_memcpy(NULL, str, 1);
	ft_memcpy(str, NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	memcpy_01(void)
{
	int		result = 1;
	char	str1[5] = {5, 5, 5, 5, 5};
	char	str2[5] = {0, -1, 0, 1, 2};
	char	str3[5] = {5, 5, 5, 5, 5};
	char	str4[5] = {0, -1, 0, 1, 2};

	result = result && (ft_memcpy(str1 + 1, str2 + 1, 0) == str1 + 1);
	memcpy(str3 + 1, str4 + 1, 0);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str3[i]) && (str2[i] == str4[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memcpy_02(void)
{
	int		result = 1;
	char	str1[5] = {5, 5, 5, 5, 5};
	char	str2[5] = {0, -1, 0, 1, 2};
	char	str3[5] = {5, 5, 5, 5, 5};
	char	str4[5] = {0, -1, 0, 1, 2};

	result = result && (ft_memcpy(str1 + 1, str2 + 1, 3) == str1 + 1);
	memcpy(str3 + 1, str4 + 1, 3);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str3[i]) && (str2[i] == str4[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}
