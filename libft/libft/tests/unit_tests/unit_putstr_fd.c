/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:59:34 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:50 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	putstr_fd_00(void);
int	putstr_fd_01(void);

test_suite	putstr_fd_tests = {putstr_fd_00, putstr_fd_01, NULL};

int	putstr_fd_00(void)
{
	ft_putchar_fd(0, -1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	putstr_fd_01(void)
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
		result = result && (*buf == str[i]);
		i++;
	}
	close(pipefd[0]);

	_ft_assert(result, RED);
	return (SUCCESS);
}
