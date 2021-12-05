#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NEW_LINE_CHAR '\n'
#define NULL_CHAR     '\0'

//Maintaining Patterns in linked list with 
//following DS as Node type:
typedef struct um_ctx{
    struct um_ctx *next;
    char *pattern_str;
}um_ctx_t;

struct um_ctx *um_compile(const char **patterns);
int um_match(const struct um_ctx *ctx, const char *url, bool *results);
void um_free(struct um_ctx *ctx);