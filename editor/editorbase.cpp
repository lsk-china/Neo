#include "editorbase.h"

EditorBase::EditorBase(QString title,long long id){
    this->title = &title;
    this->id = &id;
}

bool EditorBase::highlight()
{
    return false;
}

EditorBase::~EditorBase(){
}