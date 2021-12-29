#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <utils.h>
#include <stdint.h>
#include <stdbool.h>
#include <statement.h>

PrepareResult prepare_statement(InputBuffer* buffer, Statement* stmt) {
	if (strncmp(lower(buffer->buffer, strlen(buffer->buffer)), "set", 3) == 0) {
		stmt->type = STATEMENT_INSERT;
		return PREPARE_SUCCESS;
	}
	if (strncmp(lower(buffer->buffer, strlen(buffer->buffer)), "get", 3) == 0) {
		stmt->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}	
	if (strncmp(lower(buffer->buffer, strlen(buffer->buffer)), "del", 3) == 0) {
		stmt->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}	
	return PREPARE_UNRECOGNIZED_STATEMENT;
}


void execute_statement(Statement* stmt) {
  switch (stmt->type) {
    case (STATEMENT_INSERT):
      printf("This is where we would do an insert.\n");
      break;
    case (STATEMENT_SELECT):
      printf("This is where we would do a select.\n");
      break;
    case (STATEMENT_DELETE):
      printf("This is where we would do a delete.\n");
      break;
  }
}