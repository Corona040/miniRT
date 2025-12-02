/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:48:24 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:20:26 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	calloc_00(void);
int	calloc_01(void);
// int	calloc_02(void);
int	calloc_03(void);
int	calloc_04(void);

test_suite	calloc_tests = {calloc_00, calloc_01, calloc_03, calloc_04, NULL};

int	calloc_00(void)
{
	void	*ptr;

	ptr = ft_calloc(0, 0);
	if (ptr)
		free(ptr);
	ptr = ft_calloc(1, 0);
	if (ptr)
		free(ptr);
	ptr = ft_calloc(0, 1);
	if (ptr)
		free(ptr);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	calloc_01(void)
{
	_ft_assert(ft_calloc(10, (size_t)4294967295) == calloc(10, (size_t)4294967295), RED);
	return (SUCCESS);
}

// int	calloc_02(void)
// {
// 	int		result = 0;
// 	void	*ptr;
//
// 	ptr = ft_calloc(2, (size_t)4294967295);
// 	if (ptr) {
// 		result = 1;
// 		free(ptr);
// 	}
//
// 	_ft_assert(result , RED);
// 	return (SUCCESS);
// }

int	calloc_03(void)
{
	int		result = 1;
	void	*ptr;

	ptr = ft_calloc(2,2);
	for (int i = 0; i < 4; i++)
		result = result && (((char *)ptr)[i] == 0);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	calloc_04(void)
{
	void	*ptr;

	fail_malloc = true;
	ptr = ft_calloc(2, 2);

	_ft_assert(ptr == NULL, RED);
	if (ptr)
		free(ptr);
	return (SUCCESS);
}
