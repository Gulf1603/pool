/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hle-hena <hle-hena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:17:19 by hle-hena          #+#    #+#             */
/*   Updated: 2024/07/22 18:33:39 by hle-hena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i ++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		i ++;
	}
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		write(1, &base[nbr % len], 1);
	}
	else
		write(1, &base[nbr % len], 1);
}

int main()
{
	ft_putnbr_base(-255, "0123456789");
}