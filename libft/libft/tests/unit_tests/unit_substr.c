/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:50:39 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:58 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	substr_00(void);
int	substr_01(void);
int	substr_02(void);
int	substr_03(void);
int	substr_04(void);

test_suite	substr_tests = {substr_00, substr_01, substr_02, substr_03, substr_04, NULL};

int	substr_00(void)
{
	char	*substr;

	substr = ft_substr(NULL, 0, 1);
	if (substr)
		free(substr);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	substr_01(void)
{
	char	*substr;
	char	str[10] = {-1, 1, 2, 3, 4, 5, 6, 0, 1, 1};

	substr = ft_substr(str, 0, 0);
	free(substr);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	substr_02(void)
{
	char	*substr;
	char	str[10] = {-1, 1, 2, 3, 4, 5, 6, 0, 1, 1};
	int		result = 1;

	substr = ft_substr(str, 0, -1);
	result = !strcmp(substr, str);
	free(substr);

	_ft_assert(result , RED);
	return (SUCCESS);
}

int	substr_03(void)
{
	char	*substr;
	char	str[10] = {-1, 1, 2, 3, 4, 5, 6, 0, 1, 1};
	int		result = 1;

	substr = ft_substr(str, 2, 4);
	for (int i = 0; i < 4; i++)
		result = result && (substr[i] == str[2 + i]);
	result = result && (substr[2 + 4] == 0);
	free(substr);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	substr_04(void)
{
	char	*substr;

	fail_malloc = true;
	substr = ft_substr("hello", 1, 1);

	_ft_assert(substr == NULL, RED);
	if (substr)
		free(substr);
	return (SUCCESS);
}
