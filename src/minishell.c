/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/27 14:02:29 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
void	parse_input(char *input)
{
	int		i;
	char	**in_tab;
	t_tok	*token_tab;

	i = 0;
	in_tab = ft_split(input, ' ');
	while (in_tab[i])
		i++;
	if (!(token_tab = malloc(sizeof(t_tok) * (i + (i - 1)))))
		return ; 
	i = 0;
	while (in_tab[i])
	{
		printf("%s\n", in_tab[i]);
		i++;
	}

}*/


int main(int ac, char **av, char **envp)
{
	char	*input;
	char	**my_path;
	int		i;

	(void)ac;
	(void)av;
	my_path = get_path(get_env(envp));
	i = 0;
	/*while (my_path[i])
	{
		printf("%s\n", my_path[i]);
		i++;
	}*/
    while(1)
    {
		printf("My_prompt> ")
		input = get_next_line(0);
		//printf("%s", input);
		//printf("%s", get_next_line(0));
    }
	return (0);
}
