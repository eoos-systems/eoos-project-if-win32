<##
 # This script builds a program.
 #
 # @param -clean - cleans the project by removing the 'build' directory.
 # @param -build - compile the project
 # @param -install - install the project
 #
 # SDIR: REPOSITORY/scripts>
 # EDIR: REPOSITORY/scripts>
 #
 # @author Sergey Baigudin, sergey@baigudin.software
 #>
param(
    [switch]$clean,
    [switch]$build,
    [switch]$install
)

Import-Module -Name .\functions.psm1

[string]$pathScriptToBuildDir = ".\..\build"
[string]$pathBuildToScriptDir = ".\..\scripts"

<## 
 # Outs a message.
 #>
function Out-Note([string]$string, [switch]$Block, [switch]$say, [switch]$ok, [switch]$err, [switch]$inf)
{
    Out-Message -String ("[BUILD] " + $string) -Block:$block.IsPresent -Say:$say.IsPresent -Ok:$ok.IsPresent -Err:$err.IsPresent -Inf:$inf.IsPresent
} 

<## 
 # Builds the project.
 #
 # CDIR: REPOSITORY/scripts>
 # EDIR: REPOSITORY/scripts> 
 #>
function Build()
{
    Out-Message -String "Build is started" -Inf -Block
    if($clean)
    {
        Out-Note -String "EOOS build clean is set" -Inf
        if( Test-Path -Path $pathScriptToBuildDir )
        {
            Out-Note "Remove build directory" -Inf
            Remove-Item -Path $pathScriptToBuildDir -Recurse -Force
        }
    }
    if( (Test-Path -Path $pathScriptToBuildDir) -eq $false )
    {
        Out-Note -String "Create build directory" -Inf
        New-Item -ItemType "directory" -Path $pathScriptToBuildDir
        New-Item -ItemType "directory" -Path ($pathScriptToBuildDir + "/CMakeInstallDir")
    }
    
    cd -Path $pathScriptToBuildDir # CDIR: REPOSITORY/build>
       
    Out-Note -String "Generate CMake project" "INF" -Inf
    cmake -D CMAKE_INSTALL_PREFIX=CMakeInstallDir ..
    
    if($build)
    {
        Out-Note -String "Build CMake project" -Inf
        cmake --build . --config Debug
    }
    
    if($install)
    {    
        Out-Note -String "Install CMake project" -Inf
        cmake --install . --config Debug
    }
    
    cd -Path $pathBuildToScriptDir # CDIR: REPOSITORY/scripts>
    Out-Message -String "ISSW project is built" -Inf -Block
}

Out-Message -String "BUILDING OF PROJECT HAS BEEN INVOKED" -Ok -Block
Build
Get-Module | Remove-Module
