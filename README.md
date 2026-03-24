# Windows Process Code Injection (C)

This project demonstrates the concept of process code injection on Windows using the C programming language.

The purpose of this project is to understand how memory manipulation and process injection techniques work at a low level in the Windows operating system.

---

## Disclaimer

This project is intended strictly for:

- Educational purposes  
- Cybersecurity research  
- Authorized penetration testing in controlled lab environments  

Do **not** use these techniques on systems without explicit permission.

---

## Objective

Process injection is a technique used to execute code within the address space of another process.

This project helps demonstrate:

- How memory is allocated in a remote process  
- How code can be written into another process’s memory  
- How execution can be triggered within that process  
- The interaction with Windows APIs involved in process handling  

---

## Key Concepts

- Process memory management  
- Windows API functions  
- Remote thread creation  
- Virtual memory allocation  
- Inter-process interaction  

---

## Technologies Used

- Language: C  
- Platform: Windows  
- APIs: Windows Native APIs (e.g., memory and process-related functions)

---


## How It Works (High-Level)

1. A target process is identified or created  
2. Memory is allocated within the target process  
3. Code or payload is written into that memory region  
4. A thread is created in the remote process to execute the injected code  

---

## Techniques Implemented

### 1. CreateRemoteThread Injection

- Allocates memory in a remote process
- Writes shellcode or payload into that memory
- Uses `CreateRemoteThread` to execute the payload

**Concepts involved:**
- Remote memory allocation
- Thread creation in another process
- Execution via a new thread

---

### 2. QueueUserAPC Injection

- Injects code into a target process using Asynchronous Procedure Calls (APCs)
- Requires the target thread to enter an alertable state

**Concepts involved:**
- APC queues
- Thread alertable states
- Indirect execution of payloads

---

### 3. Thread Hijacking Injection

- Suspends an existing thread in the target process
- Modifies its context (instruction pointer)
- Redirects execution to injected code
- Resumes the thread

**Concepts involved:**
- Thread context manipulation
- Register/state modification
- Control flow redirection

---
##  Defensive Perspective

Understanding process injection is important for defense and detection:

- Monitor suspicious process behavior (e.g., unexpected memory allocation)
- Detect abnormal thread creation in processes
- Use endpoint detection and response (EDR) tools
- Enable Windows Defender / advanced security protections
- Apply application allowlisting
- Monitor API calls associated with memory manipulation

---

## Learning Outcomes

This project demonstrates:

- Low-level Windows programming in C  
- Process and memory manipulation concepts  
- Understanding of how attackers may abuse legitimate APIs  
- Foundational knowledge for malware analysis and reverse engineering  
- Awareness of common attack techniques used in post-exploitation  

---

## Notes

- This is a simplified educational implementation
- Real-world techniques may include evasion, obfuscation, and additional stealth mechanisms
- Always test in isolated virtual environments

---

## Author

Developed as part of a penetration testing and offensive security learning path, focusing on understanding Windows internals and process interaction mechanisms.

---
