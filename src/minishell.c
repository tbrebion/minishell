/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/26 12:17:45 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

# include <readline/readline.h>
# include <readline/history.h>


# include <stdio.h>
/*
t_tok	*parse_input(char *input)
{
	int		i;
	char	**in_tab;
	t_tok	*token_tab;

	i = 0;
	in_tab = ft_split(input, ' ');
	while (in_tab[i])
		i++;
	if (!(token_tab = malloc(sizeof(t_tok) * (i + (i - 1)))))
		return (NULL); // ft_exit ??
	return (token_tab);
}*/

int main(void)
{
    //char    buffer[BUFF_SIZE];

    while(1)
    {
        printf("<Prompt>:");
        //scanf("%s",buffer);
        printf("%s\n", readline("test >"));
        /*if (ft_strncmp("exit", buffer, 4)==0)
            exit(0);
        else
            printf("Commande inconnue ...\n");*/
    }
	return (0);
}
