#!/bin/sh

echo "Generated 'version.h':"
echo  >version.h "/* GENERATED */"
echo >>version.h "#ifndef VERSION_H"
echo >>version.h "#define VERSION_H"
echo >>version.h "#define VERSION \"1.0\""
echo >>version.h "#endif"
cat version.h
