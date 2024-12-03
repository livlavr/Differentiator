#ifndef DIFF_DSL_H_
#define DIFF_DSL_H_

#include "diff.h"

#define Num(amount     ) CreateDiffNode({.type = number   , .data = {.double_value   = amount   }}, NULL, NULL)
#define Var(var_index  ) CreateDiffNode({.type = variable , .data = {.variable_index = var_index}}, NULL, NULL)
#define Add(left, right) CreateDiffNode({.type = operation, .data = {.operation      = ADD      }}, left, right)
#define Sub(left, right) CreateDiffNode({.type = operation, .data = {.operation      = SUB      }}, left, right)
#define Mul(left, right) CreateDiffNode({.type = operation, .data = {.operation      = MUL      }}, left, right)
#define Div(left, right) CreateDiffNode({.type = operation, .data = {.operation      = DIV      }}, left, right)

#endif
