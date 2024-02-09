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
cd /thirdparty/scintilla/qt/ScintillaEdit
python3 ./WidgetGEn.py
make
cd ../../gtk
make

cd ../../../
cd lua
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
cd /thirdparty/scintilla/win32
mingw32-make 
cd ../qt/ScintillaEdit
mingw32-make

cd ../../../lua
mingw32-make

cd ../../../
cmake
```