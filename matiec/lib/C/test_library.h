// test_library.h – this file contains the C code for the TEST block defined in the “Test Library”

// FUNCTION_BLOCK TEST

// Data part
typedef struct
{
    // FB Interface – IN, OUT, IN_OUT variables
    __DECLARE_VAR(BOOL, EN)
    __DECLARE_VAR(BOOL, ENO)
    __DECLARE_VAR(INT, I0)
    __DECLARE_VAR(BOOL, ACTIVE)
    __DECLARE_VAR(INT, OUT)
} TEST;

// Initialization part
static void TEST_init__(TEST *data__, BOOL retain)
{
    __INIT_VAR(data__->EN, __BOOL_LITERAL(TRUE), retain)
    __INIT_VAR(data__->ENO, __BOOL_LITERAL(TRUE), retain)
    __INIT_VAR(data__->I0, 0, retain)
    __INIT_VAR(data__->ACTIVE, __BOOL_LITERAL(FALSE), retain)
    __INIT_VAR(data__->OUT, 0, retain)
}

// Code part
static void TEST_body__(TEST *data__)
{

    // Control execution – this should be the same for every Function Block
    if (!__GET_VAR(data__->EN))
    {
        __SET_VAR(data__->, ENO, , __BOOL_LITERAL(FALSE));
        return;
    }
    else
    {
        __SET_VAR(data__->, ENO, , __BOOL_LITERAL(TRUE));
    }

// Actual Code
#define GetFbVar(var, ...) __GET_VAR(data__->var, __VA_ARGS__)
#define SetFbVar(var, val, ...) __SET_VAR(data__->, var, __VA_ARGS__, val)
    if (GetFbVar(ACTIVE))
    {
        SetFbVar(OUT, GetFbVar(I0) + 10);
    }

#undef GetFbVar
#undef SetFbVar

    return;
} // TEST_body__()

typedef struct
{
    // FB Interface – IN, OUT, IN_OUT variables
    __DECLARE_VAR(BOOL, EN)
    __DECLARE_VAR(BOOL, ENO)
    __DECLARE_VAR(INT, I0)
    __DECLARE_VAR(BOOL, ACTIVE)
    __DECLARE_VAR(INT, OUT)
} BNO055;

// Initialization part
static void BNO055_init__(BNO055 *data__, BOOL retain)
{
    __INIT_VAR(data__->EN, __BOOL_LITERAL(TRUE), retain)
    __INIT_VAR(data__->ENO, __BOOL_LITERAL(TRUE), retain)
    __INIT_VAR(data__->I0, 0, retain)
    __INIT_VAR(data__->ACTIVE, __BOOL_LITERAL(FALSE), retain)
    __INIT_VAR(data__->OUT, 0, retain)
}

// Code part
static void BNO055_body__(BNO055 *data__)
{

    // Control execution – this should be the same for every Function Block
    if (!__GET_VAR(data__->EN))
    {
        __SET_VAR(data__->, ENO, , __BOOL_LITERAL(FALSE));
        return;
    }
    else
    {
        __SET_VAR(data__->, ENO, , __BOOL_LITERAL(TRUE));
    }

// Actual Code
#define GetFbVar(var, ...) __GET_VAR(data__->var, __VA_ARGS__)
#define SetFbVar(var, val, ...) __SET_VAR(data__->, var, __VA_ARGS__, val)
    if (GetFbVar(ACTIVE))
    {
        SetFbVar(OUT, GetFbVar(I0) + 10);
    }

#undef GetFbVar
#undef SetFbVar

    return;
} // BNO055_body__()