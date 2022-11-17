
# -*- coding: utf-8 -*-
#
# Configuration file for the Sphinx documentation builder.
#

# -- Project information

project = u'XuanTie QEMU user guide'
author = u'T-HEAD'
copyright = 'copyright'

# -- General configuration

extensions = [
]
templates_path = ['_templates']
source_suffix = '.rst'
master_doc = 'index'
language = u'zh_CN'
exclude_patterns = []
pygments_style = 'sphinx'
numfig = True

# -- Options for HTML output

html_theme = 'alabaster'
html_static_path = ['_static']

# -- Options for HTMLHelp output

htmlhelp_basename = 'cksim-doc'

# -- Options for LaTeX output

latex_engine = 'xelatex'

latex_elements = {

	'preamble': r'''
\usepackage[UTF8, heading = true]{ctex}
\setlength{\parindent}{2em}
\hypersetup{bookmarksnumbered = true}
\setcounter{secnumdepth}{3}
\usepackage{graphicx}
\usepackage{multirow}
\makeatletter
    \fancypagestyle{normal}{
        \fancyhf{}
        \fancyfoot[R]{\thepage}
        \fancyfoot[L]{\py@release}
        \fancyfoot[C]{\fontsize{7}{7} \selectfont Copyright \textcopyright\ 2020 T-HEAD Semiconductor Co.,Ltd. All rights reserved.}
        \fancyhead[L]{\includegraphics[scale=0.4] {theadlog.png}}
        \fancyhead[R]{\py@HeaderFamily \nouppercase{\leftmark}}
     }
\makeatother
	''',
	'classoptions': ',oneside',
	'maketitle': ur'''
\maketitle

\small \textbf{Copyright © 2020 平头哥半导体有限公司，保留所有权利。}

本文档的产权属于平头哥半导体有限公司(下称“平头哥”)。本文档仅能分布给:(i)拥有合法雇佣关系，
并需要本文档的信息的平头哥员工，或(ii)非平头哥组织但拥有合法合作关系，
并且其需要本文档的信息的合作方。对于本文档，禁止任何在专利、版权或商业秘密过程中，
授予或暗示的可以使用该文档。在没有得到平头哥半导体有限公司的书面许可前，
不得复制本文档的任何部分，传播、转录、储存在检索系统中或翻译成任何语言或计算机语言。

\textbf{商标申明}

平头哥的LOGO和其它所有商标归平头哥半导体有限公司及其关联公司所有，未经平头哥半导体有限公司的书面同意，
任何法律实体不得使用平头哥的商标或者商业标识。

\textbf{注意}

您购买的产品、服务或特性等应受平头哥商业合同和条款的约束，
本文档中描述的全部或部分产品、服务或特性可能不在您的购买或使用范围之内。
除非合同另有约定，平头哥对本文档内容不做任何明示或默示的声明或保证。
由于产品版本升级或其他原因，本文档内容会不定期进行更新。
除非另有约定，本文档仅作为使用指导，本文档中的所有陈述、信息和建议不构成任何明示或暗示的担保。
平头哥半导体有限公司不对任何第三方使用本文档产生的损失承担任何法律责任。

\vspace{10pt}

\textbf{Copyright © 2021 T-HEAD Semiconductor Co.,Ltd. All rights reserved.}

This document is the property of T-HEAD Semiconductor Co.,Ltd.
This document may only be distributed to: (i) a T-HEAD party having a
legitimate business need for the information contained herein,
or (ii) a non-T-HEAD party having a legitimate business need for the
information contained herein.  No license, expressed or implied,
under any patent, copyright or trade secret right is granted or
implied by the conveyance of this document. No part of this document
may be reproduced, transmitted, transcribed, stored in a retrieval system,
translated into any language or computer language, in any form or by any means,
electronic, mechanical, magnetic, optical, chemical, manual, or otherwise
without the prior written permission of T-HEAD Semiconductor Co.,Ltd.

\textbf{Trademarks and Permissions}

The T-HEAD Logo and all other trademarks indicated as such herein
are trademarks of Hangzhou T-HEAD Semiconductor Co.,Ltd. All other
products or service names are the property of their respective owners.

\textbf{Notice}

The purchased products, services and features are stipulated by
the contract made between T-HEAD and the customer. All or part of the
products, services and features described in this document may not be
within the purchase scope or the usage scope. Unless otherwise specified
in the contract, all statements, information, and recommendations in
this document are provided "AS IS" without warranties, guarantees or
representations of any kind, either express or implied.
The information in this document is subject to change without notice.
Every effort has been made in the preparation of this document
to ensure accuracy of the contents, but all statements,
information, and recommendations in this document do not constitute
a warranty of any kind, express or implied.

\vspace{20pt}

平头哥半导体有限公司 T-HEAD Semiconductor Co.,LTD

地址: 杭州市余杭区向往街1122号欧美金融城(EFC)英国中心西楼T6

邮编: 311121

网址:  www.t-head.cn

	''',

}

latex_additional_files = ["_static/theadlog.png"]

latex_documents = [
    (master_doc, u'XuanTie_QEMU_User_Guide.tex', u'XuanTie QEMU 用户手册',
     u'Release v3.8', 'manual'),
]

# -- Options for Texinfo output

texinfo_documents = [
    (master_doc, 'cksim', u'cksim Documentation',
     author, 'cksim', 'One line description of project.',
     'Miscellaneous'),
]
