/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:51:47 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:22 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strjoin_00(void);
int	strjoin_01(void);
int	strjoin_02(void);
int	strjoin_03(void);
int	strjoin_04(void);

test_suite	strjoin_tests = {strjoin_00, strjoin_01, strjoin_02, strjoin_03, strjoin_04, NULL};

int	strjoin_00(void)
{
	char	str[1] = {0};
	char	*strjoin;

	strjoin = ft_strjoin(NULL, NULL);
	if (strjoin)
		free(strjoin);
	ft_strjoin(str, NULL);
	if (strjoin)
		free(strjoin);
	ft_strjoin(NULL, str);
	if (strjoin)
		free(strjoin);
	ft_strjoin(str, str);
	if (strjoin)
		free(strjoin);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strjoin_01(void)
{
	char	str1[4] = {-1, 1, 2, 0};
	char	str2[7] = {-1, 1, 2, 3, 4, 5, 0};
	char	res[10] = {-1, 1, 2, -1, 1, 2, 3, 4, 5, 0};
	char	*strjoin;
	int		result = 1;

	strjoin = ft_strjoin(str1, str2);
	result = result && (!strcmp(strjoin, res));
	free(strjoin);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strjoin_02(void)
{
	char	str1[1] = {0};
	char	str2[7] = {-1, 1, 2, 3, 4, 5, 0};
	char	*strjoin;
	int		result = 1;

	strjoin = ft_strjoin(str1, str2);
	result = result && (!strcmp(strjoin, str2));
	free(strjoin);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strjoin_03(void)
{
	char	str1[1] = {0};
	char	str2[7] = {-1, 1, 2, 3, 4, 5, 0};
	char	*strjoin;
	int		result = 1;

	strjoin = ft_strjoin(str2, str1);
	result = result && (!strcmp(strjoin, str2));
	free(strjoin);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strjoin_04(void)
{
	char	*strjoin;

	fail_malloc = true;
	strjoin = ft_strjoin("he", "llo");

	_ft_assert(strjoin == NULL, RED);
	if (strjoin)
		free(strjoin);
	return (SUCCESS);
}
