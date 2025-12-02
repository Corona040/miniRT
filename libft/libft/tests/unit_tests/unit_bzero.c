/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:40:49 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:06 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	bzero_00(void);
int	bzero_01(void);
int	bzero_02(void);

test_suite	bzero_tests = {bzero_00, bzero_01, bzero_02, NULL};

// check null handling
int	bzero_00(void)
{
	ft_bzero(NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	bzero_01(void)
{
	int		result = 1;
	char	str1[5] = {0, -1, 0, 1, 0};
	char	str2[5] = {0, -1, 0, 1, 0};

	ft_bzero(str1 + 1, 0);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str2[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	bzero_02(void)
{
	int		result = 1;
	char	str1[5] = {0, -1, 0, 1, 0};
	char	str2[5] = {0, -1, 0, 1, 0};

	ft_bzero(str1 + 1, 1 - 1);
	bzero(str2 + 1, 1 - 1);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str2[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}
