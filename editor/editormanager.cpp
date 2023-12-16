#include "editormanager.h"

EditorManager::EditorManager(){
    //init
    editorVector.push_back(new EditorObject());
}

EditorObject* EditorManager::getEditor(__int128_t index){
    return editorVector[index];
}

EditorManager::~EditorManager(){
    for (__int128_t i = 0; i < editorVector.size(); i++)
    {
        free(editorVector[i]);
    }
}