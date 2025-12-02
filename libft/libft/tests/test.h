/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:30:36 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/28 17:08:56 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include "../libft.h"

# include <stdlib.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# include <execinfo.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define DFLT "\033[0m"

# define CRASH 2
# define FAILURE 1
# define SUCCESS 0

extern int	fail_malloc;
extern int	status;

typedef int(*unit_test)(void);
typedef unit_test test_suite[];

int			ft_test_env(unit_test test);
void		ft_announce(void);

# define _ft_FAIL(severity) printf(severity"%-5s ", " T-T ")
# define _ft_PASS() printf(GREEN"%-5s ", " ^-^ ")
# define _ft_assert(test, severity) do {if (!(test)){ _ft_FAIL(severity); return (FAILURE);} else { _ft_PASS();}} while (0)
# define _ft_verify(test) do { int r=test(); tests_run++; if (r) return (r);} while (0)
# define _ft_weakVerify(test) do { int r=ft_test_env(test); tests_run++; if (r == 1) status += r;} while (0)

// LIBFT
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>

#include "libft_tests.h"
//

#endif
