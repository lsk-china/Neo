#include "editorhighlighter.h"

EditorHighlighter::EditorHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent){}
void EditorHighlighter::highlightBlock(const QString &text) {};