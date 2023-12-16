#include "editorbase.h"

EditorBase::EditorBase(QString title,__int128_t id,
                       ProgramLanguageSupport language){
    this->title = &title;
    this->id = &id;
    this->language = &language;
}

EditorBase::EditorBase(QString title,__int128_t id){
    this->title = &title;
    this->id = &id;
}

bool EditorBase::highlight()
{
    return false;
}

EditorBase::~EditorBase(){
}