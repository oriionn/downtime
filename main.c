/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:24:18 by rgodet            #+#    #+#             */
/*   Updated: 2025/06/26 00:25:50 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utils.h"

void	print_date(long uptime, char is_long)
{
	int				rest;
	int				days;
	int				hours;
	int				minutes;
	int				seconds;

	days = uptime / 86400;
	rest = uptime % 86400;
	hours = rest / 3600;
	rest = rest % 3600;
	minutes = rest / 60;
	seconds = rest % 60;
	if (days != 0 || is_long)
		printf("%d jours", days);
	print_separator(minutes == 0 || is_long);
	if (hours != 0 || is_long)
		printf("%d heures", hours);
	print_separator(seconds == 0 || is_long);
	if (minutes != 0 || is_long)
		printf("%d minutes", minutes);
	if (seconds || is_long)
		print_separator(1);
	if (seconds != 0 || is_long)
		printf("%d secondes", seconds);
	printf("\n");
}

void	print_since(long uptime)
{
	time_t			current;
	time_t			up;
	time_t			start;
	struct tm		*localstart;

	time(&current);
	up = (time_t) uptime;
	start = difftime(current, up);
	localstart = localtime(&start);
	printf("%02d/%02d/%4d %02d:%02d:%02d\n", localstart->tm_mday,
		localstart->tm_mon + 1, localstart->tm_year + 1900, localstart->tm_hour,
		localstart->tm_min, localstart->tm_sec);
}

int	print_help(void)
{
	printf("\nUsage:\n  downtime [options]\n\nOptions: \n  -l, --long  affiche "
		"les valeurs même si elles sont à 0\n  -s, --since affiche la date et l"
		"'heure de démarrage de la machine \n  -r, --raw   affiche l'uptime en "
		"donnée brute (nombre de secondes depuis le démarrage de la machine) \n"
		"  -h, --help  affiche cette aide\n\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	unsigned char	is_long;
	int				i;

	i = 1;
	is_long = 0;
	while (i < argc)
	{
		if (strcmp(argv[i], "--long") == 0 || strcmp(argv[i], "-l") == 0)
			is_long = 1;
		else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
			return (print_help());
		else if (strcmp(argv[i], "--since") == 0 || strcmp(argv[i], "-s") == 0)
		{
			print_since(get_uptime());
			return (0);
		}
		else if (strcmp(argv[i], "--raw") == 0 || strcmp(argv[i], "-r") == 0)
		{
			printf("%ld\n", get_uptime());
			return (0);
		}
		i++;
	}
	print_date(get_uptime(), is_long);
	return (0);
}
