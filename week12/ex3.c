#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    char *typeClick[3] = {
        "RELEASED",
        "PRESSED ",
    };
    struct input_event ev;
    ssize_t n;
    int fd;

    fd = open(dev, O_RDONLY);
    if (fd == -1)
    {
        printf("Exuecute program with sudo");
        return 0;
    }

    char s[1024];
    for (int i = 0; i < 1024; ++i)
    {
        s[i] = '\0';
    }

    while (1)
    {
        n = read(fd, &ev, sizeof(ev));

        if (n == (ssize_t)-1 && errno != EINTR)
        {
            break;
        }
        else if (n != sizeof ev)
        {
            break;
        }

        if (ev.type == EV_KEY)
        {
            if (ev.value == 0)
            {
                if (ev.code == 46)
                {
                    strcat(s, "C\0");
                }
                else if (ev.code == 30)
                {
                    strcat(s, "A\0");
                }
                else if (ev.code == 25)
                {
                    strcat(s, "P\0");
                }
                else if (ev.code == 18)
                {
                    strcat(s, "E\0");
                }
                else
                {
                    strcat(s, "N\0");
                }
            }
            else
            {
                for (int i = 0; i < 1024; ++i)
                {
                    s[i] = '\0';
                }
            }
            
            if (strcmp(s, "PAC") == 0)
            {
                printf("Get some cappuccino!");
            }
            if (strcmp(s, "PE") == 0)
            {
                printf("I passed the Exam!");
            }
        }
    }

    return 0;
}