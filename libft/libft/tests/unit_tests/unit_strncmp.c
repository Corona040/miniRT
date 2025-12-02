/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:35:19 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:43 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strncmp_00(void);
int	strncmp_01(void);
int	strncmp_02(void);
int	strncmp_03(void);
int	strncmp_04(void);

test_suite	strncmp_tests = {strncmp_00, strncmp_01, strncmp_02, strncmp_03, strncmp_04, NULL};

// check null handling
int	strncmp_00(void)
{
	char	str[1] = {0};

	ft_strncmp(NULL, NULL, 1);
	ft_strncmp(NULL, NULL, 1);
	ft_strncmp(NULL, str, 1);
	ft_strncmp(str, NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strncmp_01(void)
{
	int		result = 1;
	char	str1[1] = {0};
	char	str2[1] = {-1};

	result = result && (ft_strncmp(str1, str1, 0) == strncmp(str1, str1, 0));
	result = result && (ft_strncmp(str1, str2, 0) == strncmp(str1, str2, 0));
	
	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strncmp_02(void)
{
	char	str[1] = {0};

	_ft_assert(ft_strncmp(str, str, -1) == strncmp(str, str, -1), RED);
	return (SUCCESS);
}

int	strncmp_03(void)
{
	int		result = 1;
	char	str1[4] = {-1, -2, 0, -3};
	char	str2[4] = {-1, -2, 0, -4};

	result = result && (ft_strncmp(str1, str2, 3) == strncmp(str1, str2, 3));
	result = result && (ft_strncmp(str1, str2, 4) == strncmp(str1, str2, 4));

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strncmp_04(void)
{
	int		result = 1;
	char	str1[4] = {-1, -2, -3, 0};
	char	str2[4] = {-1, -2, 0};

	result = result && (ft_strncmp(str1, str2, 2) == strncmp(str1, str2, 2));
	result = result && (ft_strncmp(str1, str2, 3) == strncmp(str1, str2, 3));

	_ft_assert(result, RED);
	return (SUCCESS);
}
