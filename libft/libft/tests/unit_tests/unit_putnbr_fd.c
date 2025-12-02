/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:01:24 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 01:21:45 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

int	putnbr_fd_00(void);
int	putnbr_fd_01(void);
int	putnbr_fd_02(void);
int	putnbr_fd_03(void);

test_suite	putnbr_fd_tests = {putnbr_fd_00, putnbr_fd_01, putnbr_fd_02, putnbr_fd_03, NULL};

int	putnbr_fd_00(void)
{
	ft_putnbr_fd(0, -1);

	_ft_assert(1, RED);
	return (SUCCESS);
}

int	putnbr_fd_01(void)
{
	int		pipefd[2];
	char	buf[1];
	int		nbr = 42;
	int		result = 1;

	pipe(pipefd);
	if (fork() == 0) {
		close(pipefd[0]);
		ft_putnbr_fd(nbr, pipefd[1]);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);

	int	i = 0;
	while (read(pipefd[0], &buf, 1) > 0) {
		result = result && (*buf == "42"[i]);
		i++;
	}
	close(pipefd[0]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	putnbr_fd_02(void)
{
	int		pipefd[2];
	char	buf[1];
	int		nbr = INT_MAX;
	int		result = 1;

	pipe(pipefd);
	if (fork() == 0) {
		close(pipefd[0]);
		ft_putnbr_fd(nbr, pipefd[1]);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);

	int	i = 0;
	while (read(pipefd[0], &buf, 1) > 0) {
		result = result && (*buf == "2147483647"[i]);
		i++;
	}
	close(pipefd[0]);

	_ft_assert(result, RED);
	return (SUCCESS);
}

int	putnbr_fd_03(void)
{
	int		pipefd[2];
	char	buf[1];
	int		nbr = INT_MIN;
	int		result = 1;

	pipe(pipefd);
	if (fork() == 0) {
		close(pipefd[0]);
		ft_putnbr_fd(nbr, pipefd[1]);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);

	int	i = 0;
	while (read(pipefd[0], &buf, 1) > 0) {
		result = result && (*buf == "-2147483648"[i]);
		i++;
	}
	close(pipefd[0]);

	_ft_assert(result, RED);
	return (SUCCESS);
}
