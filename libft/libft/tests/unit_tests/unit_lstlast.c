/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:14:14 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 16:42:43 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstlast_00(void);
int	lstlast_01(void);

test_suite	lstlast_tests = {lstlast_00, lstlast_01, NULL};

int	lstlast_00(void)
{
	ft_lstlast(NULL);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstlast_01(void)
{
	t_list	*lst;
	t_list	*node;
	t_list	*tmp;

	lst = ft_lstnew((void *)NULL);
	tmp = lst;
	node = ft_lstnew((void *)NULL);
	ft_lstadd_front(&lst, node);
	node = ft_lstnew((void *)NULL);
	ft_lstadd_front(&lst, node);
	node = ft_lstnew((void *)NULL);
	ft_lstadd_front(&lst, node);
	node = ft_lstnew((void *)NULL);
	ft_lstadd_front(&lst, node);

	_ft_assert(ft_lstlast(lst) == tmp, RED);
	return (SUCCESS);
}
