/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
/*   Updated: 2022/04/29 18:11:46 by tbrebion         ###   ########.fr       */
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
	//char	**my_path;
	//int		i;

	(void)ac;
	(void)av;
	(void)envp;
	//my_path = get_path(get_env(envp));
    while(1)
	{
		display_prompt();
		ft_putstr(" \033[31m︻\033[0m\033[32m┳\033[0m\033[33mデ");

		input = get_next_line(0);
    }
	return (0);
}
