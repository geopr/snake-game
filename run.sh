#!/bin/sh

find src -name "*.c" | xargs clang -o exec
./exec
