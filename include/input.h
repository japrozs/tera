#include <stdio.h>
#include <stdlib.h>

#ifndef INPUT_H
#define INPUT_H

typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

InputBuffer* new_input_buffer();
void prompt();
void read_input(InputBuffer* buffer);
MetaCommandResult metaCommand(InputBuffer* buffer);

#endif