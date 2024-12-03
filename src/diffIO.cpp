#include <stdio.h>

#include "tree.h"
#include "color_printf.h"
#include "diff.h"

TreeNode<DifferentiatorValue>* GetG(const char* s, size_t* p) {
    TreeNode<DifferentiatorValue>* val = GetE(s, p);
    if(s[*p] != '\0')
        SyntaxError(__LINE__);
    (*p)++;
    return val;
}

TreeNode<DifferentiatorValue>* GetE(const char* s, size_t* p) {
    TreeNode<DifferentiatorValue>* val1   = GetT(s, p);
    TreeNode<DifferentiatorValue>* result = val1;
    TreeNode<DifferentiatorValue>* val2   = NULL;

    while (s[*p] == '+' || s[*p] == '-') {
        int op = s[*p];
        (*p)++;
        val2 = GetT(s, p);
        if(op == '+') result = Add(val1, val2);
        else          result = Sub(val1, val2);
    }
    SkipSpaces(s, p);
    return result;
}

TreeNode<DifferentiatorValue>* GetT(const char* s, size_t* p) {
    TreeNode<DifferentiatorValue>* val1   = GetP(s, p);
    TreeNode<DifferentiatorValue>* result = val1;
    TreeNode<DifferentiatorValue>* val2   = NULL;

    while (s[*p] == '*' || s[*p] == '/') {
        int op = s[*p];
        (*p)++;
        val2  = GetP(s, p);
        if(op == '*') result = Mul(val1, val2);
        else          result = Div(val1, val2);
    }
    SkipSpaces(s, p);
    return result;
}

TreeNode<DifferentiatorValue>* GetP(const char* s, size_t* p) {
    SkipSpaces(s, p);
    if(s[*p] == '('){
        (*p)++;
        SkipSpaces(s, p);
        TreeNode<DifferentiatorValue>* val = GetE(s, p);
        if(s[*p] != ')')
            SyntaxError(__LINE__);
        (*p)++;
        SkipSpaces(s, p);
        return val;
    }
    else
        return GetN(s, p);
}

TreeNode<DifferentiatorValue>* GetN(const char* s, size_t* p) {
    SkipSpaces(s, p);
    double amount = 0;
    size_t start  = *p;
    while('0' <= s[*p] && s[*p] <= '9') {
        amount = amount * 10 + (s[*p] - '0');
        (*p)++;
        SkipSpaces(s, p);
    }
    if(start == *p)
        SyntaxError(__LINE__);
    SkipSpaces(s, p);
    return Num(amount);
}

void SyntaxError(int line){
    color_printf(RED_COLOR, BOLD, "BRUUUUH Syntax Error in %d\n", line);
    exit(0);
}

void SkipSpaces(const char* s, size_t* p) {
    while(s[*p] == ' ') {
        (*p)++;
    };
}


// #include <stdio.h>
//
// #include "tree.h"
// #include "diff.h"
// #include "color_printf.h"
//
// int  GetG        (const char* s, size_t* p);
// int  GetE        (const char* s, size_t* p);
// int  GetT        (const char* s, size_t* p);
// int  GetN        (const char* s, size_t* p);
// int  GetP        (const char* s, size_t* p);
// void SkipSpaces  (const char* s, size_t* p);
// void SyntaxError (int line                );
//
// const char* s = "";
//
// int main() {
//     size_t p = 0;
//     printf("%d", GetG(s, &p));
// }
//
// int GetG(const char* s, size_t* p) {
//     int val = GetE(s, p);
//     if(s[*p] != '\0')
//         SyntaxError(__LINE__);
//     (*p)++;
//     return val;
// }
//
// int GetE(const char* s, size_t* p) {
//     int val = GetT(s, p);
//     while (s[*p] == '+' || s[*p] == '-') {
//         int op = s[*p];
//         (*p)++;
//         int val2 = GetT(s, p);
//         if(op == '+') val += val2;
//         else          val -= val2;
//     }
//     SkipSpaces(s, p);
//     return val;
// }
//
// int GetT(const char* s, size_t* p) {
//     int val = GetP(s, p);
//     while (s[*p] == '*' || s[*p] == '/') {
//         int op = s[*p];
//         (*p)++;
//         int val2 = GetP(s, p);
//         if(op == '*') val *= val2;
//         else          val /= val2;
//     }
//     SkipSpaces(s, p);
//     return val;
// }
//
// int GetP(const char* s, size_t* p) {
//     SkipSpaces(s, p);
//     if(s[*p] == '('){
//         (*p)++;
//         SkipSpaces(s, p);
//         int val = GetE(s, p);
//         if(s[*p] != ')')
//             SyntaxError(__LINE__);
//         (*p)++;
//         SkipSpaces(s, p);
//         return val;
//     }
//     else
//         return GetN(s, p);
// }
//
// int GetN(const char* s, size_t* p) {
//     SkipSpaces(s, p);
//     int    val   = 0;
//     size_t start = *p;
//     while('0' <= s[*p] && s[*p] <= '9') {
//         val = val*10 + (s[*p] - '0');
//         (*p)++;
//         SkipSpaces(s, p);
//     }
//     if(start == *p)
//         SyntaxError(__LINE__);
//     SkipSpaces(s, p);
//     return val;
// }
//
// void SyntaxError(int line){
//     color_printf(RED_COLOR, BOLD, "BRUUUUH Syntax Error in %d\n", line);
//     exit(0);
// }
//
// void SkipSpaces(const char* s, size_t* p) {
//     while(s[*p] == ' ') {
//         (*p)++;
//     };
// }
