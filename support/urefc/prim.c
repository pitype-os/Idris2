#include "prim.h"

Value *idris2_Data_IORef_prim__newIORef(Value *erased, Value *input_value,
                                        Value *_world) {
  Value_IORef *ioRef = IDRIS2_NEW_VALUE(Value_IORef);
  ioRef->header.tag = IOREF_TAG;
  ioRef->v = idris2_newReference(input_value);
  return (Value *)ioRef;
}

Value *idris2_Data_IORef_prim__writeIORef(Value *erased, Value *_ioref,
                                          Value *new_value, Value *_world) {
  Value_IORef *ioref = (Value_IORef *)_ioref;
  idris2_newReference(new_value);
  Value *old = ioref->v;
  ioref->v = new_value;
  idris2_removeReference(old);
  return NULL;
}

// -----------------------------------
//       System operations
// -----------------------------------

Value_String const idris2_predefined_osstring = {IDRIS2_STOCKVAL(STRING_TAG),
#ifdef _WIN32
                                                 "windows"
#elif _WIN64
                                                 "windows"
#elif __APPLE__ || __MACH__
                                                 "macOS"
#elif __linux__
                                                 "Linux"
#elif __FreeBSD__
                                                 "FreeBSD"
#elif __OpenBSD__
                                                 "OpenBSD"
#elif __NetBSD__
                                                 "NetBSD"
#elif __DragonFly__
                                                 "DragonFly"
#elif __unix || __unix__
                                                 "Unix"
#else
                                                 "Other"
#endif
};

// NOTE: The codegen is obviously determined at compile time,
//       so the backend should optimize it by replacing it with a constant.
//       It would probably also be useful for conditional compilation.
Value_String const idris2_predefined_codegenstring = {
    IDRIS2_STOCKVAL(STRING_TAG), "refc"};

Value *sysCodegen(void) { return (Value *)idris2_mkString("refc"); }

Value *idris2_crash(Value *msg) {
  Value_String *str = (Value_String *)msg;
  exit(-1);
}

// // -----------------------------------
// //         Array operations
// // -----------------------------------


Value *idris2_Data_IOArray_Prims_prim__newArray(Value *erased, Value *_length,
                                                Value *v, Value *_word) {
  int length = idris2_vp_to_Int64(_length);
  Value_Array *a = idris2_makeArray(length);

  for (int i = 0; i < length; i++) {
    a->arr[i] = idris2_newReference(v);
  }

  return (Value *)a;
}

Value *idris2_Data_IOArray_Prims_prim__arraySet(Value *erased, Value *_array,
                                                Value *index, Value *v,
                                                Value *_word) {
  Value_Array *a = (Value_Array *)_array;
  idris2_removeReference(a->arr[idris2_vp_to_Int64(index)]);
  a->arr[idris2_vp_to_Int64(index)] = idris2_newReference(v);
  return NULL;
}

Value *idris2_Prelude_IO_prim__onCollect(Value *_erased, Value *_anyPtr,
                                         Value *_freeingFunction,
                                         Value *_world) {
  Value_GCPointer *retVal = IDRIS2_NEW_VALUE(Value_GCPointer);
  retVal->header.tag = GC_POINTER_TAG;
  retVal->p = (Value_Pointer *)idris2_newReference(_anyPtr);
  retVal->onCollectFct = (Value_Closure *)_freeingFunction;
  return (Value *)retVal;
}

Value *idris2_Prelude_IO_prim__onCollectAny(Value *_anyPtr,
                                            Value *_freeingFunction,
                                            Value *_world) {
  Value_GCPointer *retVal = IDRIS2_NEW_VALUE(Value_GCPointer);
  retVal->header.tag = GC_POINTER_TAG;
  retVal->p = (Value_Pointer *)idris2_newReference(_anyPtr);
  retVal->onCollectFct = (Value_Closure *)_freeingFunction;
  return (Value *)retVal;
}

Value *voidElim(Value *erased1, Value *erased2) { return NULL; }

char const idris2_constr_Int[] = "Int";
char const idris2_constr_Int8[] = "Int8";
char const idris2_constr_Int16[] = "Int16";
char const idris2_constr_Int32[] = "Int32";
char const idris2_constr_Int64[] = "Int64";
char const idris2_constr_Bits8[] = "Bits8";
char const idris2_constr_Bits16[] = "Bits16";
char const idris2_constr_Bits32[] = "Bits32";
char const idris2_constr_Bits64[] = "Bits64";
char const idris2_constr_Double[] = "Double";
char const idris2_constr_Integer[] = "Integer";
char const idris2_constr_Char[] = "Char";
char const idris2_constr_String[] = "String";
char const idris2_constr____gt[] = "->";

