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

| 平台 | 已收录 | 备注 |
|:---|:---:|:---|
| [Luogu](https://www.luogu.com.cn/) | 375 题 | 主线 |
| [Codeforces](https://codeforces.com/) | 7 题 | 队内训练 |
| [Nowcoder](https://ac.nowcoder.com/) | 3 题 | 牛客练习 |
| [MATIJI](https://www.matiji.net/) | 5 题 | 周/月赛 |
| [PTA](https://pintia.cn/) | 2 题 | 课内平台 |
| [LeetCode](https://leetcode.cn/) | — | 休闲模式 |
| 2026 牛客暑期多校 | 7 场 | 每场按 `场次/题号` 组织 |
| 2026 SHUPC-summer | 3 题 | 个人邀请赛 |
| 2026 上海市赛 | 1 题 | |
| 胜意杯 | 5 题 | |
| 模板库 | 25 个 | `templates/` |

> 统计口径：一个题目文件夹计 1 题，统计于 2026-08-13。

---

## 仓库结构

```
OI/
├── luogu/                          # 洛谷
│   └── P1001/                      # 每题一个文件夹（题号为目录名）
│       ├── P1001.cpp               # 第一版
│       ├── P1001_dp.cpp            # 不同解法（_方法后缀）
│       └── programP1001            # 可执行文件
├── codeforces/                     # Codeforces
├── nowcoder/                       # 牛客
├── matiji/                         # MATIJI
├── pintia/                         # PTA
├── 2026牛客暑期多校/                # 比赛：按场次组织（第一场/B/B.cpp）
├── 2026SHUPC-summer/               # SHUPC 个人邀请赛
├── 2026上海市赛/
├── 胜意杯/
├── templates/                      # 模板库
├── prompts/                        # AI Agent 配置
├── .claude/                        # Claude Code 配置
├── STYLE.md                        # 个人码风文档（供 AI 对齐风格）
└── README.md                       # 本文件
```

---

## 文件命名规范

- 平台文件夹：平台英文小写（`luogu`、`codeforces`、`nowcoder`），比赛用「年份+比赛名」
- 题目文件夹：平台题号（`P1000`、`1742C`）
- 代码文件：
  - `{题号}.cpp` — 第一版（方法隐含）
  - `{题号}_{方法}.cpp` — 同题不同解法，如 `_tree` 树状数组、`_heap` 堆、`_bst` 二分、`_spfa`、`_floyd` 等
  - `_vN` — 同一方法的第 N 次迭代，挂在方法后（`P1000_dp_v2.cpp`）
  - `_rev` — 赛前复习错题时写的版本（`P1000_rev.cpp`，迭代为 `_rev_v2`）
- 可执行文件：`program` + 代码文件名（`programP1000_dp`），与代码文件一一对应

---

## AI Agent 使用

本仓库配套 Trae IDE 智能体，用于辅助代码审查与风格管理：

| Agent | 配置文件 | 用途 |
|-------|----------|------|
| `oi-code-reviewer` | `prompts/AGENT_OI_CODE_REVIEWER.md` | 审查代码、调试 WA/TLE/MLE/RE、讲解思路 |
| `style-writer` | `prompts/AGENT_STYLE_WRITER.md` | 分析代码生成/更新 `STYLE.md` |

### 日常使用

1. **调试bug**：打开 `.cpp` 文件，@oi-code-reviewer 请求审查
2. **更新码风**：@style-writer，指令 `分析 OI/ 文件夹生成 STYLE.md`
3. **风格对齐**：审查前将 `STYLE.md` 贴入对话，让 Agent 按你的习惯诊断

---

## 关于

- 语言标准：C++17
- 每周一次 commit+push 存档（由 Claude Code 自动完成）

---

## 近期目标

- [ ] 持续更新模板库
- [ ] 持续收录趣题
- [ ] 完善题解/复盘记录
