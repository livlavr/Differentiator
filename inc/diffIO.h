#ifndef DIFFIO_H_
#define DIFFIO_H_

#include "diff.h"

TreeNode<DifferentiatorValue>* GetG(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetE(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetT(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetN(const char* s, size_t* p);
TreeNode<DifferentiatorValue>* GetP(const char* s, size_t* p);
void SkipSpaces                    (const char* s, size_t* p);
void SyntaxError                   (int line                );

#endif
