#!/usr/bin/env python3
"""把 templates/templates.txt 生成带目录的 PDF (LaTeX + minted + ctex)。

用法: python3 tools/templates2pdf.py
产物: templates/templates.pdf
依赖: xelatex / latexmk (TeX Live), pygments (pip install pygments)

原理: 按各模板的标题注释行把 templates.txt 切成小节,
按「章节 -> 小节」两级目录排版, minted 做 C++ 高亮。
修改模板后重新运行即可; 新增模板时在 SECTIONS 里按文件顺序补一行即可。
"""
import os
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TXT = os.path.join(ROOT, "templates", "templates.txt")
OUT = os.path.join(ROOT, "templates", "templates.pdf")

# (标题注释行前缀, 目录标题, 所属章节), 顺序需与 templates.txt 中的出现顺序一致
SECTIONS = [
    ("//二分答案",         "二分答案",             "基础技巧"),
    ("//stl二分",          "STL 二分",             "基础技巧"),
    ("//步长二分",         "步长二分",             "基础技巧"),
    ("//双指针",           "双指针 / 尺取",        "基础技巧"),
    ("//三分",             "三分搜索",             "基础技巧"),
    ("//前缀和 + 哈希",    "前缀和 + 哈希",        "基础技巧"),
    ("//曼哈顿距离",       "曼哈顿与切比雪夫变换", "基础技巧"),
    ("//lambda自定义比较", "Lambda 自定义比较",    "基础技巧"),
    ("//区间窗口相交",     "区间窗口相交",         "基础技巧"),
    ("//多组数据与时间戳", "多组数据与时间戳",     "基础技巧"),
    ("//01背包",           "01 / 完全 / 多重背包", "动态规划"),
    ("//区间DP",           "区间 DP",              "动态规划"),
    ("//数位DP",           "数位 DP",              "动态规划"),
    ("//状压DP",           "状压 DP",              "动态规划"),
    ("//树形背包",         "树形背包",             "动态规划"),
    ("//字符串处理",       "字符串处理",           "基础技巧"),
    ("//dijkstra",         "Dijkstra 最短路",      "图论"),
    ("//spfa",             "SPFA（判负环 / 差分约束）", "图论"),
    ("//拓扑排序",         "拓扑排序",             "图论"),
    ("//bellmanford",      "Bellman-Ford",         "图论"),
    ("//并查集",           "并查集",               "图论"),
    ("//kruskal",          "Kruskal 最小生成树",   "图论"),
    ("//floyd",            "Floyd 全源最短路",     "图论"),
    ("//最长上升子序列LIS", "LIS 最长上升子序列",  "动态规划"),
    ("//最长公共子序列LCS", "LCS 最长公共子序列",  "动态规划"),
    ("//换根DP",           "换根 DP",              "动态规划"),
    ("//快速幂",           "快速幂",               "数学"),
    ("//组合数",           "组合数 / 卢卡斯定理",  "数学"),
    ("//矩阵快速幂",       "矩阵快速幂",           "数学"),
    ("//马拉车",           "Manacher 马拉车",      "字符串"),
    ("//Z函数",            "Z 函数",               "字符串"),
    ("//字符串哈希",       "字符串哈希",           "字符串"),
    ("//最小表示法",       "最小表示法",           "字符串"),
    ("//欧拉筛",           "欧拉筛",               "数学"),
    ("//线性筛",           "线性筛求积性函数",     "数学"),
    ("//树的直径",         "树的直径",             "图论"),
    ("//LCA",              "LCA 与树上差分",       "图论"),
    ("//树链剖分",         "树链剖分",             "图论"),
    ("//DSU on tree",      "DSU on tree 树上启发式合并", "图论"),
    ("//点分治",           "点分治",               "图论"),
    ("//带权并查集",       "带权并查集",           "图论"),
    ("//树上最大独立集",   "树上最大独立集",       "动态规划"),
    ("//Tarjan",           "Tarjan（SCC / 割点 / 桥 / 2-SAT）", "图论"),
    ("//二分图",           "二分图与匈牙利",       "图论"),
    ("//线段树",           "线段树（区间加 / 双 lazy / 二分）", "数据结构"),
    ("//ST表",             "ST 表",                "数据结构"),
    ("//单调栈",           "单调栈",               "数据结构"),
    ("//单调队列",         "单调队列",             "数据结构"),
    ("//离散化",           "离散化",               "数据结构"),
    ("//二维前缀和",       "二维前缀和与差分",     "数据结构"),
    ("//最大公约数",       "gcd 最大公约数",       "数学"),
    ("//KMP",              "KMP",                  "字符串"),
    ("//trie",             "Trie 字典树",          "字符串"),
    ("//AC自动机",         "AC 自动机",            "字符串"),
    ("//树状数组",         "树状数组（含第 k 小）", "数据结构"),
    ("//莫队",             "莫队",                 "数据结构"),
    ("//逆序对",           "逆序对",               "数据结构"),
    ("//扫描线",           "扫描线 + 线段树",      "数据结构"),
    ("//主席树",           "主席树",               "数据结构"),
    ("//分块",             "分块",                 "数据结构"),
    ("//扩展欧几里得",     "扩展欧几里得",         "数学"),
    ("//逆元",             "逆元",                 "数学"),
    ("//中国剩余定理",     "CRT / exCRT 中国剩余定理", "数学"),
    ("//高斯消元",         "高斯消元",             "数学"),
    ("//线性基",           "线性基",               "数学"),
    ("//Miller-Rabin",     "Miller-Rabin 素数判定", "数学"),
    ("//Dinic",            "Dinic 最大流",         "网络流"),
    ("//最小费用最大流",   "费用流 MCMF",          "网络流"),
    ("//计算几何基础",     "计算几何基础",         "计算几何"),
]


