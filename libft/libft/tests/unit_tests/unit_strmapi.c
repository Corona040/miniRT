/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:55:57 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:39 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	strmapi_00(void);
int	strmapi_01(void);
int	strmapi_02(void);
int	strmapi_03(void);

test_suite	strmapi_tests = {strmapi_00, strmapi_01, strmapi_02, strmapi_03, NULL};

static char	strmapi_toupper(unsigned int i, char c)
{
	(void)i;
	return (toupper(c));
}

int	strmapi_00(void)
{
	char	str[1] = {0};
	char	*map;
	int		result = 1;

	map = ft_strmapi(NULL, NULL);
	result = result && (map == NULL);
	map = ft_strmapi(str, NULL);
	result = result && (map == NULL);
	map = ft_strmapi(NULL, strmapi_toupper);
	result = result && (map == NULL);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strmapi_01(void)
{
	char	str[1] = {0};
	char	*map;
	int		result = 1;

	map = ft_strmapi(str, strmapi_toupper);
	result = result && (*map == 0);
	free(map);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strmapi_02(void)
{
	char	str[10] = "a1b-hello";
	char	*map;
	char	res[10] = "A1B-HELLO";
	int		result = 1;

	map = ft_strmapi(str, strmapi_toupper);
	result = result && (!strcmp(res, map));
	free(map);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	strmapi_03(void)
{
	char	str[10] = "a1b-hello";
	char	*map;
	int		result = 1;


	fail_malloc = true;
	map = ft_strmapi(str, strmapi_toupper);
	result = result && (map == NULL);
	if (map)
		free(map);

	_ft_assert(result, RED);
	return (SUCCESS);
}
