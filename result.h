#ifndef RESULT_H
#define RESULT_H

#include <stdlib.h>

enum HRet{
    success,
    memory,
    socket_failed,
    connect_failed,
    send_failed,
    recv_failed,
    other
};
#endif
