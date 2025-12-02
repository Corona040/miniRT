/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tests.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 00:22:58 by ecorona-          #+#    #+#             */
/*   Updated: 2024/10/26 15:55:25 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef int(*unit_test)(void);
typedef unit_test test_suite[];

extern test_suite	isalpha_tests;
extern test_suite	isdigit_tests;
extern test_suite	isalnum_tests;
extern test_suite	isascii_tests;
extern test_suite	isprint_tests;
extern test_suite	toupper_tests;
extern test_suite	tolower_tests;
extern test_suite	strlen_tests;
extern test_suite	strchr_tests;
extern test_suite	strrchr_tests;
extern test_suite	strncmp_tests;
extern test_suite	memcmp_tests;
extern test_suite	memset_tests;
extern test_suite	memchr_tests;
extern test_suite	bzero_tests;
extern test_suite	memcpy_tests;
extern test_suite	memmove_tests;
extern test_suite	strnstr_tests;
extern test_suite	strlcpy_tests;
extern test_suite	strlcat_tests;
extern test_suite	atoi_tests;
extern test_suite	calloc_tests;
extern test_suite	strdup_tests;
extern test_suite	substr_tests;
extern test_suite	strjoin_tests;
extern test_suite	strtrim_tests;
extern test_suite	split_tests;
extern test_suite	itoa_tests;
extern test_suite	strmapi_tests;
extern test_suite	striteri_tests;
extern test_suite	putchar_fd_tests;
extern test_suite	putstr_fd_tests;
extern test_suite	putendl_fd_tests;
extern test_suite	putnbr_fd_tests;
extern test_suite	lstnew_tests;
extern test_suite	lstadd_front_tests;
extern test_suite	lstsize_tests;
extern test_suite	lstlast_tests;
extern test_suite	lstadd_back_tests;
extern test_suite	lstdelone_tests;
extern test_suite	lstclear_tests;
extern test_suite	lstiter_tests;
extern test_suite	lstmap_tests;
