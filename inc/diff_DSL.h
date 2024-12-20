#ifndef DIFF_DSL_H_
#define DIFF_DSL_H_

#define  Num(amount     ) CreateDiffNode({.type = number   , .data = {.double_value   = amount   }}, NULL, NULL )
#define  Var(var_index  ) CreateDiffNode({.type = variable , .data = {.variable_index = var_index}}, NULL, NULL )
#define  Add(left, right) CreateDiffNode({.type = operation, .data = {.operation      = ADD      }}, left, right)
#define  Sub(left, right) CreateDiffNode({.type = operation, .data = {.operation      = SUB      }}, left, right)
#define  Mul(left, right) CreateDiffNode({.type = operation, .data = {.operation      = MUL      }}, left, right)
#define  Div(left, right) CreateDiffNode({.type = operation, .data = {.operation      = DIV      }}, left, right)
#define  Pow(left, right) CreateDiffNode({.type = operation, .data = {.operation      = POW      }}, left, right)
#define Sqrt(left       ) CreateDiffNode({.type = operation, .data = {.operation      = SQRT     }}, left, NULL )
#define  Sin(left       ) CreateDiffNode({.type = operation, .data = {.operation      = SIN      }}, left, NULL )
#define  Cos(left       ) CreateDiffNode({.type = operation, .data = {.operation      = COS      }}, left, NULL )
#define   Ln(left       ) CreateDiffNode({.type = operation, .data = {.operation      = LN       }}, left, NULL )
#define  Exp(left       ) CreateDiffNode({.type = operation, .data = {.operation      = EXP      }}, left, NULL )

#endif
