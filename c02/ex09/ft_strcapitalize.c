/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atay <atay@42kl.edu.my>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:20:53 by atay              #+#    #+#             */
/*   Updated: 2023/09/21 08:20:54 by atay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_num(char str)
{
	if (str < '0' || str > '9')
	{
		return (0);
	}
	return (1);
}

int	is_low(char str)
{
	if (str < 'a' || str > 'z')
	{
		return (0);
	}
	return (1);
}

int	is_up(char str)
{
	if (str < 'A' || str > 'Z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	*head;

	head = str;
	i = 0;
	while (*head && head[i])
	{
		if (head[i] && !(is_low(head[i]) || is_up(head[i]) || is_num(head[i])))
		{
			head = head + i + 1;
			i = 0;
		}
		else
		{
			if (is_low(head[0]))
				head[0] = head[0] - 'a' + 'A';
			else if (i > 0 && is_up(head[i]))
				head[i] = head[i] - 'A' + 'a';
			i++;
		}
	}
	return (str);
}
