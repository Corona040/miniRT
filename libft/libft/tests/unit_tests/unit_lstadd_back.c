/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:15:47 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 15:59:01 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstadd_back_00(void);
int	lstadd_back_01(void);

test_suite	lstadd_back_tests = {lstadd_back_00, lstadd_back_01, NULL};

int	lstadd_back_00(void)
{
	t_list	*lst;
	t_list	*ptr = NULL;

	ft_lstadd_back(NULL, NULL);
	ft_lstadd_back(&ptr, NULL);
	lst = ft_lstnew((void *)NULL);
	ft_lstadd_back(NULL, lst);
	ft_lstadd_back(&ptr, lst);
	if (lst)
		free(lst);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstadd_back_01(void)
{
	t_list	*l1;
	t_list	*l2;
	t_list	**lst;
	int		result = 1;

	l1 = ft_lstnew((void *)NULL);
	l2 = ft_lstnew((void *)NULL);
	lst = &l1;
	ft_lstadd_back(lst, l2);
	result = result && (*lst == l1);
	result = result && (l1->next == l2);
	result = result && (l2->next == NULL);

	_ft_assert(result, RED);
	return (SUCCESS);
}
