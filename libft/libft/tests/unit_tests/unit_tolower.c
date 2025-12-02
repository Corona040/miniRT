/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:27:07 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:23:01 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	tolower_00(void);

test_suite	tolower_tests = {tolower_00, NULL};

// compare to original from EOF to max unsigned char
int	tolower_00(void)
{
	int	result = 1;

	for (int i = -1; i < 256; i++)
		result = result && (ft_tolower(i) == tolower(i));

	_ft_assert(result, RED);
	return (SUCCESS);
}
