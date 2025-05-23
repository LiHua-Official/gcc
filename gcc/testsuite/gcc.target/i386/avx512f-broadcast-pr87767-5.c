/* PR target/87767 */
/* { dg-do compile } */
/* { dg-options "-O2 -mavx512f" } */
/* { dg-final { scan-assembler-times "\[^n\n\]*\\\{1to8\\\}" 4 } }  */
/* { dg-final { scan-assembler-times "\[^n\n\]*\\\{1to16\\\}" 4 } }  */

typedef int v16si  __attribute__ ((vector_size (64)));
typedef long long v8di  __attribute__ ((vector_size (64)));

#define CONSTANT 101;
#define FOO(VTYPE, OP_NAME, OP1, OP2)		\
VTYPE						\
 __attribute__ ((noipa))			\
 foo_##OP_NAME##_##VTYPE (VTYPE a)		\
{						\
  return (OP1 a) OP2 CONSTANT;			\
}						\

FOO (v16si, andnot, ~, &);
FOO (v8di, andnot, ~, &);
FOO (v16si, and,, &);
FOO (v8di, and,, &);
FOO (v16si, or,, |);
FOO (v8di, or,, |);
FOO (v16si, xor,, ^);
FOO (v8di, xor,, ^);
