/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:44:18 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:47 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strnstr_00(void);
int	strnstr_01(void);
int	strnstr_02(void);
int	strnstr_03(void);
int	strnstr_04(void);
int	strnstr_05(void);
int	strnstr_06(void);

test_suite	strnstr_tests = {strnstr_00, strnstr_01, strnstr_02, strnstr_03, strnstr_04, strnstr_05, strnstr_06, NULL};

// check null handling
int	strnstr_00(void)
{
	char	str[1] = {-1};

	ft_strnstr(NULL, NULL, 1);
	ft_strnstr(NULL, str, 1);
	ft_strnstr(str, NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strnstr_01(void)
{
	char	little[1] = {-1};
	char	big[1] = {-1};

	_ft_assert(ft_strnstr(big, little, 0) == strnstr(big, little, 0), RED);
	return (SUCCESS);
}

int	strnstr_02(void)
{
	char	little[1] = {0};
	char	big[1] = {-1};

	_ft_assert(ft_strnstr(big, little, -1) == strnstr(big, little, -1), RED);
	return (SUCCESS);
}

int	strnstr_03(void)
{
	char	little[1] = {1};
	char	big[5] = {2, 3, 4, 5, 0};

	_ft_assert(ft_strnstr(big, little, -1) == strnstr(big, little, -1), RED);
	return (SUCCESS);
}

int	strnstr_04(void)
{
	char	little[4] = {1, 2, 3, 0};
	char	big[10] = {1, 2, 1, 3, 1, 2, 1, 2, 3, 2};

	_ft_assert(ft_strnstr(big, little, -1) == strnstr(big, little, -1), RED);
	return (SUCCESS);
}

int	strnstr_05(void)
{
	char	little[4] = {1, 2, 3, 0};
	char	big[10] = {1, 2, 1, 3, 1, 2, 1, 2, 3, 2};

	_ft_assert(ft_strnstr(big, little, 8) == strnstr(big, little, 8), RED);
	return (SUCCESS);
}

int	strnstr_06(void)
{
	char	little[4] = {1, 2, 3, 0};
	char	big[10] = {1, 2, 1, 3, 1, 2, 1, 2, 3, 2};

	_ft_assert(ft_strnstr(big, little, 9) == strnstr(big, little, 9), RED);
	return (SUCCESS);
}
