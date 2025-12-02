/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:45:24 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:33 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strlcpy_00(void);
int	strlcpy_01(void);
int	strlcpy_02(void);
int	strlcpy_03(void);

test_suite	strlcpy_tests = {strlcpy_00, strlcpy_01, strlcpy_02, strlcpy_03, NULL};

int	strlcpy_00(void)
{
	char	str[1] = {-1};

	ft_strlcpy(NULL, NULL, 1);
	ft_strlcpy(NULL, str, 1);
	ft_strlcpy(str, NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strlcpy_01(void)
{
	int		result = 1;
	char	src1[5] = {1, 2, 3, 4, 0};
	char	dst1[5] = {-1, -1, 0, -1, -1};
	char	src2[5] = {1, 2, 3, 4, 0};
	char	dst2[5] = {-1, -1, 0, -1, -1};

	result = result && (ft_strlcpy(dst1, src1, 0) == strlcpy(dst2, src2, 0));
	for (int i = 0; i < 5; i++) {
		result = result && (src1[i] == src2[i]);
		result = result && (dst1[i] == dst2[i]);
	}

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strlcpy_02(void)
{
	int		result = 1;
	char	src1[5] = {1, 2, 3, 4, 0};
	char	dst1[5] = {-1, -1, 1, -1, -1};
	char	src2[5] = {1, 2, 3, 4, 0};
	char	dst2[5] = {-1, -1, 1, -1, -1};

	result = result && (ft_strlcpy(dst1, src1, 3) == strlcpy(dst2, src2, 3));
	for (int i = 0; i < 5; i++) {
		result = result && (src1[i] == src2[i]);
		result = result && (dst1[i] == dst2[i]);
	}

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strlcpy_03(void)
{
	int		result = 1;
	char	src1[5] = {1, 0, 3, 4, 0};
	char	dst1[5] = {-1, -1, 0, -1, -1};
	char	src2[5] = {1, 0, 3, 4, 0};
	char	dst2[5] = {-1, -1, 0, -1, -1};

	result = result && (ft_strlcpy(dst1, src1, 5) == strlcpy(dst2, src2, 5));
	for (int i = 0; i < 5; i++) {
		result = result && (src1[i] == src2[i]);
		result = result && (dst1[i] == dst2[i]);
	}

	_ft_assert(result, RED);
	return (SUCCESS);
}
