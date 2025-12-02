/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:37:49 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:28 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	memset_00(void);
int	memset_01(void);
int	memset_02(void);

test_suite	memset_tests = {memset_00, memset_01, memset_02, NULL};

// check null handling
int	memset_00(void)
{
	ft_memset(NULL, 1, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	memset_01(void)
{
	int		result = 1;
	char	str1[5] = {0, -1, 0, -1, -1};
	char	str2[5] = {0, -1, 0, -1, -1};

	result = result && (ft_memset(str1 + 1, 1, 3) == str1 + 1);
	memset(str2 + 1, 1, 3);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str2[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memset_02(void)
{
	int		result = 1;
	char	str1[5] = {0, -1, 0, -1, -1};
	char	str2[5] = {0, -1, 0, -1, -1};

	result = result && (ft_memset(str1, 1, 0) == str1);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str2[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}
