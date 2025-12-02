/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:46:16 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:28 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strlcat_00(void);
int	strlcat_01(void);
int	strlcat_02(void);
int	strlcat_03(void);

test_suite	strlcat_tests = {strlcat_00, strlcat_01, strlcat_02, strlcat_03, NULL};

int	strlcat_00(void)
{
	char	str[1] = {-1};

	ft_strlcat(NULL, NULL, 1);
	ft_strlcat(NULL, str, 1);
	ft_strlcat(str, NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strlcat_01(void)
{
	int		result = 1;
	char	src1[5] = {1, 2, 3, 4, 0};
	char	dst1[10] = {-1, -1, 0, -1, -1, 0, 0, 0, 0, 0};
	char	src2[5] = {1, 2, 3, 4, 0};
	char	dst2[10] = {-1, -1, 0, -1, -1, 0, 0, 0, 0, 0};

	result = result && (ft_strlcat(dst1, src1, 0) == strlcat(dst2, src2, 0));
	for (int i = 0; i < 5; i++) {
		result = result && (src1[i] == src2[i]);
		result = result && (dst1[i] == dst2[i]);
	}

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strlcat_02(void)
{
	int		result = 1;
	char	src1[5] = {1, 2, 3, 4, 0};
	char	dst1[10] = {-1, -1, 1, -1, 0, 0, 0, 0, 0, 0};
	char	src2[5] = {1, 2, 3, 4, 0};
	char	dst2[10] = {-1, -1, 1, -1, 0, 0, 0, 0, 0, 0};

	result = result && (ft_strlcat(dst1, src1, 3) == strlcat(dst2, src2, 3));
	for (int i = 0; i < 5; i++) {
		result = result && (src1[i] == src2[i]);
		result = result && (dst1[i] == dst2[i]);
	}

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strlcat_03(void)
{
	int		result = 1;
	char	src1[5] = {1, 0, 3, 4, 0};
	char	dst1[10] = {-1, -1, 0, -1, -1, 0, 0, 0, 0, 0};
	char	src2[5] = {1, 0, 3, 4, 0};
	char	dst2[10] = {-1, -1, 0, -1, -1, 0, 0, 0, 0, 0};

	result = result && (ft_strlcat(dst1, src1, 5) == strlcat(dst2, src2, 5));
	for (int i = 0; i < 5; i++) {
		result = result && (src1[i] == src2[i]);
		result = result && (dst1[i] == dst2[i]);
	}

	_ft_assert(result, RED);
	return (SUCCESS);
}
