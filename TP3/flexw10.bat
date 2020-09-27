@echo off

set ruta_flex="C:\Program Files (x86)\GnuWin32\bin"

if %2.==. ( 
    set ejecutable=a.exe
) else (
    set ejecutable=%2
)

if %1.==. ( 
    echo se esperaba archivo de especificacion
) else (
    if exist %ejecutable% del %ejecutable%
    echo generando codigo c...
    flex %1
    if exist lex.yy.c (
        echo lex.yy.c creado.
        echo compilando y enlazando con libfl.a...
        gcc lex.yy.c -L "C:\Program Files (x86)\GnuWin32\lib" -lfl -o %ejecutable%
        if exist %ejecutable% (
            echo "%ejecutable% creado."
            echo "abriendo %ejecutable%..."
            start %ejecutable%
        ) else (
            del lex.yy.c
        )
    )    
)
exit