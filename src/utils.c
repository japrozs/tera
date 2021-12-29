#include <string.h>
#include <utils.h>
#include <string.h>

char* lower(char *str, size_t len){
    char *str_l = calloc(len+1, sizeof(char));

    for (size_t i = 0; i < len; ++i) {
        str_l[i] = tolower((unsigned char)str[i]);
    }
    return str_l;
}

void gray () {
  printf("\033[90m");
}
void reset () {
  printf("\033[0m");
}
