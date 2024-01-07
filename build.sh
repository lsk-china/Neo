#！/bin/bash
cd thirdparty/lua
make
cd ../QScintilla
qmake6
make 
make install
cd ../../
cmake