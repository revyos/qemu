==========================
cskysim
==========================

cskysim 是 T-HEAD 为了简化 XuanTie QEMU 系统模式使用，提供的一个 QEMU 启动程序。
cskysim 用 xml 文件整合了常用的 QEMU 参数，为用户提供了 XuanTie 虚拟环境的典型参数。
另外，cskysim 跟 QMEU 配合，还提供了动态加载外设等功能。

------------------
Linux 平台下的使用
------------------

Linux的安装目录下，lib/qemu 中，可以找到默认的 xml 文件，这些文件提供了通用的 cskysim 配置。

以运行 C-SKY Linux 内核为例，可以用 -soc 参数指定 xml 配置文件，用 -kernel 指定 Linux 内核 elf 文件。如果需要调整 QEMU 参数，可以修改 xml 文件，或者直接在命令行后直接加更多的 QEMU 参数。

.. code-block:: none

    cskysim -soc lib/qemu/soccfg/cskyv2/dummyh_cfg.xml -kernel path/of/bin/vmlinux

在弹出窗口中，通过菜单栏 view->serial0 切换到串口，就可以看到打印输出。

如果要直接在终端输出，命令行之后追加 nographic 即可。

.. code-block:: none

    cskysim -soc lib/qemu/soccfg/cskyv2/dummyh_cfg.xml -kernel path/of/bin/vmlinux -nographic

--------------------
Windows 平台下的使用
--------------------

windows 下 qemu 动态插件使用与 linux 类似，不同的只是动态库文件从so变成了dll。
windows 安装后目录组成与 linux 类似，默认位于 C:\\Program Files (x86)\\C-Sky 下。

以运行 C-SKY Linux 内核为例，-soc 参数指定 xml 配置文件，其他参数用法与 QEMU 相同。弹出窗口后，通过菜单栏 view->serial0 切换到串口，就可以看到打印输出。

.. code-block:: none

  cskysim.exe -soc soccfg\cskyv2\dummyh_cfg.xml -kernel path\of\bin\vmlinux

如果要直接在终端输出，需要先设置 SDL 库的环境变量 SDL_STDIO_REDIRECT=no , 命令行之后再追加 nographic 选项。

.. code-block:: none

  set SDL_STDIO_REDIRECT=no
  cskysim.exe -soc soccfg\cskyv2\dummyh_cfg.xml -kernel path\of\bin\vmlinux -nographic

对 cskysim 中 xml 文件的详细说明，可以参考《dynsoc开发手册》
