#!/bin/bash

make re

echo ""
echo ">>> ./a.out 0"
./a.out 0

echo ""
echo ">>> ./a.out 42"
./a.out 42

echo ""
echo ">>> ./a.out 42."
./a.out 42.

echo ""
echo ">>> ./a.out hello!"
./a.out hello!

echo ""
echo ">>> ./a.out 30 86"
./a.out 30 86

echo ""
echo ">>> ./a.out 42.f"
./a.out 42.f

echo ""
echo ">>> ./a.out -64"
./a.out -64

echo ""
echo ">>> ./a.out -30.7878f"
./a.out -30.7878f

echo ""
echo ">>> ./a.out -24.456"
./a.out -24.456

echo ""
echo ">>> ./a.out nan"
./a.out nan

echo ""
echo ">>> ./a.out nanf"
./a.out nanf

echo ""
echo ">>> ./a.out inf"
./a.out inf

echo ""
echo ">>> ./a.out inff"
./a.out inff

echo ""
echo ">>> ./a.out +inf"
./a.out +inf

echo ""
echo ">>> ./a.out +inff"
./a.out +inff

echo ""
echo ">>> ./a.out -inf"
./a.out -inff

echo ""
echo ">>> ./a.out 2147483647"
./a.out 2147483647

echo ""
echo ">>> ./a.out 2147483649"
./a.out 2147483649

echo ""
echo ">>> ./a.out -2147483648"
./a.out -2147483648

echo ""
echo ">>> ./a.out -2147483649"
./a.out -2147483649

echo ""
echo ">>> ./a.out 2147483649.0f"
./a.out 2147483649.0f

echo ""
echo ">>> ./a.out -2147483649.89"
./a.out -2147483649.89

echo ""
echo ">>> ./a.out a"
./a.out a

echo ""
echo ">>> ./a.out \"***\""
./a.out "***"

echo ""
echo ">>> ./a.out 216"
./a.out 216

echo ""
echo ">>> ./a.out test"
./a.out test

echo ""
echo ">>> ./a.out 54178652.41784187"
./a.out 54178652.41784187

echo ""
echo ">>> ./a.out ?"
./a.out ?

echo ""
echo ">>> ./a.out y"
./a.out y

echo ""
echo ">>> ./a.out ~"
./a.out '~'
