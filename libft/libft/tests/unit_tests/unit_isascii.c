/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:24:51 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:36 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	isascii_00(void);

test_suite	isascii_tests = {isascii_00, NULL};

// compare to original from EOF to max unsigned char
int	isascii_00(void)
{
	int	result = 1;

	for (int i = -1; i < 256; i++)
		result = result && ((ft_isascii(i) > 0) == (isascii(i) > 0));

	_ft_assert(result, RED);
	return (SUCCESS);
}
