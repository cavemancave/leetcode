[toc]
# 本地配置
1. 下载Ubuntu Server 20.0.4镜像，注意不是Desktop版
2. 使能HyperV，第二代，安装Ubuntu Server 20.0.4，注意安全启动选Windows UEFI证书颁发机构；用户名建议和windows一致，这样后面可以少输用户名
3. 使能ssh-agent，避免去git网站新添加秘钥  
3.1 windows使能ssh-agent
 - 设置->应用->可选功能->添加功能-> OpenSSH客户端
 - 管理员权限打开power shell，输入下面命令
```cmd
#启动ssh-agent
Start-Service ssh-agent
Get-Service ssh-agent
#添加秘钥
ssh-add ~\.ssh\id_ed25519
ssh-add -l
#测试
ssh -T git@github.com
#设置开机自动启动
Set-Service ssh-agent -StartupType Automatic 
```
3.2 设置所有主机使能秘钥代理，`~/.ssh/config`添加
```txt
Host *
  ForwardAgent yes
```
3.3 git bash中使能ssh-agent  
修改~/.ssh/.profile每次自动启动或者使用下面的命令手动启动
```bash
eval `ssh-agent -s`
```
4. 设置免密登录
```bash
ssh-copy-id -i ~/.ssh/id_ed25519 taishan@192.168.0.22
ssh 192.168.0.22
```

# 服务端配置
## 配置git
```bash
git clone git@github.com:cavemancave/leetcode.git
git config --global user.email "948238104@qq.com"
git config --global user.name "cavemancave"
```
## 安装编译软件
1. 安装apt-smart来更换apt源
2. 更新系统  `sudo apt upgrade`
3. 安装编译软件
```bash
sudo apt install wget curl gdb g++ gcc lldb llvm git cmake clang libclang-dev liblldb-dev build-essential vsftpd -y
sudo apt install --fix-broken --fix-missing
sudo apt autoremove
```
## 编译lldb-mi
```bash
git clone git@github.com:lldb-tools/lldb-mi.git
cd lldb-mi
cmake .  #预构建
vi /home/taishan/lldb-mi/CMakeFiles/CMakeError.log #查看错误日志,提示缺少signpost.h
cmake --build . #忽略错误，直接构建
find ./ -name lldb-mi #查找构建结果
sudo cp src/lldb-mi /usr/bin

# launch.json中"stopAtEntry"改为true, 调试时发现DEBUG CONSOLE窗口报错：
# ERROR: Unable to start debugging. Unexpected LLDB output from command "-exec-run". process launch failed: unable to locate lldb-server-10.0.0
# 发现vscode只使用文件名lldb-mi-10.0.0和lldb-server-10.0.0，所以创建软连接
cd /usr/bin
sudo cp lldb-mi lldb-mi-10
sudo ln -s lldb-mi-10 lldb-mi-10.0.0
sudo ln -s lldb-server-10 lldb-server-10.0.0
```

# vscode安装Remote-SSH插件远程调试
我一般有2种运行方式：
1. `ctrl+shift+b` 编译，再TERMINAL窗口直接运行`./a.out`
2. 直接F5开始运行，切换到DEBUG窗口看输出

如果发现停在没有断点的地方，清理一下所有的断点：  `Run->Remove all breakpoints`
