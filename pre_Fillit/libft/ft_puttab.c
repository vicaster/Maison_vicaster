/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puttab.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 13:13:31 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 17:16:11 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab, size_t size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		i++;
	}
}
