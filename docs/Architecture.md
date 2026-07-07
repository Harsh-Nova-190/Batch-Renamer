# NovaBytes Batch Renamer Architecture

## Overview

NovaBytes Batch Renamer is a desktop application built with **C++20** and **Qt 6**.

The application follows a modular architecture that separates the user interface, business logic, and data models to improve maintainability and scalability.

---

# Project Structure

```
NovaBytes-Batch-Renamer
│
├── include/
│   ├── core/
│   ├── models/
│   ├── ui/
│   └── widgets/
│
├── src/
│   ├── core/
│   ├── ui/
│   └── widgets/
│
├── resources/
│   ├── icons/
│   ├── images/
│   └── qss/
│
└── docs/
```

---

# Architecture

```
                MainWindow
                     │
     ┌───────────────┼────────────────┐
     │               │                │
     ▼               ▼                ▼
 DropArea      RenamePanel       FileTable
     │               │
     └──────┐        │
            ▼        ▼
         FileManager RenameEngine
                 │
                 ▼
          RenameExecutor
                 │
                 ▼
             File System
```

---

# Components

## MainWindow

Responsible for:

- Creating the application layout
- Connecting signals and slots
- Managing UI interactions

---

## DropArea

Responsible for:

- Drag & Drop support
- Emitting dropped file paths

---

## FileManager

Responsible for:

- Loading files
- Loading folders
- Creating FileItem objects

---

## RenameEngine

Responsible for:

- Generating rename previews
- Applying rename options
- Updating new filenames

---

## RenameExecutor

Responsible for:

- Renaming files on disk
- Undo operations
- Redo operations

---

## FileTable

Responsible for:

- Displaying loaded files
- Displaying rename previews
- Showing rename status

---

## RenamePanel

Responsible for:

- Collecting rename options
- Emitting option changes

---

# Design Goals

- Modular
- Easy to maintain
- Easy to extend
- Reusable components
- Modern Qt architecture

---

# Future Improvements

- Plugin system
- Regex engine
- Presets
- Multi-language support
- Theme manager