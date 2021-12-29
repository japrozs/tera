#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <utils.h>
#include <tera.h>
#include <input.h>
#include <statement.h>

// constants throughout the software
const char* VERSION = "0.0.1";

int main(){
	InputBuffer* buffer = new_input_buffer();

	// intro message
	printf("Welcome to Tera v%s.\n", VERSION);
	printf("Type :help for more information.\n");

	while(true){
		prompt();
		read_input(buffer);
		if(buffer->buffer[0] == ':'){
			switch(metaCommand(buffer)){
				case (META_COMMAND_SUCCESS):
					continue;
				case (META_COMMAND_UNRECOGNIZED_COMMAND):
					printf("Unrecognized command '%s'\n", buffer->buffer + 1);
				continue;
			}
		}
		
		Statement stmt;
		switch (prepare_statement(buffer, &stmt)) {
			case (PREPARE_SUCCESS):
				break;
			case (PREPARE_SYNTAX_ERROR):
		        printf("Syntax error. Could not parse statement.\n");
		        continue;
			case (PREPARE_UNRECOGNIZED_STATEMENT):
				printf("Unrecognized keyword at start of '%s'.\n",
					buffer->buffer);
				continue;
		}
		gray();
		printf("👍 Executed successfully\n");
		reset();
	}

	return 0;
}