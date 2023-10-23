#pragma once

#include "../compiler/value.hpp"
#include "../opCode/chunk.hpp"
#include "../types/type.hpp"
#include "../common.hpp"

struct VM {
    Chunk* chunk;
    uint8_t* ip;

    Value stack[256]; // 256 is the max stack size
    Value* stackTop;
};

inline VM vm;

void resetStack();
void initVM();
void freeVM();

Zura_Exit_Value interpret(const char* source);

Value peek(int distance);
void push(Value value);
Value pop();