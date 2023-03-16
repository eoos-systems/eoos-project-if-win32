# EOOS Automotive WIN32
---

**EOOS copyrights reserved in [Rospatent Federal Service for Intellectual Property]( https://www1.fips.ru/registers-doc-view/fips_servlet?DB=EVM&DocNumber=2017664105&TypeFile=html), Russian Federation**

EOOS Automotive for WIN32 API based operating systems is a **C++ library for cross-platform development** of 
applications in automotive sphere. The library is developed in **C++98** programming language and supports 
features of **C++11** programming language depending on compiler options that 
**allows to consider wide criteria when selecting a suitable programming language** on initiation step 
of product development.

EOOS Automotive WIN32 is developed within **ISO C++ standards**, complied with **MISRA C++:2008** and 
**AUTOSAR C++14 Coding Guidelines**, and relies on **ISO 26262** that means applications based on EOOS 
**can be used in critical and safety-related systems**.

Quality of EOOS Automotive WIN32:

- MISRA C++ and AUTOSAR C++: **0** violations
- Unit Tests coverage: **94%**

---

## 1. How-to Build Project

EOOS is a static library for linkage with other Windows applications. This EOOS project based on CMake that builds 
the static library and installs it on Windows for being found by CMake projects of the Windows applications.



#### 1.1. Prerequisites on Windows

The process described below is passed on 

- Windows 7 (64-bit)
- Windows 10 (64-bit)
- Windows 11 (64-bit)

and requires the next tool to be installed on it:

###### 1.1.1. Install [Git for Windows](https://git-scm.com/downloads)

The installer automatically sets the *Path* system environment variable.
But you have to set manually *C:\Program Files\Git\binpath* to the *Path* user environment variable to execute Bash if it needs. 
After the installation, check in CMD that tool is executed properly by executing the following commands.

```
C:\> git --version
git version 2.26.0.windows.1
 
C:\> bash --version
GNU bash, version 4.4.23(1)-release (x86_64-pc-msys)
Copyright (C) 2016 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
 
This is free software; you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```

###### 1.1.2. Install [CMake 3.20 or higher](https://cmake.org/download/)

CMake minimum required version 3.20 for EOOS project.

The installer automatically sets the *Path* system environment variable if you chose this way during installation. 
After the installation, check in CMD that tool is executed properly by executing the following commands.

```
C:\> cmake --version
cmake version 3.20.6
```

###### 1.1.3. Instal [Visual Studio](https://developer.microsoft.com/en-us/windows/downloads/) or [Windows SDK](https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/) for purposes that you need

After the installation, check in CMD that tool is executed properly by executing the following commands.

```
C:\> MSBuild -version
Microsoft (R) Build Engine version 16.5.0+d4cbfca49 for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

16.5.0.12403
```

###### 1.1.4. Install [Python 3.10 or higher](https://www.python.org/downloads/) for automation

Allow the installer to set *Path*. 
After the installation, check in CMD that tool is executed properly by executing the following commands.

```
C:\>python --version
Python 3.10.2
```

NOTE: This is important to install colorama v0.4.6 or higher.

###### 1.1.5. Install [OpenCppCoverage](https://github.com/OpenCppCoverage/OpenCppCoverage/releases/tag/release-0.9.9.0) for code coverage report generation

Allow the installer to set *Path*.
After the installation, check in CMD that tool is executed properly by executing the following commands.

```
C:\> OpenCppCoverage.exe
OpenCppCoverage Version: 0.9.9.0
```



#### 1.2. Obtain Git Repository

###### 1.2.1. Create an empty directory somewhere on your disk

For instance we will create *C:\REPOSITORY*.

```
C:\> mkdir REPOSITORY
C:\> cd REPOSITORY
C:\REPOSITORY>
```

###### 1.2.2. Clone this repository

For instance we will clone it to *EOOS* directory by SSH.

```
C:\REPOSITORY\> git clone --branch master git@gitflic.ru:baigudin-software/eoos-project-if-win32.git EOOS
```

###### 1.2.3. Go the EOOS directory

```
C:\REPOSITORY\> cd EOOS
```

###### 1.2.4. Initialize and update all submodules of the repository

```
C:\REPOSITORY\EOOS> git submodule update --init
```



#### 1.3. Source Code Build and Installation

EOOS can be executed on various systems. To standardize the building process, we put most common steps 
under the hood of the `Make.py` cross-platform script that is located in `scripts/python` directory.

###### 1.3.1. Build and Installation for Developing on EOOS

Run CMD in *Run as administrator* mode to be able to install EOOS on Windows and execute the commads below.

```
C:\REPOSITORY\EOOS> cd scripts\python
C:\REPOSITORY\EOOS\scripts\python> python Make.py --clean --build EOOS --install --config RelWithDebInfo
```

None that the *--config* parameter can be one of *Release*, *Debug*, *RelWithDebInfo*, *MinSizeRel*, but for developing
purpose we recommend to pass *RelWithDebInfo*.

Having done all the steps, EOOS will be installed to the *C:\Program Files (x86)* directory, and you will be able 
to find EOOS in by using `find_package()` command in your CMake project.

An example of your root *CMakeLists.txt* may be the next:

```
cmake_minimum_required(VERSION 3.20)
project(eoos-application VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(EOOS 0.11.0 REQUIRED)

add_executable(application)

target_sources(application
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/Program.cpp"
)

target_link_libraries(application
PRIVATE
    eoos::main
)

set_target_properties(application PROPERTIES
    OUTPUT_NAME EoosApplication
)
```

Thus, you will build *EoosApplication.exe* executable file.

> For more examples and fast start please see 
> the [EOOS Automotive Sample Applications](https://gitflic.ru/project/baigudin-software/eoos-project-sample-applications) repository

###### 1.3.2. Build for Testing EOOS

This chapter must be useful for EOOS developers and CI/CD engineers, but not prohibited to be used by any other for sure.

To build the project with Unit Tests and run them, you have to execute the commands below.

```
C:\REPOSITORY\EOOS> cd scripts\python
C:\REPOSITORY\EOOS\scripts\python> python Make.py --clean --build ALL --run --config RelWithDebInfo
```

