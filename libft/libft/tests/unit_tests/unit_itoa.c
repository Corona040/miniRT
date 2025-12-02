/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:55:08 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:49 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	itoa_00(void);
int	itoa_01(void);
int	itoa_02(void);
int	itoa_03(void);

test_suite	itoa_tests = {itoa_00, itoa_01, itoa_02, itoa_03, NULL};

int	itoa_00(void)
{
	char	*a;
	int		result = 1;

	a = ft_itoa(INT_MAX);
	result = result && (!strcmp(a, "2147483647"));
	free(a);
	a = ft_itoa(INT_MIN);
	result = result && (!strcmp(a, "-2147483648"));
	free(a);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	itoa_01(void)
{
	char	*a;
	int		result = 1;

	a = ft_itoa(0);
	result = result && (!strcmp(a, "0"));
	free(a);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	itoa_02(void)
{
	char	*a;
	int		result = 1;

	a = ft_itoa(15);
	result = result && (!strcmp(a, "15"));
	free(a);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	itoa_03(void)
{
	char	*a;

	fail_malloc = true;
	a = ft_itoa(10);

	_ft_assert(a == NULL, RED);
	return (SUCCESS);
}
