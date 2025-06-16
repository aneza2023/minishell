/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:38:30 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/06/15 20:34:24 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


int what_builtin(char *argv);
int run_pwd(void);
int run_echo(char **string);

//libft_later
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int	ft_numstrings(const char *s, int c);
unsigned int	findend(const char *s, int c, int i);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif