这里记录的MySQL的常见命令
同时也是《MySQL技术内幕：InnoDB存储引擎》的学习笔记
第3章 文 件

3.1 参数文件
当MySQL实例启动时，数据库会先去读一个配置参数文件，用来寻找数据库的各种文件所在位置以及指定某些初始化参数，这些参数通常定义了某种内存结构有多大等。
默认情况下，MySQL实例会按照一定的顺序在指定的位置进行读取，用户只需要通过命令mysql --help | grep my.cnf
1. 查看数据库的参数
select * from information_schema.global_variables where variable_name like 'innodb_buffer%';
5.6以后，改为在performance_schema中进行查看
在global_variables表中也可以查询到静态参数,比如：datadir
show variables like 'innodb_buffer%';

在MySQL数据库中，参数分为：
1.动态参数 dynamic
2.静态参数 static

动态参数在MySQL实例进程运行时，可以进行修改
静态参数在整个生命周期内不得进行修改，就好像是只读（read only）。静态参数应该是只能在参数文件中进行修改。

动态参数修改可以使用set命令。
set 
| [global | session] system_var_name = expr
| [@@global. | @@session. | @@] system_var_name = expr

有些参数只能在会话内进行修改 比如：autocommit；有些参数可以全局修改binlog_cache_size read_buffer_size（其他会话也会受影响、或者说是整个实例周期内生效）
set read_buffer_size=524288;
select @@session.read_buffer_size \ G 
show @@seesion.read_buffer_size
select @@global.read_buffer_size;

如果对静态参数进行设置，会报错
set global datadir = '/db/mysql';
