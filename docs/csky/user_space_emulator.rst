==========================
XuanTie QEMU 用户模式
==========================

------------
简介
------------

XuanTie QEMU 用户模式是提供 XuanTie Linux 应用程序执行环境的一个模式。允许直接执行绝大多数 XuanTie Linux 应用程序。

-------------------
从源码编译
-------------------

这节，以从源码编译 ABIV2 的 C-SKY 用户模式为例，描述了如何从源码编译 C-SKY 用户模式。


**编译：**

.. code-block:: none

  mkdir build
  ../configure --target-list=cskyv2-linux-user
  make

编译RISC-V 用户模式。

**编译：**

.. code-block:: none

  mkdir build
  ../configure --target-list=riscv64-linux-user
  make

如果需要安装可执行程序到本机执行目录，则可以 **安装：**

.. code-block:: none

  make install


-----------------
用户模式简易示例
-----------------

**用户模拟** 是 XuanTie QEMU 模拟 Linux 程序执行环境的模式。

以仅有 ``hello world`` 打印的 main.c 为例。

如果程序正常执行，将在终端上输出 ``hello world``，否则会出现错误信息，甚至没有任何提示。

.. code-block:: none

  qemu-cskyv2 /path/of/a.out


-----------------
使用 gdb 调试
-----------------

下面仍然以 XuanTie QEMU 运行 ``hello world`` 示例程序为例，来说明如何在使用 GDB 来调试 QEMU 上执行的程序。

QEMU 使用与上例类似参数，并追加调试的参数，打开端口 23333， 等待远程 GDB 调试终端链接，具体如下命令：

.. code-block:: none

  qemu-cskyv2 -g 23333 /path/of/a.out

如上，QEMU 在等待远程连接到端口23333。 从其他命令行窗口中，用 csky-gdb 接需要调试的 elf 文件：

.. code-block:: none

  csky-abiv2-elf-gdb /path/of/a.out


在 GDB 的提示后，输入以下命令连接 QEMU：

.. code-block:: none

  (cskygdb) target remote localhost:23333

本例当中 GDB 连接的端口是由参数 -g 23333 指定为 23333。

接下来便可以与调试普通 Linux 应用程序一样使用 GDB 进行调试了。例如设断点，单步执行，查看寄存器值等操作。

-----------------
RISC-V 用户模式
-----------------

对于RISC-V 用户模式程序，模拟器需要换成qemu-riscv64, 调试器需要换成riscv64-unknown-linux-gnu-gdb。
