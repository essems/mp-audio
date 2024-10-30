
# vcpkg 설정 추가
```bash
$ git clone https://github.com/microsoft/vcpkg.git
$ cd vcpkg 
$ bootstrea-vcpkg.bat

# linux
# VCPKG_ROOT 등록 
$ export VCPKG_ROOT=/home/essems/Work/vcpkg
# vcpkg PATH 등록
$ export PATH=$VCPKG_ROOT:$PATH 

# windows powershell
$env:VCPKG_ROOT = "S:\devs\vcpkg"
$env:PATH = "$env:VCPKG_ROOT;$env:PATH"
```

## How to build
```bash
# <platform> in CMakePresets.json
$ cmake --preset=<platform> 
$ cmake --build build/<platform>
```