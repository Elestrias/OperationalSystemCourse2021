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

        if (ev.type == EV_KEY && (ev.value == 0 || ev.value == 1))
        {
            printf("%s 0x%04x (%d)\n", typeClick[ev.value], (int)ev.code, (int)ev.code);
        }
    }

    return 0;
}