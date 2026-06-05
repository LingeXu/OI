# 刷题记录

这里记录着我的OI/ACM成长历程。

---

## 本仓库

主要用来：

1. **存档** — 防止本地代码丢失
2. **复盘** — 偶尔回来看看自己写了些什么, 为日后水帖做准备
3. **记录** — 随缘更新，看到长时间荒废请踢我。

---

## 总览

| OJ | 已解决 | 目标 | 备注 |
|:---|:---:|:---|:---|
| [Luogu](https://www.luogu.com.cn/) | — | — | 主线 |
| [Codeforces](https://codeforces.com/) | — | — | 队内训练 |
| [LeetCode](https://leetcode.cn/) | — | — | 休闲模式 |
| [PTA](https://pintia.cn/) | — | — | 课内平台 |
| [MATIJI](https://www.matiji.net/) | — | — | 周/月赛 |

---

## 仓库结构 

OI/
├── luogu/                          # 洛谷题解
│   ├── P1000/		            # 题号
│   │   ├── P1000.cpp               # 第一版代码
│   │   ├── P1000_v2.cpp            # 迭代版本
│   │   ├── ...
│   │   ├── programP1000            # 可执行文件
│   │   ├── ...
│   └── ...
├── codeforces/                     # Codeforces 题解
│   └── ...
├── STYLE.md                        # 个人码风文档（供 AI Agent 对齐风格）
├── prompts/                  	    # AI Agent 配置
│   ├── AGENT_OI_CODE_REVIEWER.md   # OI 代码审查 Agent 配置
│   └── AGENT_STYLE_WRITER.md       # 码风分析 Agent 配置
└── README.md			    # 本文件

---

## 文件命名规范

- 平台文件夹：使用平台英文小写（`luogu`、`codeforces`、`atcoder`）
- 题目文件夹：使用平台题号（`P1000`、`1742C` 等）
- 代码文件：`{题号}.cpp` 为主版本，`_v2`、`_v3` 等为迭代版本，`_rev`为赛前复习用版本
- 可执行程序：`program{题号}` 为主版本，其余版本的命名规则见代码文件的命名规范

---

## AI Agent 使用

本仓库配套 Trae IDE 智能体，用于辅助代码审查与风格管理：

| Agent | 配置文件 | 用途 |
|-------|----------|------|
| `oi-code-reviewer` | `prompts/AGENT_OI_CODE_REVIEWER.md` | 审查代码、调试 WA/TLE/MLE/RE、讲解思路 |
| `style-writer` | `prompts/AGENT_STYLE_WRITER.md` | 分析代码生成/更新 `STYLE.md` |

---

### 日常使用

1. **调试bug**：打开 `.cpp` 文件，@oi-code-reviewer 请求审查
2. **更新码风**：@style-writer，指令 `分析 OI/ 文件夹生成 STYLE.md`
3. **风格对齐**：审查前将 `STYLE.md` 贴入对话，让 Agent 按你的习惯诊断

---

## 关于

- 语言标准：C++17
- 环境变量：已隐藏

---

## 近期目标

- [ ] 把之前做过的题整理进来
- [ ] 持续更新模板库
- [ ] 持续收录趣题
