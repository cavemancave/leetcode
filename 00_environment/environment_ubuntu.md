主要工作环境是Windows 10，本地安装ubuntu虚拟机，使用vscode远程开发调试
# 本地安装ubuntu虚拟机
1. 下载Ubuntu Server 20.0.4镜像，注意不是Desktop版
2. 使能HyperV，第二代，安装Ubuntu Server 20.0.4，注意安全启动选Windows UEFI证书颁发机构；用户名建议和windows一致，这样后面可以少输用户名
3. 使能ssh-agent，避免去git网站新添加秘钥
管理员权限打开power shell，输入下面命令
```cmd
# 如果ssh命令可以敲出来，就不用安装
Install-Module -Force OpenSSHUtils -Scope AllUsers
#设置开机自动启动
Set-Service ssh-agent -StartupType Automatic 
Start-Service ssh-agent
Get-Service ssh-agent
#添加秘钥
ssh-add ~\.ssh\id_rsa
ssh-add -l
#测试，warning可以忽略
ssh -T git@github.com
```
4. 设置免密登录
ssh-copy-id taishan@192.168.0.22
ssh 192.168.0.22

# 安装编译软件
1. 安装apt-smart来更换apt源
2. 更新系统
sudo apt upgrade
3. 安装编译软件
sudo apt install wget curl gdb g++ gcc lldb llvm git cmake clang libclang-dev liblldb-dev build-essential vsftpd -y
sudo apt install --fix-broken --fix-missing
sudo apt autoremove

# 配置git
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

# vscode安装Remote-SSH插件远程调试
