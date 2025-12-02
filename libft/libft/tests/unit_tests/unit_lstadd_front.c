/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:55:19 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 16:41:18 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstadd_front_00(void);
int	lstadd_front_01(void);

test_suite	lstadd_front_tests = {lstadd_front_00, lstadd_front_01, NULL};

int	lstadd_front_00(void)
{
	t_list	*lst;
	t_list	*ptr = NULL;

	ft_lstadd_front(NULL, NULL);
	ft_lstadd_front(&ptr, NULL);
	lst = ft_lstnew((void *)NULL);
	ft_lstadd_front(NULL, lst);
	ft_lstadd_front(&ptr, lst);
	if (lst)
		free(lst);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstadd_front_01(void)
{
	t_list	*lst;
	t_list	*node;
	t_list	*tmp1;
	t_list	*tmp2;
	int		result = 1;

	lst = ft_lstnew((void *)NULL);
	node = ft_lstnew((void *)lst);
	tmp1 = lst;
	tmp2 = node;
	ft_lstadd_front(&lst, node);
	result = result && (lst == tmp2);
	result = result && ((lst)->next == tmp1);
	result = result && (((lst)->next)->next == NULL);

	_ft_assert(result, RED);
	return (SUCCESS);
}
