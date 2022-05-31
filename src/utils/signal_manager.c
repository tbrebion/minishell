/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:14:37 by tbrebion          #+#    #+#             */
/*   Updated: 2022/05/31 15:28:11 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sigint_handler(int signo) // CTRL+c
{
	if (signo == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		data.error_status = 130;
	}
}

void	sigquit_handler(int signo) // "CTRL+\"
{
	if (signo == SIGQUIT)
	{
		write(2, "\b\b  \b\b", 6);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	ctrld_handler(char *input) // "CTRL+d"
{
	if (input == NULL)
		exit(EXIT_SUCCESS);
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
