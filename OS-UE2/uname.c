#include <stddef.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <stdlib.h>

size_t length(char *str)
{
    int i = 0;
    while (str[i] != 0)
        i++;
    return i;
}

void putstr(char *str)
{
    size_t len = length(str);
    if (write(1, str, len) != (ssize_t)len)
        exit(1);
}

int main(void)
{
    struct utsname uname_data;
    if (uname(&uname_data) == -1) exit(1);

    putstr("Hostname: ");
    putstr(uname_data.nodename);
    putstr("\n");
    putstr("OS: ");
    putstr(uname_data.sysname);
    putstr("\n");
    putstr("Version: ");
    putstr(uname_data.version);
    putstr("\n");
    putstr("Release: ");
    putstr(uname_data.release);
    putstr("\n");
    return 0;
}