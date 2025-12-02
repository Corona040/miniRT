/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:52:50 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:54 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strtrim_00(void);
int	strtrim_01(void);
int	strtrim_02(void);
int	strtrim_03(void);

test_suite	strtrim_tests = {strtrim_00, strtrim_01, strtrim_02, strtrim_03, NULL};

int	strtrim_00(void)
{
	char	str[1] = {0};
	char	*trim;

	trim = ft_strtrim(NULL, NULL);
	if (trim)
		free(trim);
	trim = ft_strtrim(str, NULL);
	if (trim)
		free(trim);
	trim = ft_strtrim(NULL, str);
	if (trim)
		free(trim);
	trim = ft_strtrim(str, str);
	if (trim)
		free(trim);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	strtrim_01(void)
{
	char	str[4] = {1,2,3,0};
	char	set[1] = {0};
	char	*strtrim;
	int		result = 1;

	strtrim = ft_strtrim(str, set);
	result = result && (!strcmp(strtrim, str));
	free(strtrim);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strtrim_02(void)
{
	char	str[10] = {-3, -1, 2, -2, -1, 5, -2, -1, 0};
	char	set[4] = {-1, -2, -3, 0};
	char	res[5] = {2, -2, -1, 5, 0};
	char	*trim;
	int		result = 1;

	trim = ft_strtrim(str, set);
	result = result && (!strcmp(trim, res));
	free(trim);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strtrim_03(void)
{
	char	*strtrim;

	fail_malloc = true;
	strtrim = ft_strtrim("abba","a");

	_ft_assert(strtrim == NULL, RED);
	if (strtrim)
		free(strtrim);
	return (SUCCESS);
}
