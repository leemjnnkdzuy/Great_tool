#include "lib.h"


#pragma comment(lib, "Wininet.lib")

void Install_Spotify() 
{
    HINTERNET hInternet = InternetOpen(L"MyApp", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (hInternet != NULL) {
        const char* url = "https://raw.githubusercontent.com/amd64fox/SpotX/main/Install.ps1";
        int urlLength = strlen(url) + 1;
        int wUrlLength = MultiByteToWideChar(CP_ACP, 0, url, urlLength, NULL, 0);
        wchar_t* wUrl = new wchar_t[wUrlLength];
        MultiByteToWideChar(CP_ACP, 0, url, urlLength, wUrl, wUrlLength);

        HINTERNET hUrl = InternetOpenUrl(hInternet, wUrl, NULL, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
        if (hUrl != NULL) {
            char buffer[1024];
            DWORD bytesRead;
            string scriptContent = "";

            while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
                scriptContent.append(buffer, bytesRead);
            }

            InternetCloseHandle(hUrl);
            InternetCloseHandle(hInternet);

            string powershellCommand = "$([Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12); ";
            powershellCommand += scriptContent;
            powershellCommand += " -confirm_uninstall_ms_spoti -confirm_spoti_recomended_over -podcasts_off -block_update_on -start_spoti -new_theme -adsections_off -lyrics_stat spotify ";

            int wCommandLength = MultiByteToWideChar(CP_ACP, 0, powershellCommand.c_str(), -1, NULL, 0);
            wchar_t* wCommand = new wchar_t[wCommandLength];
            MultiByteToWideChar(CP_ACP, 0, powershellCommand.c_str(), -1, wCommand, wCommandLength);

            ShellExecute(NULL, L"open", L"powershell.exe", wCommand, NULL, SW_HIDE);

            delete[] wUrl;
            delete[] wCommand;
        }
    }
}