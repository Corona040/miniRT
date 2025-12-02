/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:47:41 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:19:49 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	atoi_00(void);
int	atoi_01(void);
int	atoi_02(void);
int	atoi_03(void);
int	atoi_04(void);
int	atoi_05(void);

test_suite	atoi_tests = {atoi_00, atoi_01, atoi_02, atoi_03, atoi_04, NULL};

int	atoi_00(void)
{
	ft_atoi(NULL);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	atoi_01(void)
{
	char	str[1] = {0};

	_ft_assert(ft_atoi(str) == atoi(str), RED);
	return (SUCCESS);
}

int	atoi_02(void)
{
	char	*str = "---+++--++-+-000123000a";

	_ft_assert(ft_atoi(str) == atoi(str), RED);
	return (SUCCESS);
}

int	atoi_03(void)
{
	char	*str = "/000123000a";

	_ft_assert(ft_atoi(str) == atoi(str), RED);
	return (SUCCESS);
}

int	atoi_04(void)
{
	char	*str = "2147483648";

	_ft_assert(ft_atoi(str) == atoi(str), RED);
	return (SUCCESS);
}

int	atoi_05(void)
{
	char	*str = "-2147483649";

	_ft_assert(ft_atoi(str) == atoi(str), RED);
	return (SUCCESS);
}
