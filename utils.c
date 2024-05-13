#include <string.h>
#include <stdlib.h>
#include "cwalk.h"
#include "chibicc.h"

char *dirname(char *path) {
    size_t where;
    cwk_path_get_dirname(path, &where);
    path[where] = '\0';
    return path;
}

char* strndup(const char *str, size_t len) {
    char *new = malloc((len + 1) * sizeof(char));
    memcpy(new, str, len + 1);
    return new;
}

const char *basename(char *path) {
    const char *new;
    size_t len;
    cwk_path_get_basename(path, &new, &len);
    (void) len;
    return new;
}
