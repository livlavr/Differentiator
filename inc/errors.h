#ifndef ERRORS_H_
#define ERRORS_H_

enum TypeOfError {
    SUCCESS         = 0,
    POINTER_IS_NULL = 1,
    DOUBLE_IS_NAN   = 1 << 1,
    FILE_OPEN_ERROR = 1 << 2,
    FILE_READ_ERROR = 1 << 3,
    STAT_ERROR      = 1 << 4,
    CALLOC_ERROR    = 1 << 5,
    PROGRAM_ERROR   = 1 << 6
};

#endif