#include <stdio.h>
#include <syslog.h>

int main(int argc, char const *argv[])
{
    openlog(NULL, 0, LOG_USER);
    int ret = 0;
    if (argc < 3) {
        syslog(LOG_ERR, "Invalig number of arguments: %d. The program is called with PATH and STRING as its two arguments", argc);
        ret = 1;
        goto too_few_arguments;
    }
    FILE* write_file = fopen(argv[1], "w+");
    if (write_file == NULL){
        syslog(LOG_ERR, "Could not create file '%s'", argv[1]);
        ret = 1;
        goto fopen_failed;
    }
    syslog(LOG_DEBUG, "Writting <%s> to <%s>", argv[2], argv[1]);
    int num_printed = fprintf(write_file, "%s", argv[2]);
    if (num_printed < 0) {
        syslog(LOG_ERR, "Could not write string '%s' to the file '%s'", argv[2], argv[1]);
        ret = 1;
        goto fprintf_failed;
    } 

fprintf_failed:
    fclose(write_file);
fopen_failed:
too_few_arguments:
    closelog();
    return ret;
}
