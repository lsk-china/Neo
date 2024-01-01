/// 负责定义界面样式、编译服务、软件设置等
#ifndef USERCONFIG_H
#define USERCONFIG_H

#include<string>

struct UserConfig
{
    /// @brief MainWindow样式定义
    std::string MainWindowBackgroundColor;
    std::string MainWindowBackgroundImage;
    std::string MainWindowFont;
    std::string MainWindowFontSize;

    /// @brief Editor样式定义
    std::string EditorBackgroundColor;
    std::string EditorFont;
    std::string EditorFontSize;

    // 字体渲染
    std::string EditorNumberFontColor;
    std::string EditorFunctionFontColor;
    std::string EditorCommonFontColor;
    std::string EditorStringFontColor;
    std::string EditorKeywordFontColor;
    std::string EditorOperatorFontColor;
    std::string EditorCharFontColor;
    // 未渲染的字体
    std::string EditorUnrenderedTextColor;
    // 文件路径渲染使用另一种颜色
    std::string EditorFilePath;

    // 字体行距
    int EditorLineHeight;
    //是否使用连体,true是使用，false是不使用
    bool EditorUseLigatures;

    /// @brief 软件设置
    //TODO
};

#endif // USERCONFIG_H