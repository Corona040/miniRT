/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:09:02 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 16:41:54 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstsize_00(void);
int	lstsize_01(void);

test_suite	lstsize_tests = {lstsize_00, lstsize_01, NULL};

int	lstsize_00(void)
{
	ft_lstsize(NULL);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstsize_01(void)
{
	t_list	*lst;
	t_list	*node;

	lst = ft_lstnew((void *)NULL);
	node = ft_lstnew((void *)NULL);
	ft_lstadd_front(&lst, node);
	node = ft_lstnew((void *)NULL);
	ft_lstadd_front(&lst, node);
	node = ft_lstnew((void *)NULL);
	ft_lstadd_front(&lst, node);

	_ft_assert(ft_lstsize(lst) == 4, RED);
	return (SUCCESS);
}
