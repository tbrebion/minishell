/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:19:38 by tbrebion          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/04/27 16:53:43 by tbrebion         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2022/04/27 15:55:36 by flcarval         ###   ########.fr       */
=======
/*   Updated: 2022/04/27 15:55:37 by tbrebion         ###   ########.fr       */
>>>>>>> 53bb4915498b595cbea21aa283a307fe815f7dae
>>>>>>> c29fb5c7be62259098cd6f685bf01e14543a720a
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
	//i = 0;
	/*while (my_path[i])
	{
		printf("%s\n", my_path[i]);
		i++;
	}*/
<<<<<<< HEAD
	while(1)
	{
		printf("My_prompt> ");
=======
    while(1)
	{
		ft_printf("My_prompt> ");
>>>>>>> 53bb4915498b595cbea21aa283a307fe815f7dae
		input = get_next_line(0);
		ft_printf("%s", input);
<<<<<<< HEAD
    }
=======
		//printf("%s", get_next_line(0));
	}
>>>>>>> c29fb5c7be62259098cd6f685bf01e14543a720a
	return (0);
}
