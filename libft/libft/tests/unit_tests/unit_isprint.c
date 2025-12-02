/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:25:41 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:45 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	isprint_00(void);

test_suite	isprint_tests = {isprint_00, NULL};

// compare to original from EOF to max unsigned char
int	isprint_00(void)
{
	int	result = 1;

	for (int i = -1; i < 256; i++)
		result = result && ((ft_isprint(i) > 0) == (isprint(i) > 0));

	_ft_assert(result, RED);
	return (SUCCESS);
}
