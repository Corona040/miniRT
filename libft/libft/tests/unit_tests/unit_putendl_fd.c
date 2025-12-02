/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:00:30 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:39 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	putendl_fd_00(void);
int	putendl_fd_01(void);

test_suite	putendl_fd_tests = {putendl_fd_00, putendl_fd_01, NULL};

int	putendl_fd_00(void)
{
	ft_putendl_fd(0, -1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	putendl_fd_01(void)
{
	int		pipefd[2];
	char	buf[1];
	char	*str = "Hello";
	int		result = 1;

	pipe(pipefd);
	if (fork() == 0) {
		close(pipefd[0]);
		ft_putstr_fd(str, pipefd[1]);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);

	int	i = 0;
	while (read(pipefd[0], &buf, 1) > 0) {
		if (i < 5)
			result = result && (*buf == str[i]);
		else
			result = result && (*buf == '\n');
		i++;
	}
	close(pipefd[0]);

	_ft_assert(result, RED);
	return (SUCCESS);
}
