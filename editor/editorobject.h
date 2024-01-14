/// 负责提供编辑器控制函数

#ifndef EDITOROBJECT_H
#define EDITOROBJECT_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "editorbase.h"

class EditorObject : public QWidget
{
private:
    EditorBase *editor;
    QString *data;
    QString *path;
    QFile *file;
    QTextStream *stream;

    ///
    QCompleter *completer;

public:
    EditorObject(QString path, long long id);
    EditorObject();

    void save();
    void getData();
    EditorBase* getEditor();

    inline void setEditor();
    inline void setEditor(EditorSetting setting);

    ~EditorObject();

private slots:
    ///检测行数改变，并自动修改行号栏宽度
    void LineChanged();
};

#endif