# EOOS Automotive WIN32
---

EOOS Automotive for Win32 API based OSs is software for automotive sphere been developing 
with aim to ISO 26262. Source code is complied with AUTOSAR C++14 and MISRA C++ rules.

---

### 1. How-to Build Project

##### 1.1. Prerequisites on Windows

The process described below is passed on Windows 10 (64-bit) and requires the next tool to be installed on it:

###### 1.1.1. Install [Git for Windows](https://git-scm.com/downloads)

The installer automatically sets the *Path* system environment variable.
But you have to set manually *C:\Program Files\Git\binpath* to the *Path* user environment variable to execute Bash if it needs. 
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

###### 1.1.2. Install [CMake](https://cmake.org/download/)

The installer automatically sets the *Path* system environment variable if you chose this way during installation. 
Having Git installed, you should sign out form and sign in to Windows to refresh the environment variables, and can check 
in CMD that CMake can be executed properly.

```
C:\>cmake --version
cmake version 3.17.0
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

###### 1.1.3. Instal [Visual Studio](https://developer.microsoft.com/en-us/windows/downloads/) or [Windows SDK](https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/) for purposes that you need

Having a tool installed, you shell check in CMD that MSBuild can be executed properly with the similar output.

```
C:\>MSBuild.exe -version
Microsoft (R) Build Engine version 16.5.0+d4cbfca49 for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

16.5.0.12403
```

###### 1.1.4. Optionally install [Doxygen](https://www.doxygen.nl/download.html) for future documentation creation

The installer automatically sets the *Path* system environment variable.
Having Doxygen installed, you should sign out form and sign in to Windows to refresh the environment variables, and can check 
in CMD that Doxygen can be executed properly.

```
C:\>Doxygen -v
1.9.2 (caa4e3de211fbbef2c3adf58a6bd4c86d0eb7cb8)
```

###### 1.1.5. Optionally install [Graphviz](http://www.graphviz.org/download/) for future documentation creation

The installer automatically suggest adding Graphviz to the system *Path*, please add it. 
Having Graphviz installed, you should sign out form and sign in to Windows to refresh the environment variables, and can check 
in CMD that Graphviz can be executed properly.

```
C:\>dot -version
dot - graphviz version 2.49.3 (20211023.0002)
```

##### 1.2. Obtain Git Repository

###### 1.2.1. Create an empty directory somewhere on your disk. 

For instance we will create *C:\REPOSITORY*.

```
C:\>mkdir.exe REPOSITORY
C:\>cd REPOSITORY
C:\REPOSITORY>
```

###### 1.2.2. Clone this repository. 

For instance we will clone it to *EOOS* directory by SSH.

```
C:\REPOSITORY\>git clone --branch master git@gitflic.ru:baigudin-software/eoos-project-if-win32.git EOOS
```

###### 1.2.3. Go the EOOS directory

```
C:\REPOSITORY\>cd EOOS
```

###### 1.2.4. Initialize and update all submodules of the repository

```
C:\REPOSITORY\EOOS>git submodule update --init
```
