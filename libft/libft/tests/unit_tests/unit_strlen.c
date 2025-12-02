/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:30:30 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:36 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strlen_00(void);
int	strlen_01(void);
int	strlen_02(void);

test_suite	strlen_tests = {strlen_00, strlen_01, strlen_02, NULL};

// check null handling
int	strlen_00(void)
{
	ft_strlen(NULL);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strlen_01(void)
{
	char	str[5] = {0,-1,-1,-1,-1};

	_ft_assert(ft_strlen(str) == strlen(str), RED);
	return (SUCCESS);
}

int	strlen_02(void)
{
	char	str[5] = {-1,-1,-1,-1,0};

	_ft_assert(ft_strlen(str) == strlen(str), RED);
	return (SUCCESS);
}
