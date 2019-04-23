/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   6_resolve_options.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 16:24:34 by vicaster     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/16 18:34:19 by vicaster    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../ft_printf.h"

t_stru	ft_resolve_plus(t_stru stru, long long nb)
{
	int		i;
	int		j;
	char	tmp[BUFF_SIZE_PRINTF];

	nb = 0; //bypass error long long nb
	i = 1;
	j = 0;
	ft_strcpy(tmp, stru.buff);
	stru.buff[0] = '+';
	while (tmp[j])
		stru.buff[i++] = tmp[j++];
	stru.buff[i] = '\0';
	return (stru);
}

t_stru	ft_resolve_esp(t_stru stru, long long nb)
{
	int		i;
	int		j;
	char	tmp[BUFF_SIZE_PRINTF];

	i = 1;
	j = 0;
	ft_strcpy(tmp, stru.buff);
	stru.buff[0] = ' ';
	while (tmp[j])
		stru.buff[i++] = tmp[j++];
	stru.buff[i] = '\0';
	return (stru);
}

t_stru	ft_resolve_preci_string(t_stru stru, long long nb)
{
	int		i;
	int		j;
	char	tmp[BUFF_SIZE_PRINTF];

	i = 0;
	j = 0;
	ft_strcpy(tmp, stru.buff);
	stru = ft_countpreci(stru, nb);
	if (stru.count > 0 && stru.type != 's')
	{
		while (stru.count-- > 0)
			stru.buff[i++] = '0';
		if (nb < 0)
			stru.buff[i++] = '0';
		while (tmp[j])
			stru.buff[i++] = tmp[j++];
	}
	if (stru.count >= 0 && stru.type == 's')
	{
		ft_bzero(stru.buff, ft_strlen(stru.buff));
		while (stru.count-- > 0)
			stru.buff[i++] = tmp[j++];
	}
	stru.buff[i] = '\0';
	stru = ft_swap_plus(stru, nb);
	return (stru);
}

t_stru	ft_resolve_preci_int(t_stru stru, long long nb)
{
	int		i;
	int		j;
	char	tmp[BUFF_SIZE_PRINTF];

	i = 0;
	j = 0;
	ft_strcpy(tmp, stru.buff);
	stru = ft_countpreci(stru, nb);
	if (nb < 0)
		stru.buff[i++] = '-';
	while (stru.count > 0)
	{
		stru.buff[i++] = '0';
		stru.count--;
	}
	if (nb < 0)
		j++;
	while (tmp[j])
		stru.buff[i++] = tmp[j++];
	return (stru);
}