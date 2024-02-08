/// 负责定义编辑器的基本函数和功能

#ifndef EDITORBASE_H
#define EDITORBASE_H

#include <QString>
#include <QTextEdit>
#include <QCompleter>
#include <QFont>
#include <QColor>

#include <ScintillaEdit.h>
#include <Scintilla.h>
#include <ScintillaMessages.h>
#include <ScintillaStructures.h>
#include <ScintillaCall.h>
#include <ScintillaTypes.h>
#include <ScintillaDocument.h>

#include "editorhighlighter.h"
#include "programlanguage.h"

enum Encode
{
    UTF8,
    GBK
};

enum Folding
{
    BoxedTreeFoldStyle
};

struct EditorSetting{
    QFont font;
    int setTabWidth;
    bool setAutoIndent;
    bool setCaretLineVisible;
    QColor setCaretLineBackgroundColor;
    Encode setEncode;
    Folding setFolding;
    int setMarginWidth;
    QColor setMarginsForegroundColor;
    QColor setPaperColor;
    QColor setCaretForegroundColor;
    int setCaretWidth;
};

class EditorBase : public ScintillaEdit{
private:
    QString *title;
    long long *id;
    
    /// status
    bool *is_saved;
    bool *is_focused;
    bool *is_modified;
    //渲染情况,如果修改后需重新渲染
    bool *is_highlighted;

public:
    EditorBase(QString title, long long id);

    bool Neo_highlight();

    int getTotalLine(){
        return send(SCI_GETLINECOUNT, 0, 0);
    }

    ~EditorBase() override;

private slots:
    void NeoAutoChangeMarginWidth();
};

#endif