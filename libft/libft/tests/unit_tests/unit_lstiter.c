/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:34:38 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 16:48:50 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstiter_00(void);
int	lstiter_01(void);

test_suite	lstiter_tests = {lstiter_00, lstiter_01, NULL};

static void	fiter(void *content)
{
	*(char *)content = toupper(*(char *)content);
}

static void	delnothing(void *content)
{
	(void)content;
	return ;
}

int	lstiter_00(void)
{
	t_list	*lst;

	ft_lstiter(NULL, NULL);
	lst = ft_lstnew((void *)NULL);
	ft_lstiter(lst, NULL);
	if (lst)
		free(lst);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstiter_01(void)
{
	char	contents[14] = "hello, world!";
	char	expect[14] = "HELLO, WORLD!";
	t_list	*lst;
	t_list	*node;

	lst = ft_lstnew((void *)contents);
	for (int i = 1; i < 14; i++) {
		node = ft_lstnew((void *)contents + i);
		ft_lstadd_back(&lst, node);
	}
	ft_lstiter(lst, fiter);
	ft_lstclear(&lst, delnothing);

	_ft_assert(!strcmp(contents, expect), RED);
	return (SUCCESS);
}
