# EOOS Automotive WIN32
---

EOOS Automotive for Win32 API based OSs is software for automotive sphere been developing 
with aim to ISO 26262. Source code is complied with AUTOSAR C++14 and MISRA C++ rules.

---

# 1. How-to Build Project

## 1.1 Prerequisites on Windows

The process described below is passed on Windows 10 (64-bit) and requires the next tool to be installed on it:

**1. Install [Git for Windows](https://git-scm.com/downloads)**
The installer automatically sets the `Path` system environment variable.
But you have to set manually `C:\Program Files\Git\binpath` to the `Path` user environment variable to execute Bash if it needs. 
Having Git installed, you should sign out form and sign in to Windows to refresh the environment variables, and can check 
in CMD that Git and Bash can be executed properly.

```
C:\>git --version
git version 2.26.0.windows.1
 
C:\>bash --version
GNU bash, version 4.4.23(1)-release (x86_64-pc-msys)
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
 
This is free software; you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```