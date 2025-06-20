/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:53:24 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/06/20 15:18:45 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int run_cd(char *path) //issues with absolute path?
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
        write(STDOUT_FILENO, "\n", 1);
    }
    return (0);
}

int run_env(char *envp[])
{
    int i;

    i = 0;
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
    return (0);
}

int run_exit(void)
{
    exit(0);
}

int run_export(char *envp)
{
    setenv(name, value, 0); //if not 0 and name already exists, overwrites name
    return (0);
    //check if added correctly, in shell by abc
}

int what_builtin(char *argv, char *envp[])
{
    char **arguments;

    arguments = ft_split(argv,' ');
    if (ft_strcmp(arguments[0], "echo") == 0)
        run_echo(arguments);
    if (ft_strcmp(arguments[0], "pwd") == 0)
        run_pwd();
    if (ft_strcmp(arguments[0], "cd") == 0)
        run_cd(arguments[1]);
    if (ft_strcmp(arguments[0], "env") == 0)
        run_env(envp);
    if (ft_strcmp(arguments[0], "exit") == 0)
        run_exit();
    if (ft_strcmp(arguments[0], "export") == 0)
        run_export(envp);
    // if (ft_strcmp(arguments[0], "unset") == 0)
    //     run_unset();
    return (0);
}
