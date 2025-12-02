/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:56:56 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:22:18 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	striteri_00(void);
int	striteri_01(void);
int	striteri_02(void);

test_suite	striteri_tests = {striteri_00, striteri_01, striteri_02, NULL};

static void	striteri_toupper(unsigned int i, char *c)
{
	(void)i;
	*c = toupper(*c);
}

int	striteri_00(void)
{
	char	str[1] = {0};

	ft_striteri(NULL, NULL);
	ft_striteri(str, NULL);
	ft_striteri(NULL, striteri_toupper);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	striteri_01(void)
{
	char	str[1] = {0};
	int		result = 1;

	ft_striteri(str, striteri_toupper);
	result = result && (*str == 0);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	striteri_02(void)
{
	char	str[10] = "a1b-hello";
	char	res[10] = "A1B-HELLO";
	int		result = 1;

	ft_striteri(str, striteri_toupper);
	result = result && (!strcmp(res, str));

	_ft_assert(result, RED);
	return (SUCCESS);
}
