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
    editor = new EditorBase(QString("untitled"),0);

    // 默认设置
    setEditor();
}

void EditorObject::save(){
    file->write(data->toUtf8());
}

void EditorObject::getData(){
    *data = editor->text();
}

EditorBase* EditorObject::getEditor(){
    return editor;
}

void EditorObject::setEditor(){
    QFont font("FiraCode", 14, QFont::Normal);
    editor->setFont(font);
    editor->setColor(QColor(255,255,255));// 设置字体颜色

    editor->setTabWidth(4);// 设置Tab键为4个空格
    editor->setAutoIndent(true);// 开启自动缩进
    editor->setIndentationGuides(true); // 设置缩进提示符
    // editor->setCaretLineVisible(true);// 高亮当前行
    editor->setCaretLineBackgroundColor(QColor(211,211,211));// 设置光标当前行颜色
    editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE, QsciScintilla::SC_CP_UTF8); //设置编码为UTF-8 
    editor->setFolding(QsciScintilla::BoxedTreeFoldStyle);//折叠样式 
    editor->setMarginType(0, QsciScintilla::NumberMargin);//设置左侧行号栏
    editor->setMarginWidth(0, "00"+QString::number(editor->lines()));//设置行号栏宽度

    editor->setMarginsForegroundColor(QColor(0,0,0));// 设置行号栏字体颜色
    editor->setPaper(QColor(0,0,0));//设置背景颜色
    editor->setCaretForegroundColor(QColor(255,255,255));//设置光标颜色
    editor->setCaretWidth(2);//设置光标大小

    //connect
    connect(this,SIGNAL(editor->linesChanged()),this,SLOT(LineChanged()));
}

//slot
void EditorObject::LineChanged(){
    editor->setMarginWidth(0,"00"+QString::number(editor->lines()));//设置行号栏宽度
    return;
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