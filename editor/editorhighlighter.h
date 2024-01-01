/// 处理代码渲染高光的部分

#ifndef EDITORHIGHLIGHTER_H
#define EDITORHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <vector>

class EditorHighlighter : public QSyntaxHighlighter{
    Q_OBJECT
public:
    EditorHighlighter(QTextDocument *parent = nullptr);
protected:
    void highlightBlock(const QString &text) override;
private:
    struct HighlighterRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    std::vector<HighlighterRule> rules;

    QRegularExpression commentStartExpression;//多行注释开始标识符
    QRegularExpression commentEndExpression;//多行注释结束标识符

    QTextCharFormat keywordFormat;//关键字格式
    QTextCharFormat classFormat;//类格式
    QTextCharFormat functionFormat;//函数格式
    QTextCharFormat numberFormat;//数字格式
    QTextCharFormat operatorFormat;//运算符格式
    QTextCharFormat stringFormat;//字符串格式
    QTextCharFormat charFormat;//字符格式

    QTextCharFormat multiLineCommentFormat;//多行注释格式
    QTextCharFormat singleLineCommentFormat;//单行注释格式
};

#endif //EDITORHIGHLIGHTER_H
