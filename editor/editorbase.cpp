#include "editorbase.h"

EditorBase::EditorBase(QString title,__int128_t id,
                       ProgramLanguageSupport language){
    *this->title = title;
    *this->id = id;
    *this->language = language;
}

EditorBase::~EditorBase(){
    free(title);
    free(id);

    free(language);

    free(is_saved);
    free(is_focused);
    free(is_modified);
    free(is_highlighted);
}