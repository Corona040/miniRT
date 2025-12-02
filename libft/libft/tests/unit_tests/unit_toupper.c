/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:26:25 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:23:05 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	toupper_00(void);

test_suite	toupper_tests = {toupper_00, NULL};

// compare to original from EOF to max unsigned char
int	toupper_00(void)
{
	int	result = 1;

	for (int i = -1; i < 256; i++)
		result = result && (ft_toupper(i) == toupper(i));

	_ft_assert(result, RED);
	return (SUCCESS);
}
