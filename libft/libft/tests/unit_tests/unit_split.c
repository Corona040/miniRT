/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:53:59 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:54 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	split_00(void);
int	split_01(void);
int	split_02(void);
int	split_03(void);

test_suite	split_tests = {split_00, split_01, split_02, split_03, NULL};

int	split_00(void)
{
	ft_split(NULL, 1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	split_01(void)
{
	char	str[2] = {1, 0};

	ft_split(str, 0);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	split_02(void)
{
	char	str[10] = {2, 1, 2, 1, 2, 1, 1, 1, 2, 0};
	char	res[4][4] = {{1,0}, {1,0}, {1,1,1,0}, {0}};
	char	**split;
	int		result = 1;

	split = ft_split(str, 2);
	for (int i = 0; split[i]; i++) {
		result = result && (!strcmp(split[i], res[i]));
		free(split[i]);
	}
	free(split);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	split_03(void)
{
	char	**split;

	fail_malloc = true;
	split = ft_split("  ha ha ha  ", ' ');

	_ft_assert(split == NULL, RED);
	if (split) {
		for (int i = 0; split[i]; i++)
			free(split[i]);
		free(split);
	}
	return (SUCCESS);
}
