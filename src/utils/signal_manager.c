/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/30 19:28:36 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int signo) // CTRL+c
{
	if (signo == SIGINT)
	{
		data.exit = 1;
		free(g_input);
		g_input = ft_strdup("\n");
	}
}

void	sigquit_handler(int signo) // "CTRL+\"
{
	if (signo == SIGQUIT)
		return ;
}

void	ctrld_handler(char *input) // "CTRL+d"
{
	if (input == NULL)
		exit(EXIT_FAILURE);
}



/*
int	ft_sig_state(int *status, int get)
{
	static int	*state = (int *)0;

	if (status != NULL)
		state = status;
	if (get == 1)
		*state = 1;
	return (*state);

}
*/
/*char	*ft_get_addr(char **input)
{
	static int	*my_input_addr = (int *)0;

	if (input)
		my_input_addr = input;
	return (*my_input_addr);

// si str == null c'est la function siginnt_handler qui appelle
// si != ull je viens set l'adresse 
}*/
/*
char *ft_example(void)
{
	char *str = malloc(sizeof(char) * 42);

	ft_get_addr(str);


	// signal :: 

}*/