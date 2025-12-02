/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:24:10 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:30 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	isalnum_00(void);

test_suite	isalnum_tests = {isalnum_00, NULL};

// compare to original from EOF to max unsigned char
int	isalnum_00(void)
{
	int	result = 1;

	for (int i = -1; i < 256; i++)
		result = result && ((ft_isalnum(i) > 0) == (isalnum(i) > 0));

	_ft_assert(result, RED);
	return (SUCCESS);
}
