/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/26 14:54:30 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


void/*t_tok	**/parse_input(char *input)
{
	int		i;
	int		j;
	int		k;
	char	**in_tab;
	t_tok	*token_tab;

	i = 0;
	j = 0;
	k = 0;
	in_tab = ft_split(input, ' ');
	while (in_tab[i])
		i++;
	if (!(token_tab = malloc(sizeof(t_tok) * (i + (i - 1)))))
		return /*(NULL)*/; // ft_exit ??
	i = 0;
	while (in_tab[i])
	{
		printf("%s\n", in_tab[i]);
		i++;
	}
	
	//return (token_tab);
}


int main(void)
{
    char    buffer[BUFF_SIZE];
	t_tok	*tok;
	int		i = 0;

    while(1)
    {
        printf("<Prompt>:");
        scanf("%s", buffer);
		/*tok = */parse_input(buffer);
		/*while (tok[i].val)
		{
			printf("%s\n", tok->val);
			i++;
		}*/
        /*if (ft_strncmp("exit", buffer, 4)==0)
            exit(0);
        else
            printf("Commande inconnue ...\n");*/
		
    }
	return (0);
}
