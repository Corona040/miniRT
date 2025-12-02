/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:44:49 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 16:49:33 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstnew_00(void);
int	lstnew_01(void);
int	lstnew_02(void);

test_suite	lstnew_tests = {lstnew_00, lstnew_01, lstnew_02, NULL};

int	lstnew_00(void)
{
	t_list	*lst;
	
	lst = ft_lstnew(NULL);
	if (lst)
		free(lst);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstnew_01(void)
{
	int		contents[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
	t_list	*lst;
	int		result = 1;

	lst = ft_lstnew(contents);
	result = result && (*(int *)lst->content == -1);
	result = result && (lst->next == NULL);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	lstnew_02(void)
{
	int		contents[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};
	t_list	*lst;

	fail_malloc = true;
	lst = ft_lstnew(contents);
	if (lst)
		free(lst);

	_ft_assert(1, RED);
	return (SUCCESS);
}
