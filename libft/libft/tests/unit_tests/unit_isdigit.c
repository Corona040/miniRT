/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:22:02 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:40 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	isdigit_00(void);

test_suite	isdigit_tests = {isdigit_00, NULL};

// compare to original from EOF to max unsigned char
int	isdigit_00(void)
{
	int	result = 1;

	for (int i = -1; i < 256; i++)
		result = result && ((ft_isdigit(i) > 0) == (isdigit(i) > 0));

	_ft_assert(result, RED);
	return (SUCCESS);
}
