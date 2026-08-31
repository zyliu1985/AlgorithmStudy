# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 仓库性质

个人 OI/ACM 竞赛练习仓库(`AlgorithmStudy`),以 C++ 为主。题目按来源平台 / 专题分目录组织,每个 `.cpp` 文件一般对应一道题的完整提交(无独立 `CMakeLists.txt` / 测试框架)。

没有共享库、没有构建系统、没有 CI。`.gitignore` 只过滤编译产物(`*.exe` 等)。

## 目录约定

- **按平台分类**: `luogu/`(洛谷)、`atcoder/`、`xmoj/`(信友队)、`cyezoi/`、`iai/`、`usco/`、`zzoj/`、`vjudge/`、`YACS/`、`杭电/`
- **按专题分类**: `algorithm/`(模板)、`密码系统/`、`休闲/`、`NOIP/`、`IOI和NOI挑战/`
- **专题子目录**: `algorithm/平衡树/`(splay、treap)、`algorithm/线段树/`(和、最值、最大值)
- **比赛/作业**: `cyezoi/日常刷题/`、`cyezoi/20250614测评/`、`xiaohoucode/`、`梦熊联盟周赛/`、`shang hai yue sai ti mu/`
- **杂项**: `trash/`、`数据/`、`you_xi/`、`Z2集训队/`、`YCL6/`、`新建文件夹/` —— 一般是不再维护的代码,不要主动修改

`README.md` 仅一句话说明仓库用途(`宝宝的算法学习仓库`),无构建/运行说明。

## 代码风格

代码全部是 C++,普遍使用的特征:

- `bits/stdc++.h` + `using namespace std;`
- `ios::sync_with_stdio(false); cin.tie(0);`
- 主函数常包含 `int main(){... return 0;}`
- 模板使用类封装(`class ST`、`class SegTree`),见 `algorithm/ST.cpp`
- 部分模板用 `#define int long long`
- 命名以中文为主(`平衡树`、`矩阵`、`四子棋AI大战100回合`),路径含大量非 ASCII / 空格字符,git 操作需注意转义

## 常见操作

仓库没有 `Makefile` / `build.sh`,单个题目的标准运行流程:

```bash
g++ -O2 -std=c++17 -o problem.exe problem.cpp        # Windows MinGW
./problem.exe < problem.in > problem.out
```

判定题目录里通常配对存在 `*.in` 与 `*.ans`(例如 `luogu/arena2.in` / `luogu/arena2.ans`),可用 `fc problem.out problem.ans` 或 `diff` 对拍。

`休闲/` 含 testlib(`testlib.h`、`checkers/`、`validators/`、`generators/`、`interactors/`),`checker.cpp` 编译时与 `testlib.h` 同目录即可。testlib 来自 `testlib-0.9.41.zip`。

## 提交注意事项

- 分支: `csp-j`(主开发分支);`master` 仅历史归档
- 远端: `git@github.com:zyliu1985/AlgorithmStudy.git`(SSH,ed25519)
- 大目录(如 `atcoder/dp_v/` 嵌套包含 Rust 项目)可能被 `git add -A` 一并暂存
- Windows 下 LF/CRLF 警告属正常
- 历史 commit 信息以中文一句话为主(例:`提交`、`洛谷两次作业提交`、`oj大规模提交`),无需刻意美化

## 修改时的注意事项

- 仓库历史中曾出现根目录的 `*.exe` 编译产物(根目录仍散落 `1.exe`、`假期.exe` 等),若新增 `git add` 请确认是否需要保留
- `密码系统/` 含真实可执行加/解密程序,源代码可读,无密钥;不要把生成的密文 / 解密结果文件提交进来
- `~$知识点清单.docx` 是 Office 临时文件,可加入 `.gitignore`
- `trash/`、`you_xi/`、`Z2集训队/`、`YCL6/`、`新建文件夹/` 一般是早期代码,不要"清理"——可能只是归档
- 文件名含空格 / 中文时,`git`、`grep` 命令需加引号或转义
