#include <stdio.h>
#include <string.h>
#include <sys/sysinfo.h>

int main(int argc, char *argv[]) {
    int rest, days, hours, minutes, seconds;
    int i = 0;
    long uptime;
    char content[4][20];
    char totalContent[110] = "";
    unsigned char isLong = 0;

    for (int j = 0; j < argc; j++) {
        if (strcmp(argv[j], "--long") == 0 || strcmp(argv[j], "-l") == 0) {
            isLong = 1;
        } else if (strcmp(argv[j], "--help") == 0 || strcmp(argv[j], "-h") == 0) {
            printf("\nUsage:\n  downtime [options]\n\nOptions: \n  -l, --long affiche les valeurs même si elles sont à 0\n  -h, --help affiche cette aide\n\n");
            return 0;
        }
    }

    struct sysinfo info;
    sysinfo(&info);
    uptime = info.uptime;

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

    for (int j = 0; j < 4; j++) {
        if (strlen(content[j]) == 0) continue;

        if ((i - 1) == j) strcat(totalContent, " et ");
        else if (j != 0) strcat(totalContent, ", ");

        strcat(totalContent, content[j]);
    }

    printf("%s\n", totalContent);

    return 0;
}
