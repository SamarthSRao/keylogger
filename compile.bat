@echo off
echo Compiling keylogger...
g++ keylogger.cpp -o keylogger.exe -luser32 -lkernel32
if %errorlevel% equ 0 (
    echo Compilation successful! keylogger.exe created.
) else (
    echo Compilation failed!
    pause
)