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
}
EditorObject::EditorObject(){
    editor = new EditorBase(QString("untitled"),0);

    // Test Code
    editor->setFontFamily("FiraCode");
    editor->setFontPointSize(14);
}

void EditorObject::save(){
    file->write(data->toUtf8());
}

void EditorObject::getData(){
    *data = editor->toPlainText();
}

EditorBase* EditorObject::getEditor(){
    return editor;
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