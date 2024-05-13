#include <string.h>
#include <stdlib.h>
#include "chibicc.h"

char* strndup(const char *str, size_t len) {
    char *new = malloc((len + 1) * sizeof(char));
    memcpy(new, str, len + 1);
    return new;
}

static const char *last(const char *src, char c) {
    const char *res = strrchr(src, c);
    if (res == NULL)
        return src;
    return res;
}

// string up to but not including final slash
char *dirname(const char *path) {
    const char *where = last(path, '/');
    where = last(where, '\\');
    return strndup(path, where - path);
}
// string after last slash 
const char *basename(const char *path) {
    path = last(path, '/');
    path = last(path, '\\');
    path ++;
    return path;
}
