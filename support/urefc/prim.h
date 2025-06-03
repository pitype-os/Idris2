#include "cBackend.h"

// IORef

Value *newIORef(Value *, Value *, Value *);
Value *readIORef(Value *, Value *, Value *);
Value *writeIORef(Value *, Value *, Value *, Value *);

// Sys

Value *sysCodegen(void);
Value *idris2_crash(Value *msg);
extern Value_String const idris2_predefined_osstring;
extern Value_String const idris2_predefined_codegenstring;
#define idris2_System_Info_prim__os() ((Value *)&idris2_predefined_osstring)
#define idris2_System_Info_prim__codegen()                                     \
  ((Value *)&idris2_predefined_codegenstring)

// Array

Value *newArray(Value *, Value *, Value *, Value *);
Value *arrayGet(Value *, Value *, Value *, Value *);
Value *arraySet(Value *, Value *, Value *, Value *, Value *);

Value *onCollect(Value *, Value *, Value *, Value *);
Value *onCollectAny(Value *, Value *, Value *);

Value *voidElim(Value *, Value *);

extern char const idris2_constr_Int[];
extern char const idris2_constr_Int8[];
extern char const idris2_constr_Int16[];
extern char const idris2_constr_Int32[];
extern char const idris2_constr_Int64[];
extern char const idris2_constr_Bits8[];
extern char const idris2_constr_Bits16[];
extern char const idris2_constr_Bits32[];
extern char const idris2_constr_Bits64[];
extern char const idris2_constr_Double[];
extern char const idris2_constr_Integer[];
extern char const idris2_constr_Char[];
extern char const idris2_constr_String[];
extern char const idris2_constr____gt[];


