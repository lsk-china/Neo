# NEO

## Dependence
```
libreadline-dev
```

## Clone
```
git clone git@github.com:Shirasawa-CN/Neo.git
git submodule init
git submodule update
```

## Build
### linux
```
sh ./build.sh
```

### windows
msys2
```
pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-qt6-base
```

[Download latest Lua source code](https://www.lua.org/download.html) and compile it with mingw32-make  
```
mingw32-make mingw
```
Copy the generated static link library to Neo/thirdparty/lua  

powershell
```
cd /thirdparty/QScintilla
qmake6
mingw32-make 
mingw32-make install
cmake
```