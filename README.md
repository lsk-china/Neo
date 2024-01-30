# NEO

## Dependence
[Click here](./thirdparty/README.md)

## Clone
```
git clone git@github.com:Shirasawa-CN/Neo.git
```

## Build
### linux
```
cd /thirdparty/Scintilla/win32
make 
cd ../qt
qmake6
make

cd ../../../
cmake
```

### windows
msys2
```
pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-qt6-base
```

powershell
```
cd /thirdparty/Scintilla/win32
mingw32-make 
cd ../qt
qmake6
mingw32-make

cd ../../../
cmake
```