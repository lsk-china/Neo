/// 负责管理所有编辑器的创建，移位，删除等操作
#include <vector>
#include <string>

#include "editorobject.h"

class EditorManager{
private:
    std::vector<EditorObject*> editorVector;
    __int128_t size;
public:
    EditorManager();

    EditorObject* getEditor(__int128_t index);

    ~EditorManager();
};