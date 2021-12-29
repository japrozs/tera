#include <input.h>

#ifndef STATEMENT_H
#define STATEMENT_H

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT, PREPARE_SYNTAX_ERROR } PrepareResult;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT, STATEMENT_DELETE } StatementType;

typedef struct {
  StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* stmt);

#endif