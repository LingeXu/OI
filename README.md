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
| [Luogu](https://www.luogu.com.cn/) | 394 题 | 主线 |
| [Codeforces](https://codeforces.com/) | 16 题 | 队内训练 |
| [Nowcoder](https://ac.nowcoder.com/) | 4 题 | 牛客练习 |
| [MATIJI](https://www.matiji.net/) | 5 题 | 周/月赛 |
| [PTA](https://pintia.cn/) | 17 题 | 课内平台，按 `L1`/`L2` 分级存放 |
| [LeetCode](https://leetcode.cn/) | — | 休闲模式 |
| 2026 牛客暑期多校 | 8 场 | 每场按 `场次/题号` 组织 |
| 2026 SHUPC-summer | 3 题 | 个人邀请赛 |
| 2026 上海市赛 | 1 题 | |
| 2026 集训队个人赛 | 4 场 | 按 `日期/题号` 组织 |
| 胜意杯 | 5 题 | |
| VP（CF 补题） | 8 场 | `VP/Div2/<round>/`，按题号字母平铺 |
| 2026 ICPC Asia EC | 2 题 | `2026_ICPC_Asia_EC/` |
| 模板库 | 24 个 | `templates/` |

> 统计口径：一个题目文件夹计 1 题，统计于 2026-09-10。

---

## 仓库结构

```
OI/
├── luogu/                          # 洛谷
│   └── P1001/                      # 每题一个文件夹（题号为目录名）
│       ├── P1001.cpp               # 第一版
│       ├── P1001_dp.cpp            # 不同解法（_方法后缀）
│       ├── programP1001            # 可执行文件（本地生成，已被 .gitignore 忽略，不入库）
│       └── .cph/                   # cph 测试点缓存（本地保留，不入库）
├── codeforces/                     # Codeforces
├── nowcoder/                       # 牛客
├── matiji/                         # MATIJI
├── pintia/                         # PTA（内含 L1/、L2/ 两级）
├── 2026牛客暑期多校/                # 比赛：按场次组织（第一场/B/B.cpp）
├── 2026.8.21集训队个人赛/           # 集训队个人赛：按日期组织（A/A.cpp）
├── 2026.9.1集训队个人赛/
├── 2026.9.3集训队个人赛/
├── 2026.9.5集训队个人赛/
├── 2026SHUPC-summer/               # SHUPC 个人邀请赛
├── 2026上海市赛/
├── 2026_ICPC_Asia_EC/              # ICPC 区域赛：按题号组织
├── VP/                             # CF 补题：VP/Div2/<round>/，题号字母平铺
├── 胜意杯/
├── templates/                      # 模板库
├── tools/                          # 工具脚本（cph 归档等）
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
  - `_final` — PTA 课程提交定稿版（`L2-011_final.cpp`）
- 可执行文件：`program` + 代码文件名（`programP1000_dp`），与代码文件一一对应
- 本地产物不入库：可执行文件与 `.cph/` 测试点均已被 `.gitignore` 忽略，仅保留在本地

---

## cph 工作流

本仓库配合 [cph](https://marketplace.visualstudio.com/items?itemName=DivyanshuAgrawal.competitive-programming-helper)（VS Code 插件）+ [Competitive Companion](https://github.com/jmerle/competitive-companion)（浏览器扩展，端口 27121 自动配对）使用：

- **关键设置**：`useShortLuoguName` / `useShortCodeForcesName` 开启（生成 `P1001.cpp`、`2209D.cpp` 风格短文件名，与仓库命名一致）；`timeOut` 3000ms
- **日常流程**：
  1. 浏览器打开题目页 → 点绿色「+」图标（或 `Ctrl+Shift+U`）
  2. cph 自动创建源文件并载入样例 → 写题
  3. `Ctrl+Alt+B` 编译并跑全部样例
  4. 通过后归档：`python3 tools/cph_archive.py <文件.cpp>`（自动归类到平台目录并迁移测试点；重名自动 `_vN`；比赛补题用 `--target` 指定目录）
- **旧题重跑**：直接打开旧 `.cpp` 即可；无测试点时 `Ctrl+Alt+B` 新建本地测试点手动填样例，或在 Judge 面板 Import Testcases 导入 `[{ "input": "...", "output": "..." }]` JSON
- 测试点保存在源文件旁的 `.cph/` 目录，已加入 `.gitignore`：留在本地即可让旧题随时重跑，不入库

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
