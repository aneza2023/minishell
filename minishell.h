/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:38:30 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/06/20 15:47:23 by ahavrank         ###   ########.fr       */
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


int what_builtin(char *argv, char *envp[]);
int run_pwd(void);
int run_echo(char **string);
int run_env(char *envp[]);
int run_exit(void);
int run_export(char *envp[], char *arguments);

//libft_later
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int	ft_numstrings(const char *s, int c);
unsigned int	findend(const char *s, int c, int i);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif