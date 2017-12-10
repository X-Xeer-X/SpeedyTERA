#include <windows.h>
#include <cstdio>

char * szOnBeforeEncrypt = "[SpeedyTera][PluginExample] onBeforeEncrypt: ";
char buf[10240] = { 0 };
char hexBuf[50] = { 0 };

extern "C" __declspec (dllexport) void __cdecl onBeforeEncrypt(char * buffer, size_t size) {
  strcpy_s(buf, szOnBeforeEncrypt);
  for (size_t i = 0; i < size; i++) {
    sprintf_s(hexBuf, "%02X", (unsigned char)buffer[i]);
    strcat_s(buf, hexBuf);
  }
  OutputDebugString(buf);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved) {
  switch (ulReason) {
  case DLL_PROCESS_ATTACH: {
    OutputDebugString("[SpeedyTera][PluginExample] Attached");
    break;
  }
  case DLL_PROCESS_DETACH:
    OutputDebugString("[SpeedyTera][PluginExample] Detached");
    break;
  }

  return TRUE;
}
