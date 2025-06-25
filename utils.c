/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:23:55 by rgodet            #+#    #+#             */
/*   Updated: 2025/06/26 00:30:52 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include <mach/mach_time.h>
#endif
#ifdef __unix__
# include <sys/sysinfo.h>
#endif
#include <stdint.h>
#include <stdio.h>

#ifdef __APPLE__

long	get_uptime(void)
{
	uint64_t					absolute_time;
	mach_timebase_info_data_t	timebase_info;

	mach_timebase_info(&timebase_info);
	absolute_time = mach_absolute_time();
	return ((absolute_time * timebase_info.numer)
		/ (timebase_info.denom * 1000000000));
}
#endif

#ifdef __unix__

long	get_uptime(void)
{
	struct sysinfo	info;

	sysinfo(&info);
	return (info.uptime);
}

#endif

void	print_separator(int condition)
{
	if (condition)
		return ((void) printf(" et "));
	printf(", ");
}
