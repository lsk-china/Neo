#include "editormanager.h"

EditorManager::EditorManager(){
    //init
    editorVector.push_back(new EditorObject());
}

EditorObject* EditorManager::getEditor(long long index){
    return editorVector[index];
}

EditorManager::~EditorManager(){
    for (long long i = 0; i < editorVector.size(); i++)
    {
        free(editorVector[i]);
    }
}