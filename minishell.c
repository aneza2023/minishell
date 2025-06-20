/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:15:23 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/06/20 14:27:20 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *envp[]) // need to save envp somewhere for later use
{
    char *promt;

    while (1)
    {
        promt = readline("");
        what_builtin(promt, envp);
        add_history(promt);
    }
    return (0);
}

// int main(int argc, char *argv[])
// {
//     if (argc < 2)
//     {
//         write(STDERR_FILENO, "Error\n", 6);
//         return (1);
//     }
//     else
//         what_builtin(argv);
//     return (0);
// }