def parse_sections():
    with open(TXT, encoding="utf-8") as f:
        lines = f.read().splitlines()
    pos = []
    for marker, _, _ in SECTIONS:
        hits = [i for i, ln in enumerate(lines) if ln.startswith(marker)]
        assert len(hits) == 1, f"标记 {marker!r} 应恰好命中 1 行, 实际 {len(hits)} 行"
        pos.append(hits[0])
    assert pos == sorted(pos), "SECTIONS 顺序与 templates.txt 不一致, 请按文件顺序调整"
    result = []
    for k, (_, title, cat) in enumerate(SECTIONS):
        start = pos[k]
        end = pos[k + 1] if k + 1 < len(pos) else len(lines)
        result.append((title, cat, lines[start:end]))
    return result


def build_tex(sections):
    body = []
    body.append(r"""\documentclass[11pt,a4paper,fontset=none]{ctexart}
\usepackage[top=2.2cm,bottom=2.2cm,left=1.8cm,right=1.8cm]{geometry}
\usepackage{minted}
\usepackage[hidelinks]{hyperref}
\usepackage{xcolor}

% macOS 新版系统缺少 Kaiti SC / STFangsong, 故不用 ctex 默认 macnew 字体集, 手动指定
\setCJKmainfont{Songti SC}[BoldFont={Songti SC Bold}]
\setCJKsansfont{STHeiti Medium}
\setCJKmonofont{Songti SC}

\setminted[cpp]{
    fontsize=\footnotesize,
    breaklines=true,
    breakanywhere=true,
    breakautoindent=false,
    tabsize=4,
    frame=single,
    framesep=4pt,
    rulecolor=\color{gray!40},
    style=vs,
}

\title{\textbf{算法竞赛模板}}
\author{}
\date{2026 年 10 月 · 区域赛}
\begin{document}
\maketitle
\tableofcontents
\newpage
""")
    cat_order = ["基础技巧", "动态规划", "图论", "数据结构", "字符串", "数学", "网络流", "计算几何"]
    for cat in cat_order:
        body.append(f"\\section{{{cat}}}\n")
        for title, c, content in sections:
            if c != cat:
                continue
            body.append(f"\\subsection{{{title}}}\n")
            body.append(r"\begin{minted}{cpp}")
            body.extend(content)
            body.append(r"\end{minted}")
            body.append("")
    body.append(r"\end{document}")
    return "\n".join(body)


def main():
    sections = parse_sections()
    tex = build_tex(sections)
    build_dir = tempfile.mkdtemp(prefix="tmpl_pdf_")
    tex_path = os.path.join(build_dir, "templates.tex")
    with open(tex_path, "w", encoding="utf-8") as f:
        f.write(tex)
    print(f"[1/2] 解析 templates.txt -> {len(sections)} 个模板小节")
    print(f"[2/2] 编译 PDF (latexmk -xelatex -shell-escape) ...")
    subprocess.run(
        ["latexmk", "-xelatex", "-shell-escape", "-interaction=nonstopmode",
         "-halt-on-error", "templates.tex"],
        cwd=build_dir, check=True)
    shutil.copy(os.path.join(build_dir, "templates.pdf"), OUT)
    shutil.rmtree(build_dir, ignore_errors=True)
    print(f"完成: {OUT}")


if __name__ == "__main__":
    sys.exit(main())
