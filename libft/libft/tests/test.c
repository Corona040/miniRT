/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:52:23 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/28 17:13:52 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	fail_malloc = false;
int	status = SUCCESS;

int	tests_run = 0;

int	ft_test_env(unit_test test)
{
	char	buf[32];
	int		exit_code;
	int		wstatus;

	memset(buf, 0, 32);
	if (fork() == 0) {
		exit_code = test();
		exit(exit_code);
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else {
		sprintf(buf, YELLOW"%-5s ", " O-O ");
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	return (CRASH);
}

int	unit_test_suite(test_suite tests)
{
	while (*tests)
		_ft_weakVerify((*(tests++)));
	return (status);
}

char	*expected_files[] = {
	"isalpha",
	"isdigit",
	"isalnum",
	"isascii",
	"isprint",
	"toupper",
	"tolower",
	"strlen",
	"strchr",
	"strrchr",
	"strncmp",
	"memcmp",
	"memset",
	"memchr",
	"memcmp",
	"bzero",
	"memcpy",
	"memmove",
	"strnstr",
	"strlcpy",
	"strlcat",
	"atoi",
	"calloc",
	"strdup",
	"substr",
	"strjoin",
	"strtrim",
	"split",
	"itoa",
	"strmapi",
	"striteri",
	"putchar_fd",
	"putstr_fd",
	"putendl_fd",
	"putnbr_fd",
	"lstnew",
	"lstadd_front",
	"lstsize",
	"lstlast",
	"lstadd_back",
	"lstdelone",
	"lstclear",
	"lstiter",
	"lstmap",
	NULL
};

test_suite	*test_suites[] = {
	&isalpha_tests,
	&isdigit_tests,
	&isalnum_tests,
	&isascii_tests,
	&isprint_tests,
	&toupper_tests,
	&tolower_tests,
	&strlen_tests,
	&strchr_tests,
	&strrchr_tests,
	&strncmp_tests,
	&memcmp_tests,
	&memset_tests,
	&memchr_tests,
	&memcmp_tests,
	&bzero_tests,
	&memcpy_tests,
	&memmove_tests,
	&strnstr_tests,
	&strlcpy_tests,
	&strlcat_tests,
	&atoi_tests,
	&calloc_tests,
	&strdup_tests,
	&substr_tests,
	&strjoin_tests,
	&strtrim_tests,
	&split_tests,
	&itoa_tests,
	&strmapi_tests,
	&striteri_tests,
	&putchar_fd_tests,
	&putstr_fd_tests,
	&putendl_fd_tests,
	&putnbr_fd_tests,
	&lstnew_tests,
	&lstadd_front_tests,
	&lstsize_tests,
	&lstlast_tests,
	&lstadd_back_tests,
	&lstdelone_tests,
	&lstclear_tests,
	&lstiter_tests,
	&lstmap_tests,
	NULL
};

int	iterate_suite(char	*lookup)
{
	int		match = false;
	int		result;
	char	file_buf[256];

	result = 0;
	for (int i = 0; expected_files[i]; i++) {
		if (!lookup || !strcmp(expected_files[i], lookup)) {
			printf(DFLT"\n%-15s - ", expected_files[i]);
			fflush(stdout);
			memset(file_buf, 0, 256);
			sprintf(file_buf, "../ft_%s.c",expected_files[i]);
			if (access(file_buf, F_OK) == 0 && test_suites[i])
				result += unit_test_suite(*(test_suites[i]));
			else
				printf(RED"MISSING");
			match = true;
		}
	}
	if (!match && lookup)
		printf(DFLT"\n%-20s - "YELLOW"UNRECOGNIZED", lookup);
	return (result);
}

int	main(int argc, char **argv)
{
	int		result = 0;

	if (argc > 1)
		for (int i = 1; i < argc; i++)
			result = iterate_suite(argv[i]);
	else
		result = iterate_suite(NULL);

	if (result == 0)
		printf(GREEN"\nPASSED\n");
	else
		printf(RED"\nFAILED: %d\n", status);
	printf(DFLT"Tests run: %d\n", tests_run);

	return (result);
}
