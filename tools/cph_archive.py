#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
cph 归档脚本：把 cph（Competitive Programming Helper）新建的题目文件
按平台归类归档到仓库对应目录，并同步迁移其测试点（.cph/*.prob），
归档后的旧题仍可在 cph 中直接重跑（测试点与文件绝对路径 md5 绑定）。

用法:
  python3 tools/cph_archive.py <源文件.cpp> [选项]

选项:
  --target DIR    目标目录（比赛/补题归档用，如 --target VP/Div2/1087），覆盖自动平台判断
  --name NAME     目标文件名（不含 .cpp），覆盖自动生成
  --id ID         题号，覆盖从 .prob url / 文件名推断的结果
  --method 方法   生成 {题号}_{方法}.cpp（如 dp、tree）
  --yes           目标已存在时自动取下一个 _vN，不询问
  --dry-run       只打印将执行的操作，不移动任何文件

示例:
  python3 tools/cph_archive.py D_Ghostfires.cpp             # 按 .prob url 自动归到 codeforces/2209D/
  python3 tools/cph_archive.py A.cpp --target VP/Div2/1087  # VP 补题（单字母题号，平铺）
  python3 tools/cph_archive.py P1001.cpp --method dp        # 洛谷 + 方法后缀
  python3 tools/cph_archive.py L2-011.cpp                   # PTA 自动归入 pintia/L2/L2-011/
"""

import argparse
import hashlib
import json
import os
import re
import shutil
import sys

# 已知方法后缀（_vN / _rev / _final 之外的）
METHOD_SUFFIXES = ["dp", "tree", "heap", "bst", "spfa", "floyd", "trie", "pq", "dsu"]


def md5_abs(path):
    """与 cph 一致的路径哈希：md5(绝对路径字符串)"""
    return hashlib.md5(os.path.abspath(path).encode("utf-8")).hexdigest()


def find_prob(src_abs):
    """在源文件所在目录的 .cph/ 中按 srcPath 匹配 .prob，返回 (路径, JSON)。"""
    cph_dir = os.path.join(os.path.dirname(src_abs), ".cph")
    matches = []
    if os.path.isdir(cph_dir):
        for name in os.listdir(cph_dir):
            if not name.endswith(".prob"):
                continue
            p = os.path.join(cph_dir, name)
            try:
                with open(p, encoding="utf-8") as f:
                    data = json.load(f)
            except Exception:
                continue
            if data.get("srcPath") == src_abs:
                matches.append((p, data))
    if len(matches) > 1:
        print(f"[错误] 找到 {len(matches)} 个 srcPath 相同的 .prob，请手动处理：", file=sys.stderr)
        for p, _ in matches:
            print(f"  - {p}", file=sys.stderr)
        sys.exit(2)
    return matches[0] if matches else (None, None)


def find_repo_root(start):
    """从给定路径向上找 .git 所在目录，找不到返回 None。"""
    d = os.path.abspath(start)
    while True:
        if os.path.isdir(os.path.join(d, ".git")) or os.path.isfile(os.path.join(d, ".git")):
            return d
        parent = os.path.dirname(d)
        if parent == d:
            return None
        d = parent


def strip_suffixes(base):
    """剥离 _vN / _rev(_vN) / _final / 已知方法后缀，返回 (题号, 方法)。未知后缀保留在题号中。"""
    method = None
    m = re.match(r"^(.*?)_(v\d+)$", base)          # _v2 / _v3 ...
    if m:
        base = m.group(1)
    m = re.match(r"^(.*)_(rev(?:_v\d+)?)$", base)  # _rev / _rev_v2
    if m:
        base = m.group(1)
    m = re.match(r"^(.*)_final$", base)            # PTA 课程定稿版
    if m:
        base = m.group(1)
    m = re.match(r"^(.*?)_(%s)$" % "|".join(METHOD_SUFFIXES), base)
    if m:
        base, method = m.group(1), m.group(2)
    return base, method


def detect_platform(prob, filename, id_override=None):
    """返回 (平台目录名, 题号, 方法)。--id 显式指定时优先；平台目录名 pintia 时题号形如 L2-011。"""
    url = (prob or {}).get("url") or ""
    base = os.path.splitext(os.path.basename(filename))[0]
    base, method = strip_suffixes(base)
    cand = id_override  # 显式指定的题号，优先于一切推断

    if "luogu.com.cn" in url:
        m = re.search(r"problem/(\w+)", url)
        return "luogu", (cand or (m.group(1) if m else base)), method
    if "codeforces.com" in url:
        # contest/2209/problem/D 或 problemset/problem/2209/D 或 gym/...
        m = re.search(r"(?:contest|problemset/problem|gym)/(\d+)/problem/([A-Z]\d*)", url)
        return "codeforces", (cand or (m.group(1) + m.group(2) if m else base)), method
    if "ac.nowcoder.com" in url:
        return "nowcoder", (cand or base), method
    if "matiji.net" in url:
        return "matiji", (cand or base), method
    if "pintia.cn" in url:
        if not re.match(r"^L\d-", cand or base):
            print(f"[错误] PTA 题号需形如 L2-011，无法从文件名（{base}）提取，请用 --id 指定", file=sys.stderr)
            sys.exit(2)
        return "pintia", (cand or base), method

    # 无 .prob 或未知平台：按题号/文件名前缀猜
    guess = cand or base
    if re.match(r"^[PB]\d+$", guess) or re.match(r"^CF\d+$", guess) \
            or re.match(r"^UVA\d+$", guess) or re.match(r"^T\d+$", guess):
        return "luogu", guess, method
    if re.match(r"^\d+[A-Z]\d*$", guess):
        return "codeforces", guess, method
    if re.match(r"^NC\d+$", guess):
        return "nowcoder", guess, method
    if re.match(r"^MC\d+$", guess):
        return "matiji", guess, method
    if re.match(r"^L\d-\d+$", guess):
        return "pintia", guess, method
    print(f"[错误] 无法从 .prob 或文件名推断平台/题号（{guess}），请用 --target 或 --id 指定", file=sys.stderr)
    sys.exit(2)


def pick_free_vn(directory, stem):
    """返回第一个空闲的 stem_vN（N>=2）；v1 不存在是仓库约定。"""
    n = 2
    while os.path.exists(os.path.join(directory, f"{stem}_v{n}.cpp")):
        n += 1
    return n


def main():
    parser = argparse.ArgumentParser(
        description="把 cph 新建的题目文件按平台归类归档，并迁移其测试点（.cph/*.prob）。",
        epilog="示例: python3 tools/cph_archive.py D_Ghostfires.cpp",
    )
    parser.add_argument("source", help="cph 生成的源文件（.cpp）")
    parser.add_argument("--target", help="目标目录（覆盖自动平台判断），如 VP/Div2/1087")
    parser.add_argument("--name", help="目标文件名（不含 .cpp）")
    parser.add_argument("--id", help="题号（覆盖自动推断）")
    parser.add_argument("--method", help="方法后缀，生成 {题号}_{方法}.cpp")
    parser.add_argument("--yes", action="store_true", help="目标已存在时自动取下一个 _vN")
    parser.add_argument("--dry-run", action="store_true", help="只打印将执行的操作")
    args = parser.parse_args()

    src_abs = os.path.abspath(args.source)
    if not os.path.isfile(src_abs):
        print(f"[错误] 源文件不存在: {src_abs}", file=sys.stderr)
        sys.exit(2)
    if not src_abs.endswith(".cpp"):
        print("[错误] 仅支持 .cpp 文件", file=sys.stderr)
        sys.exit(2)

    prob_path, prob = find_prob(src_abs)
    if prob is None:
        print("[警告] 未找到匹配的测试点（.cph/*.prob），将仅移动源码", file=sys.stderr)

    # ---- 确定目标目录与文件名 ----
    if args.target:
        target_dir = os.path.abspath(args.target)
        base = os.path.splitext(os.path.basename(src_abs))[0]
        pid, method = strip_suffixes(base)
        pid = args.id or args.name or pid
        # 2209D 这类带场次前缀的题号在比赛目录里习惯去掉前缀（VP 平铺字母）
        m = re.match(r"^\d+([A-Z]\d*)$", pid)
        if m and not args.name:
            pid = m.group(1)
        stem = pid + (f"_{args.method}" if args.method else (f"_{method}" if method and not args.name else ""))
    else:
        repo_root = find_repo_root(src_abs)
        if repo_root is None:
            print("[错误] 未找到 git 仓库根目录，自动归类请先在仓库内运行，或用 --target 指定", file=sys.stderr)
            sys.exit(2)
        platform, pid, method = detect_platform(prob, src_abs, args.id)
        method = args.method or method
        if platform == "pintia":
            m = re.match(r"^(L\d)-", pid)
            if not m:
                print(f"[错误] PTA 题号需形如 L2-011（当前: {pid}）", file=sys.stderr)
                sys.exit(2)
            target_dir = os.path.join(repo_root, "pintia", m.group(1), pid)
        else:
            target_dir = os.path.join(repo_root, platform, pid)
        stem = pid + (f"_{method}" if method else "")
    if args.name:
        stem = args.name + (f"_{args.method}" if args.method else "")

    dst_abs = os.path.join(target_dir, stem + ".cpp")
    if dst_abs == src_abs:
        print("[错误] 源文件与目标路径相同，无需归档", file=sys.stderr)
        sys.exit(2)

    # ---- 重名处理 ----
    if os.path.exists(dst_abs):
        n = pick_free_vn(target_dir, stem)
        alt = os.path.join(target_dir, f"{stem}_v{n}.cpp")
        if args.dry_run or args.yes:
            dst_abs = alt
        else:
            ans = input(f"目标已存在 {os.path.basename(dst_abs)}，改存为 {stem}_v{n}.cpp? [y/N] ")
            if ans.strip().lower() != "y":
                print("已取消")
                sys.exit(1)
            dst_abs = alt

    new_prob_path = os.path.join(target_dir, ".cph",
                                 f".{os.path.basename(dst_abs)}_{md5_abs(dst_abs)}.prob")

    # ---- dry-run：只打印计划 ----
    print("== 归档计划 ==")
    print(f"  移动源码: {src_abs}")
    print(f"        -> {dst_abs}")
    if prob_path:
        print(f"  迁移测试点: {prob_path}")
        print(f"          -> {new_prob_path}")
        print(f"  srcPath   -> {dst_abs}")
    else:
        print("  迁移测试点: 无（未找到 .prob）")
    if args.dry_run:
        sys.exit(0)

    # ---- 执行 ----
    os.makedirs(target_dir, exist_ok=True)
    if os.path.isdir(dst_abs):
        print(f"[错误] 目标路径是目录: {dst_abs}", file=sys.stderr)
        sys.exit(2)
    shutil.move(src_abs, dst_abs)

    if prob_path:
        if os.path.exists(new_prob_path):
            print(f"[错误] 目标测试点已存在，拒绝覆盖: {new_prob_path}", file=sys.stderr)
            print(f"      源码已移动到 {dst_abs}；旧测试点仍在 {prob_path}，请手动合并", file=sys.stderr)
            sys.exit(1)
        prob["srcPath"] = dst_abs
        os.makedirs(os.path.dirname(new_prob_path), exist_ok=True)
        with open(new_prob_path, "w", encoding="utf-8") as f:
            json.dump(prob, f, separators=(",", ":"), ensure_ascii=False)
        os.remove(prob_path)
        old_cph = os.path.dirname(prob_path)
        try:
            os.rmdir(old_cph)  # 空目录则清理
        except OSError:
            pass

    print("== 归档完成 ==")
    print(f"  {dst_abs}")
    if prob_path:
        print(f"  测试点已迁移，归档后仍可在 cph 中重跑")


if __name__ == "__main__":
    main()
