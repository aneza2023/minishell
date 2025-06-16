/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:15:23 by anezkahavra       #+#    #+#             */
/*   Updated: 2025/06/15 20:43:21 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    char *promt;

    while (1)
    {
        promt = readline("");
        what_builtin(promt);
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