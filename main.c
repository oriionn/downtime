#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int rest, days;
    long uptime;
    char content[4][20];
    char totalContent[110] = "";
    unsigned char isLong = 0, i = 0, seconds, minutes, hours;

    struct sysinfo info;
    sysinfo(&info);
    uptime = info.uptime;

    for (int j = 0; j < argc; j++) {
        if (strcmp(argv[j], "--long") == 0 || strcmp(argv[j], "-l") == 0) {
            isLong = 1;
        } else if (strcmp(argv[j], "--help") == 0 || strcmp(argv[j], "-h") == 0) {
            printf("\nUsage:\n  downtime [options]\n\nOptions: \n  -l, --long  affiche les valeurs même si elles sont à 0\n  -s, --since affiche la date et l'heure de démarrage de la machine \n  -r, --raw   affiche l'uptime en donnée brute (nombre de secondes depuis le démarrage de la machine) \n  -h, --help  affiche cette aide\n\n");
            return 0;
        } else if (strcmp(argv[j], "--since") == 0 || strcmp(argv[j], "-s") == 0) {
            time_t current = time(NULL);
            time_t up = (time_t) uptime;
            time_t start = difftime(current, up);

            struct tm* localstart = localtime(&start);
            printf("%02d/%02d/%4d %02d:%02d:%02d\n", localstart->tm_mday, localstart->tm_mon+1, localstart->tm_year+1900, localstart->tm_hour, localstart->tm_min, localstart->tm_sec);
            return 0;
        } else if (strcmp(argv[j], "--raw") == 0 || strcmp(argv[j], "-r") == 0) {
            printf("%ld\n", uptime);
            return 0;
        }
    }

    days = uptime / 86400;
    rest = uptime % 86400;

    hours = rest / 3600;
    rest = rest % 3600;

    minutes = rest / 60;
    seconds = rest % 60;

    if (days != 0 || isLong == 1) {
        snprintf(content[i], sizeof(content[i]), "%d jours", days);
        i++;
    }

    if (hours != 0 || isLong == 1) {
        snprintf(content[i], sizeof(content[i]), "%d heures", hours);
        i++;
    }

    if (minutes != 0 || isLong == 1) {
        snprintf(content[i], sizeof(content[i]), "%d minutes", minutes);
        i++;
    }

    if (seconds != 0 || isLong == 1) {
        snprintf(content[i], sizeof(content[i]), "%d secondes", seconds);
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (strlen(content[j]) == 0) continue;

        if ((i - 1) == j) strcat(totalContent, " et ");
        else if (j != 0) strcat(totalContent, ", ");

        strcat(totalContent, content[j]);
    }

    printf("%s\n", totalContent);

    return 0;
}
