主要工作环境是Windows 10，本地安装ubuntu虚拟机，使用vscode远程开发调试
# 本地安装ubuntu虚拟机
1. 下载Ubuntu Server 20.0.4镜像，注意不是Desktop版
2. 使能HyperV，第二代，安装Ubuntu Server 20.0.4，注意安全启动选Windows UEFI证书颁发机构；用户名建议和windows一致，这样后面可以少输用户名
3. 设置免密登录ssh-copy-id taishan@192.168.0.3，然后退回到windows使用git bash登录
4. 安装apt-smart来更换apt源, 更新系统

# 安装编译软件
sudo apt upgrade
sudo apt install wget curl gdb g++ gcc lldb llvm git cmake clang libclang-dev liblldb-dev build-essential vsftpd -y
sudo apt install --fix-broken --fix-missing
sudo apt autoremove

# 配置git
1. windows设置ssh-agent使能，避免去git网站新添加秘钥，我创建的是.profile，（不建议.bashrc，创建后还会再额外创建其他profile文件）。不过git提交和拉取动作需要git bash操作，vscode自带的bash不行。
[Using SSH agent forwarding
](https://docs.github.com/en/developers/overview/using-ssh-agent-forwarding)
[auto-launching-ssh-agent-on-git-for-windows](https://docs.github.com/en/github/authenticating-to-github/working-with-ssh-key-passphrases#auto-launching-ssh-agent-on-git-for-windows)

git clone git@github.com:cavemancave/leetcode.git
git config --global user.email "948238104@qq.com"
git config --global user.name "cavemancave"

# 编译lldb-mi
```bash
git clone https://g.ioiox.com/https://github.com/lldb-tools/lldb-mi.git 
cd lldb-mi
cmake .  #预构建
vi /home/taishan/lldb-mi/CMakeFiles/CMakeError.log #查看错误日志,提示缺少signpost.h
cmake --build . #忽略错误，直接构建
find ./ -name lldb-mi #查找构建结果
#将构建结果拷贝到/usr/bin，/usr/bin/lldb-mi已经存在，但是不存在链接目标，直接拷贝成目标
sudo cp ~/lldb-mi/src/lldb-mi /usr/bin/lldb-mi-10
# vscode只使用lldb-mi-10.0.0
sudo ln -s lldb-mi-10 lldb-mi-10.0.0
# 如果没有lldb-server-10.0.0，也要创建
sudo ln -s lldb-server-10 lldb-server-10.0.0
```

# 虚拟机里调试或者vscode里安装Remote-SSH插件远程调试
