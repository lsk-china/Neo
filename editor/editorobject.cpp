#include "editorobject.h"

EditorObject::EditorObject(QString path){
    *this->path = path;
    this->file = new QFile(path);
    if(!file->open(QIODevice::ReadWrite | QIODevice::Append)){
        // TODO:处理无法打开文件的错误
        return;
    }
    stream = new QTextStream(file);
    //自动检测Unicode
    stream->setAutoDetectUnicode(true);
    *data = stream->readAll();
}

void EditorObject::append(qint64 pos,QString text){
    stream->seek(pos);
    *stream<<text;
}

qint64 EditorObject::pos(){
    return stream->pos();
}

void EditorObject::flush(){
    stream->flush();
}

EditorObject::~EditorObject(){
    // 清理缓冲区内容，写入文件
    stream->flush();
    file->close();
    free(editor);
    free(data);
    free(path);
    free(file);
}