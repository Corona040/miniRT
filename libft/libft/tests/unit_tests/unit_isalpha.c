/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:53:36 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:33 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	isalpha_00(void);

test_suite	isalpha_tests = {isalpha_00, NULL};

// compare to original from EOF to max unsigned char
int	isalpha_00(void)
{
	int	result = 1;

	for (int i = -1; i < 256; i++)
		result = result && ((ft_isalpha(i) > 0) == (isalpha(i) > 0));

	_ft_assert(result, RED);
	return (SUCCESS);
}
