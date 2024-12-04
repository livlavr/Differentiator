#ifndef DIFFIO_H_
#define DIFFIO_H_

#include "diff.h"

TreeNode<DifferentiatorValue>* GetG(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetE(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetT(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetD(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetV(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetN(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetP(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetF(const char* s, size_t* p);
Operations ScanOperation           (const char* s, size_t* p);
void       SkipSpaces              (const char* s, size_t* p);
void       SyntaxError             (int line                );

#define IsSqrt(op) if(strcmp(op, operation_symbol[SQRT]) == 0) return SQRT
#define IsSin( op) if(strcmp(op, operation_symbol[SIN ]) == 0) return SIN
#define IsCos( op) if(strcmp(op, operation_symbol[COS ]) == 0) return COS
#define IsLn(  op) if(strcmp(op, operation_symbol[LN  ]) == 0) return LN
#define IsExp( op) if(strcmp(op, operation_symbol[EXP ]) == 0) return EXP

#define DetectOperation(op)\
    IsSqrt(op);\
    IsSin( op);\
    IsCos( op);\
    IsLn(  op);\
    IsExp( op);\
    else       \
        return UNDEF
#endif
