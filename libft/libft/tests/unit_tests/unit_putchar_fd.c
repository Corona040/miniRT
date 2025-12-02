/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:58:21 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:35 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	putchar_fd_00(void);
int	putchar_fd_01(void);

test_suite	putchar_fd_tests = {putchar_fd_00, putchar_fd_01, NULL};

int	putchar_fd_00(void)
{
	ft_putchar_fd(0, -1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	putchar_fd_01(void)
{
	int		pipefd[2];
	char	buf[1];

	pipe(pipefd);
	if (fork() == 0) {
		close(pipefd[0]);
		ft_putchar_fd(42, pipefd[1]);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);
	while (read(pipefd[0], &buf, 1) > 0)
		;
	close(pipefd[0]);

	_ft_assert(*buf == 42, RED);
	return (SUCCESS);
}
