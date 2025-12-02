/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:42:55 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 16:51:06 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	lstmap_00(void);
int	lstmap_01(void);
int	lstmap_02(void);

test_suite	lstmap_tests = {lstmap_00, lstmap_01, lstmap_02, NULL};

static int	lstcmp(t_list *lst, char *contents, size_t n)
{
	int	result = 1;

	for (size_t i = 0; i < n; i++) {
		result = result && (*(char *)lst->content == contents[i]);
		lst = lst->next;
	}
	result = result && (lst == NULL);
	return (result);
}

static void	*fmap(void *content)
{
	*(char *)content = toupper(*(char *)content);
	return (content);
}

static void	*donothing(void *content)
{
	return (content);
}

static void	delnothing(void *content)
{
	(void)content;
	return ;
}

int	lstmap_00(void)
{
	t_list	*lst;

	ft_lstmap(NULL, NULL, NULL);
	lst = ft_lstnew((void *)NULL);
	ft_lstmap(lst, NULL, NULL);
	if (lst)
		free(lst);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	lstmap_01(void)
{
	char	contents[14] = "hello, world!";
	char	expect[14] = "HELLO, WORLD!";
	t_list	*lst;
	t_list	*node;
	t_list	*map;
	int		result = 1;

	lst = ft_lstnew((void *)contents);
	for (int i = 1; i < 14; i++) {
		node = ft_lstnew((void *)contents + i);
		ft_lstadd_back(&lst, node);
	}
	map = ft_lstmap(lst, fmap, NULL);
	result = result && (!strcmp(contents, expect));
	result = result && (lstcmp(map, expect, 14));
	ft_lstclear(&lst, delnothing);
	ft_lstclear(&map, delnothing);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	lstmap_02(void)
{
	t_list	*l;
	t_list	*map;

	fail_malloc = true;
	l = ft_lstnew((void *)NULL);
	map = ft_lstmap(l, donothing, delnothing);
	if (map)
		free(map);

	_ft_assert(1, RED);
	return (SUCCESS);
}
