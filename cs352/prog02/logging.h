#ifndef _LOGGING_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define DEBUG_LOG_STR " [DEBUG]"
#define INFO_LOG_STR  "  [INFO]"
#define WARN_LOG_STR  "  [WARN]"
#define ERROR_LOG_STR " [ERROR]"

#define LOG_LEVEL_DEBUG  0x00
#define LOG_LEVEL_INFO   0x01
#define LOG_LEVEL_WARN   0x02
#define LOG_LEVEL_ERROR  0x03

#ifndef PROGRAM_LOG_LEVEL
    #define PROGRAM_LOG_LEVEL 0x03
#endif

#define debug(log_message, args...)  printlog(LOG_LEVEL_DEBUG, log_message, ## args)
#define info(log_message,  args...)  printlog(LOG_LEVEL_INFO,  log_message, ## args)
#define warn(log_message,  args...)  printlog(LOG_LEVEL_WARN,  log_message, ## args)
#define error(log_message, args...)  printlog(LOG_LEVEL_ERROR, log_message, ## args)


typedef struct {
    char * filepath;
    char * program;
    FILE * logfile;
} Log;

extern Log * context;

char * log_header(int log_level);

/*!
 * Initialize the logging context
 * @param program a string name for the context
 * @return Log type
 */
Log * logging_init(const char * program);

/*!
 * Shutdown logging. You usually want to do this whenever your program is exiting.
 * @param the context you had running
 */
void logging_dest(Log * context);

/*!
 * Outputs a message to the appropriate log with information.
 *
 * @param log_level integer representing the level to log
 * @param message to write to the log
 * @return 1 if the log was successfully written
 */
int printlog(int log_level, char * fmt, ...);


#endif
