# AGENTS.md

This file provides guidance to coding agents (Claude Code, Codex, Grok, opencode) when working with code in this repository.

## What this repo is

Study playground. Today it only holds the code written during the solo C++ study lives (Twitch + YouTube). There is no build system, no tests directory and no CI yet; `README.md` is just the title.

## Layout

```
cpp/live-NN/   code written during live NN (one folder per live, created when the live starts)
```

The live scripts (roteiros) and study notes are not here. They live in `~/dev/brain` (`lives/cpp/` for the scripts, `studies/` for notes) and are saved through the marginalia MCP or the `/marginalia` skill, only when the user asks. This repo is the place for code and its commits.

## Commands

Each live is a small standalone program; there is no project-wide build. The scripts were verified with g++ 16:

```bash
g++ -std=c++20 -Wall -Wextra -o main main.cpp && ./main
```

Add `-fsanitize=address` when the live is about memory (live 05, `unique_ptr`/RAII). Keep warnings clean: `-Wall` flags `=` inside `if`, signed/unsigned comparisons and similar beginner mistakes that the lives rely on showing.

## Conventions

- Code, identifiers and comments in English; commit messages in English with an emoji prefix (Conventional Commits).
- Trunk-based: commit to `main`.
- Compiled binaries are not committed (no `.gitignore` exists yet; add one before the first live produces binaries).
- Edits here follow the live in progress; do not rewrite a past `live-NN/` folder to match a later lesson.
