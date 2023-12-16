/// 负责定义编辑器的基本函数和功能

#ifndef EDITORBASE_H
#define EDITORBASE_H

#include <QString>
#include <QTextEdit>

#include "programlanguage.h"

class EditorBase : public QTextEdit{
private:
    QString *title;
    __int128_t *id;
    //Editor *editor;

    ProgramLanguageSupport *language;
    
    /// status
    bool *is_saved;
    bool *is_focused;
    bool *is_modified;
    //渲染情况,如果修改后需重新渲染
    bool *is_highlighted;

public:
    EditorBase(QString title,__int128_t id,ProgramLanguageSupport language);

    bool save();
    bool highlight();

    ~EditorBase();
};

#endif