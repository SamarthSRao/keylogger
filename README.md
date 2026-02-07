# Keylogger

A basic keylogger for Windows written in C++. This program records keystrokes to a log file.

## Feature
- Records all keystrokes to keylog.txt
- Handles special keys (Enter, Backspace, Tab, etc.)
- Logs are appended to the existing file
- Runs in the background

## Compilation

### Prerequisites

- MinGW-w64 compiler installed and added to PATH

### Compile the Keylogger

1. Double-click `compile.bat` to compile the keylogger
2. If successful, `keylogger.exe` will be created

Alternatively, compile manually using:
```
g++ keylogger.cpp -o keylogger.exe -luser32 -lkernel32
```

## Usage

1. Run `keylogger.exe`
2. The program will run in the background
3. Keystrokes will be logged to `keylog.txt` in the same directory
4. To stop the keylogger, terminate the process from Task Manager

## Log File

- The log file is named `keylog.txt`
- Each keystroke is recorded as it is pressed
- Special keys are enclosed in square brackets (e.g., [ENTER])

## Notes

- This keylogger is for educational purposes only
- Unauthorized use of keyloggers may be illegal in your jurisdiction
- Always obtain proper permission before using keyloggers

## Legal Disclaimer

The author is not responsible for any misuse of this software. Users must comply with all applicable laws and regulations.