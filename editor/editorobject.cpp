#include "editorobject.h"

EditorObject::EditorObject(QString path, long long id){
    this->path = &path;
    this->file = new QFile(path);
    if(!file->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)){
        // TODO:处理无法打开文件的错误
        return;
    }
    stream = new QTextStream(file);
    //自动检测Unicode
    stream->setAutoDetectUnicode(true);
    *data = stream->readAll();
    editor = new EditorBase(path, id);

    // 默认设置
    setEditor();
}
EditorObject::EditorObject(){

    // 默认设置
    setEditor();
}

void EditorObject::save(){
    file->write(data->toUtf8());
}

void EditorObject::getData(){
}

EditorBase* EditorObject::getEditor(){
    return editor;
}

void EditorObject::setEditor(){
    QFont font("FiraCode", 14, QFont::Normal);
}

EditorObject::~EditorObject(){
    // 写入文件
    save();
    file->close();
    free(editor);
    free(data);
    free(path);
    free(stream);
    free(file);
    free(completer);
}