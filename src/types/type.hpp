#pragma once

enum ValueType {
    Bool, Number, Nil,
};

struct Value {
    ValueType type;
    union {
        bool boolean;
        double number;
    } as;
};

constexpr Value BOOL_VAL(bool value)     { return Value{Bool, {.boolean = value}};  }
constexpr Value NUMBER_VAL(double value) { return Value{Number, {.number = value}}; }
constexpr Value NIL_VAL()                { return Value{Nil, {.number = 0}};        }

constexpr bool AS_BOOL(Value value)      { return value.as.boolean; }
constexpr double AS_NUMBER(Value value)  { return value.as.number;  }

constexpr bool IS_BOOL(Value value)      { return value.type == Bool;   }
constexpr bool IS_NUMBER(Value value)    { return value.type == Number; }
constexpr bool IS_NIL(Value value)       { return value.type == Nil;    }