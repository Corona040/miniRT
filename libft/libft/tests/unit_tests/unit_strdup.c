/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:49:40 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:12 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strdup_00(void);
int	strdup_01(void);
int	strdup_02(void);
int	strdup_03(void);

test_suite	strdup_tests = {strdup_00, strdup_01, strdup_02, strdup_03, NULL};

int	strdup_00(void)
{
	ft_strdup(NULL);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strdup_01(void)
{
	char	str[1] = {0};
	void	*res1;
	void	*res2;

	res1 = ft_strdup(str);
	res2 = strdup(str);
	_ft_assert(((res1 != NULL) == (res2 != NULL)) && !strcmp(res1 , res2), RED);
	if (res1)
		free(res1);
	if (res2)
		free(res2);
	return (SUCCESS);
}

int	strdup_02(void)
{
	char	str[5] = {-1, 1, 1, -1, 0};
	void	*res1;
	void	*res2;

	res1 = ft_strdup(str);
	res2 = strdup(str);
	_ft_assert(((res1 != NULL) == (res2 != NULL)) && !strcmp(res1 , res2), RED);
	if (res1)
		free(res1);
	if (res2)
		free(res2);
	return (SUCCESS);
}

int	strdup_03(void)
{
	char	str[5] = {-1, 1, 1, -1, 0};
	void	*ptr;

	fail_malloc = true;
	ptr = ft_strdup(str);

	_ft_assert(ptr == NULL, RED);
	if (ptr)
		free(ptr);
	return (SUCCESS);
}
