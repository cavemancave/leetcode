# leetcode

# 环境搭建
1. mac切换国内brew源
```bash
chsh -s /bin/zsh #切换成zsh
/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)" #下载homebrew
brew install gdb #安装gdb
```
2. 安装vscode
  1. 安装c++插件，
  2. 面板搜索`shell`安装到bin
  3. 终端创建目录，`mkdir test; code .`
  4. 面板搜索task，创建默认task
  5. 切到debug视图，编辑创建默认launch.json
  6. launch.json里增加前置任务填task名称 `"preLaunchTask": "C/C++: clang build active file"`
  7. 设置json->修改自动化格式为google:`"C_Cpp.clang_format_fallbackStyle": "{ BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}",`
  8. task.json 增加ASAN检测内存错误`"-fsanitize=address",`
  9. 安装remote development插件
  10. linux安装gcc和gdb，连接到vm调试
  
# 动态规划
## 理论和示例


## 相关题目
62 不同路径  


