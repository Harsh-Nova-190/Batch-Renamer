# Contributing to NovaBytes Batch Renamer

Thank you for your interest in contributing to **NovaBytes Batch Renamer**.

We appreciate bug reports, feature suggestions, documentation improvements, and code contributions.

---

# Development Environment

Requirements

- Windows 10 or later
- Visual Studio 2022
- C++20
- Qt 6.11+
- CMake 3.21+

---

# Project Structure

```
include/
    core/
    models/
    ui/
    widgets/

src/
    core/
    ui/
    widgets/

resources/
docs/
```

---

# Coding Style

## General

- Use C++20 features when appropriate.
- Keep functions focused on a single responsibility.
- Prefer readable code over clever code.
- Avoid duplicated logic.

---

## Naming

### Classes

```cpp
RenameEngine
FileManager
MainWindow
```

Use **PascalCase**.

---

### Functions

```cpp
loadFiles()

generatePreview()

renameFiles()
```

Use **camelCase**.

---

### Variables

```cpp
fileName

newName

renameOptions
```

Use **camelCase**.

---

### Member Variables

```cpp
m_fileTable

m_mainLayout

m_renameButton
```

Prefix with **m_**.

---

# Header Format

Every source file should begin with:

```cpp
/*
 * ------------------------------------------------------------
 * Project : NovaBytes Batch Renamer
 * Company : NovaBytes
 * File    : FileName.cpp
 * Author  : Harsh Laskar
 * ------------------------------------------------------------
 */
```

---

# Architecture Principles

- UI code belongs in **ui/**
- Widgets belong in **widgets/**
- Business logic belongs in **core/**
- Data structures belong in **models/**

Keep responsibilities separated.

---

# Pull Requests

Before submitting a pull request:

- Build successfully
- No compiler warnings
- Update documentation if necessary
- Keep commits focused and descriptive

Example commit messages:

```
feat: add folder loading

fix: preserve file extensions

refactor: simplify rename engine
```

---

# Reporting Bugs

When reporting a bug, please include:

- Operating System
- Application Version
- Steps to reproduce
- Expected behavior
- Actual behavior
- Screenshots (if applicable)

---

# Feature Requests

Feature requests are welcome.

Please include:

- Description
- Use case
- Expected behavior
- Possible implementation (optional)

---

# License

By contributing to this project, you agree that your contributions will be licensed under the project's MIT License.

---

Thank you for helping improve NovaBytes Batch Renamer.