/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:27:17 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 16:44:31 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstclear_00(void);
int	lstclear_01(void);

test_suite	lstclear_tests = {lstclear_00, lstclear_01, NULL};

static void	delclear(void *content)
{
	if (content)
		free(content);
}

int	lstclear_00(void)
{
	t_list	*lst;

	ft_lstclear(NULL, NULL);
	lst = ft_lstnew((void *)NULL);
	ft_lstclear(&lst, NULL);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstclear_01(void)
{
	t_list	*lst;

	lst = ft_lstnew((void *)NULL);
	ft_lstclear(&lst, delclear);

	_ft_assert(lst == NULL, RED);
	return (SUCCESS);
}
