/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:43:14 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:24 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	memmove_00(void);
int	memmove_01(void);
int	memmove_02(void);
int	memmove_03(void);
int	memmove_04(void);
int	memmove_05(void);

test_suite	memmove_tests = {memmove_00, memmove_01, memmove_02, memmove_03, memmove_04, memmove_05, NULL};

//check null handling
int	memmove_00(void)
{
	char	str[1] = {0};

	ft_memmove(NULL, NULL, 1);
	ft_memmove(NULL, str, 1);
	ft_memmove(str, NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	memmove_01(void)
{
	int		result = 1;
	char	str1[5] = {5, 5, 5, 5, 5};
	char	str2[5] = {0, -1, 0, 1, 2};
	char	str3[5] = {5, 5, 5, 5, 5};
	char	str4[5] = {0, -1, 0, 1, 2};

	result = result && (ft_memmove(str1 + 1, str2 + 1, 0) == str1 + 1);
	memmove(str3 + 1, str4 + 1, 0);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str3[i]) && (str2[i] == str4[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memmove_02(void)
{
	int		result = 1;
	char	str1[5] = {5, 5, 5, 5, 5};
	char	str2[5] = {0, -1, 0, 1, 2};
	char	str3[5] = {5, 5, 5, 5, 5};
	char	str4[5] = {0, -1, 0, 1, 2};

	result = result && (ft_memmove(str1 + 1, str2 + 1, 3) == str1 + 1);
	memmove(str3 + 1, str4 + 1, 3);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str3[i]) && (str2[i] == str4[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memmove_03(void)
{
	int		result = 1;
	char	str1[10] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};
	char	str2[10] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};

	result = result && (ft_memmove(str1, str1 + 1, 3) == str1);
	memmove(str2, str2 + 1, 3);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str2[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	memmove_04(void)
{
	int		result = 1;
	char	str1[10] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};
	char	str2[10] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};

	result = result && (ft_memmove(str1 + 1, str1, 3) == str1 + 1);
	memmove(str2 + 1, str2, 3);
	for (int i = 0; i < 5; i++)
		result = result && (str1[i] == str2[i]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

// try memmvoing 5MB
int	memmove_05(void)
{
	size_t	n = 5 * 1024 * 1024;
	char	*str;
	int		result = 1;

	str = malloc(n * sizeof(char));
	if (str) {
		bzero(str, n);
		ft_memmove(str + 1, str, n - 1);
		free(str);
	}

	_ft_assert(result, RED);
	return (SUCCESS);
}
