/// 负责提供编辑器控制函数

#ifndef EDITOROBJECT_H
#define EDITOROBJECT_H

#include <QString>
#include <QFile>
#include <QTextStream>

#include "editorbase.h"

class EditorObject
{
private:
    EditorBase *editor;
    QString *data;
    QString *path;
    QFile *file;
    QTextStream *stream;


public:
    EditorObject(QString path);

    /// @brief 通过跳转指针到指定位址写入文本,按道理来说会比复制一整块到缓冲区快得多
    /// @param pos 
    /// @param text 
    void append(qint64 pos, QString text);
    qint64 pos();
    void flush();

    ~EditorObject();
};

#endif