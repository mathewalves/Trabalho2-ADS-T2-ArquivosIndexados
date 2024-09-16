@echo off
goto :windows

#!/bin/bash
# Código Linux
echo "Compilando o programa..."
g++ -I./include src/*.cpp -o bin/programa
if [ $? -ne 0 ]; then
    echo "Erro na compilação!"
    read -p "Pressione Enter para continuar..."
    exit 1
fi
echo "Compilação concluída com sucesso!"
echo
echo "Executando o programa..."
./bin/programa
read -p "Pressione Enter para continuar..."
exit 0

:windows
@echo off
echo Compilando o programa...
g++ -I./include src/*.cpp -o bin/programa.exe
if %errorlevel% neq 0 (
    echo Erro na compilação!
    pause
    exit /b %errorlevel%
)
echo Compilação concluída com sucesso!
echo.
echo Executando o programa...
bin\programa.exe
pause