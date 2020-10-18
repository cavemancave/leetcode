# 初始操作
vmware15Player Ubuntu20.0.4 
最小化安装
software 更新，选择其他软件源，选择最快的安装源
sudo apt-get install open-vm-tools-desktop -y #安装vmware工具
sudo apt install openssh-service -y #安装ssh服务端
sudo systemctl start sshd 
sudo systemctl enable sshd 
然后就可以用其他喜欢的终端登录了
ssh-copy-id root@192.168.0.3 #免密登陆

# 安装编译软件
sudo apt upgrade
sudo apt install wget curl gdb g++ gcc lldb llvm git cmake clang libclang-dev liblldb-dev build-essential vsftpd -y
sudo apt install --fix-broken --fix-missing
sudo apt autoremove

# 配置git
ssh-keygen -t rsa 
cat ~/.ssh/id_rsa.pub 
网站添加公钥
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

# 安装vscode
sudo snap install --classic code 

# 虚拟机里调试或者vscode里安装Remote-SSH插件远程调试
