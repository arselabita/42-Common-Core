/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abita <abita@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:22:01 by abita             #+#    #+#             */
/*   Updated: 2025/04/25 22:22:03 by abita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *s, int c)
{
	int		i;
	const char	*temp;
	char	ch = (char)c;

	i = 0;
	temp = 0;
	while (s[i])
	{
		if(s[i] == ch)
			temp = &s[i];
		i++;
	}
	if(ch == '\0')
		return (char *)&s[i];
	return (char *)temp;
}
