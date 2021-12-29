#include <string.h>
#include <utils.h>
#include <stdio.h>
#include <input.h>

InputBuffer* new_input_buffer(){
	InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;

	return input_buffer;
}

void prompt() { printf(">>> "); }

void read_input(InputBuffer* buffer) {
  ssize_t bytes_read =
      getline(&(buffer->buffer), &(buffer->buffer_length), stdin);

  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  // Ignore trailing newline
  buffer->input_length = bytes_read - 1;
  buffer->buffer[bytes_read - 1] = 0;
}

MetaCommandResult metaCommand(InputBuffer* buffer) {
  if (strcmp(buffer->buffer, ":exit") == 0) {
    gray();
    printf("👋 Bye!\n");
    reset();
    exit(EXIT_SUCCESS);
  } else if(strcmp(buffer->buffer, ":help") == 0){
	  printf(":break\tSometimes you get stuck, this gets you out\n");
	  printf(":clear\tAlias for break\n");
	  printf(":exit\tExit the REPL\n");
	  printf(":help\tPrint this help message\n");
	  printf(":save\tSave all evaluated commands in this REPL session to a file\n\n");
    printf("Press Ctrl+C to abort current expression, Ctrl+D to exit the REPL\n");
	  return META_COMMAND_SUCCESS;
  }
  else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}