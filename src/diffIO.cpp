#include <stdio.h>

#define NDEBUG

#include "tree.h"
#include "color_printf.h"
#include "diff.h"

TreeNode<DifferentiatorValue>* GetG(const char* s, size_t* p) { //TODO rename
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    TreeNode<DifferentiatorValue>* val = GetE(s, p);
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    if(s[*p] != '\0')
        SyntaxError(__LINE__);
    return val;
}

TreeNode<DifferentiatorValue>* GetE(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    TreeNode<DifferentiatorValue>* val1   = GetT(s, p);
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    TreeNode<DifferentiatorValue>* result = val1;
    TreeNode<DifferentiatorValue>* val2   = NULL;

    while (s[*p] == '+' || s[*p] == '-') {
        int op = s[*p];
        (*p)++;
        val2 = GetE(s, p);
        $DEBUG("%s", __func__);
        $DEBUG("%c", s[*p]);
        if(op == '+') result = Add(val1, val2);
        else          result = Sub(val1, val2);
    }
    SkipSpaces(s, p);
    return result;
}

TreeNode<DifferentiatorValue>* GetT(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    TreeNode<DifferentiatorValue>* val1   = GetD(s, p);
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    TreeNode<DifferentiatorValue>* result = val1;
    TreeNode<DifferentiatorValue>* val2   = NULL;

    while (s[*p] == '*' || s[*p] == '/') {
        int op = s[*p];
        (*p)++;
        val2  = GetT(s, p);
        $DEBUG("%s", __func__);
        $DEBUG("%c", s[*p]);
        if(op == '*') result = Mul(val1, val2);
        else          result = Div(val1, val2);
    }
    SkipSpaces(s, p);
    return result;
}

TreeNode<DifferentiatorValue>* GetD(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    TreeNode<DifferentiatorValue>* val1   = GetP(s, p);
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    TreeNode<DifferentiatorValue>* result = val1;
    TreeNode<DifferentiatorValue>* val2   = NULL;

    while (s[*p] == '^') {
        (*p)++;
        val2   = GetD(s, p);
        $DEBUG("%s", __func__);
        $DEBUG("%c", s[*p]);
        result = Deg(val1, val2);
    }
    SkipSpaces(s, p);
    return result;
}

TreeNode<DifferentiatorValue>* GetP(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    SkipSpaces(s, p);
    if(s[*p] == '('){
        (*p)++;
        SkipSpaces(s, p);
        TreeNode<DifferentiatorValue>* val = GetE(s, p);
        $DEBUG("%s", __func__);
        $DEBUG("%c", s[*p]);
        if(s[*p] != ')')
            SyntaxError(__LINE__);
        (*p)++;
        SkipSpaces(s, p);
        return val;
    }
    else
        return GetF(s, p);
}

TreeNode<DifferentiatorValue>* GetF(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    size_t start = *p;
    double amount = 0;
    Operations op = ScanOperation(s, p);
    TreeNode<DifferentiatorValue>* val = NULL;
    (*p)++;
    SkipSpaces(s, p);
    switch(op) {
        case SQRT:
            val = GetE(s, p);
            $DEBUG("%s", __func__);
            $DEBUG("%c", s[*p]);
            if(s[*p] != ')')
                SyntaxError(__LINE__);
            (*p)++;
            SkipSpaces(s, p);
            return Sqrt(val);

        case SIN:
            val = GetE(s, p);
            $DEBUG("%s", __func__);
            $DEBUG("%c", s[*p]);
            if(s[*p] != ')')
                SyntaxError(__LINE__);
            (*p)++;
            SkipSpaces(s, p);
            return Sin(val);

        case COS:
            val = GetE(s, p);
            $DEBUG("%s", __func__);
            $DEBUG("%c", s[*p]);
            if(s[*p] != ')')
                SyntaxError(__LINE__);
            (*p)++;
            SkipSpaces(s, p);
            return Cos(val);

        case LN:
            val = GetE(s, p);
            $DEBUG("%s", __func__);
            $DEBUG("%c", s[*p]);
            if(s[*p] != ')')
                SyntaxError(__LINE__);
            (*p)++;
            SkipSpaces(s, p);
            return Ln(val);

        case EXP:
            val = GetE(s, p);
            $DEBUG("%s", __func__);
            $DEBUG("%c", s[*p]);
            if(s[*p] != ')')
                SyntaxError(__LINE__);
            (*p)++;
            SkipSpaces(s, p);
            return Exp(val);

        case UNDEF:
            *p = start;
            return GetV(s, p);
        default:
            warning(false, PROGRAM_ERROR);
    }
}

Operations ScanOperation(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    SkipSpaces(s, p);
    char       operation[6] = "";
    size_t     op_index     = 0;
    Operations op;
    while(s[*p] != '(' && s[*p] != '\0' && op_index < 6) {
        operation[op_index] = s[*p];
        (*p)++;
        SkipSpaces(s, p);
        op_index++;
    }
    DetectOperation(operation);
}

TreeNode<DifferentiatorValue>* GetV(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    size_t number_of_var = sizeof(variable_table);
    for(size_t variable_number = 0; variable_number < number_of_var; variable_number++) {
        if(s[*p] == variable_table[variable_number]) {
            (*p)++;
            SkipSpaces(s, p);
            $DEBUG("%d", variable_number);
            return Var(variable_number);
        }
    }

    return GetN(s, p);
}

TreeNode<DifferentiatorValue>* GetN(const char* s, size_t* p) {
    $DEBUG("%s", __func__);
    $DEBUG("%c", s[*p]);
    SkipSpaces(s, p);
    double amount = 0;
    size_t start  = *p;
    while('0' <= s[*p] && s[*p] <= '9') {
        amount = amount * 10 + (s[*p] - '0');
        (*p)++;
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


// Operations ScanOperation(const char* s, size_t* p) {
//     SkipSpaces(s, p);
//     char       operation[6] = "";
//     size_t     op_index     = 0;
//     Operations op;
//     while(s[*p] != '(' && op_index < 6) {
//         operation[op_index] = s[*p];
//         (*p)++;
//         SkipSpaces(s, p);
//         op_index++;
//     }
//     operation[op_index + 1] = '\0';
//     if (s[*p] != '(')
//         SyntaxError(__LINE__);
//     DetectOperation(operation);
// }

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
