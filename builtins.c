/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:53:24 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/06/15 20:30:42 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int run_cd(char *path)
{
    if (chdir(path) != 0)
    {
        write(STDERR_FILENO, "Error\n", 6);
        return (1);
    }
    run_pwd();
    return (0);
}

int run_echo(char **string)
{
    int i;
    int k;

    i = 2;
    if (string[2] == NULL)
    {
        write(STDOUT_FILENO, "\n", 1);
        return (0);
    }
    if (ft_strcmp(string[2], "-n") == 0)
        i++;
    while (string[i] != NULL)
    {
        k = 0;
        while (string[i][k] != '\0')
        {
            write(STDOUT_FILENO, &string[i][k], 1);
            k++;
        }
        if (string[i + 1] != NULL)
            write(STDOUT_FILENO, " ", 1);
        i++;
    }
    if (ft_strcmp(string[2], "-n") != 0) //adding flag
        write(STDOUT_FILENO, "\n", 1);
    return (0);
}

int run_pwd(void)
{
    char *wd;
    char buff[PATH_MAX + 1];
    int i;

    wd = getcwd(buff, PATH_MAX + 1);
    if (wd != NULL)
    {
        i = 0;
        while (wd[i] != '\0')
        {
            write(STDOUT_FILENO, &wd[i], 1);
            i++;
        }
    }
    return (0);
}

int what_builtin(char *argv)
{
    char **arguments;

    arguments = ft_split(argv,' ');
    if (ft_strcmp(arguments[0], "echo") == 0)
        run_echo(arguments);
    if (ft_strcmp(arguments[0], "pwd") == 0)
        run_pwd();
    if (ft_strcmp(arguments[0], "cd") == 0)
        run_cd(arguments[1]);
    return (0);
}
