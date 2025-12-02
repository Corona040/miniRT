/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:21:03 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 15:59:14 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstdelone_00(void);

test_suite	lstdelone_tests = {lstdelone_00, NULL};

static void	delone(void *content)
{
	if (content)
		free(content);
}

int	lstdelone_00(void)
{
	t_list	*lst;

	lst = ft_lstnew((void *)NULL);
	ft_lstdelone(NULL, NULL);
	ft_lstdelone(lst, NULL);
	if (lst)
		free(lst);
	lst = ft_lstnew((void *)NULL);
	ft_lstdelone(lst, delone);

	_ft_assert(1, RED);
	return (SUCCESS);
}
