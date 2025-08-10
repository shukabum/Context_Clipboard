# ContextClipboard

A cross-platform clipboard monitoring tool with a searchable history stored in an SQLite database.  
It runs a background listener that captures any text copied to the clipboard, classifies it, and saves it for later search.

---

## 📂 Features
- **Real-time clipboard monitoring**
- **Content classification** (e.g., URLs, emails, plain text)
- **SQLite database storage** for persistent history
- **Search tool** to query past clipboard items
- **Duplicate prevention** (no repeated consecutive entries)
- **Case-insensitive search** support
- Search by **type** or **date** (planned)

---

## 📦 Folder Structure
```plaintext
ContextClipboard/
├── build/                # Build directory (created after compilation)
├── data/                 # Contains clipboard.db
├── include/              # Header files
│   ├── Classifier.h
│   ├── ClipBoardListener.h
│   ├── Database.h
│   ├── Search.h
│   ├── Utils.h
│   └── ...
├── src/                  # Source files
│   ├── main.cpp
│   ├── clipsearch_main.cpp
│   ├── Classifier.cpp
│   ├── ClipBoardListener.cpp
│   ├── Database.cpp
│   ├── Search.cpp
│   ├── Utils.cpp
│   └── ...
├── third_party/          # Third-party libraries
│   ├── sqlite3.c
│   └── sqlite3.h
├── CMakeLists.txt
└── README.md
```

## ⚙️ Building

### **Requirements**
- **CMake** ≥ 3.10
- **g++ / clang++** (C++17 support)
- **SQLite3** (included in `third_party/sqlite3.c`)
- Windows: MinGW or MSYS2 with `ucrt64` toolchain

### **Steps**
```bash
# 1. Clone repo
git clone https://github.com/shukabum/ContextClipboard.git
cd ContextClipboard

# 2. Create build folder
mkdir build && cd build

# 3. Configure
cmake ..

# 4. Build
cmake --build .

```
This will produce two executables:

context_clipboard → Clipboard listener

clipsearch → Search utility

## 🚀 Usage
Start the Clipboard Listener
```bash
# Run from the project root so paths resolve correctly
./build/context_clipboard data/clipboard.db
```
## Search Clipboard History
```bash
# Search for the keyword "email"
./build/clipsearch email

# Search by type (planned feature)
./build/clipsearch --type URL

# Search by date (planned feature)
./build/clipsearch --date 2025-08-10
```

## 📁 Database
The database is stored in data/clipboard.db.
You can inspect it using the SQLite CLI:
```bash
sqlite3 data/clipboard.db
sqlite> .tables
sqlite> SELECT * FROM clipboard;
```

# 📜 License
MIT License © 2025 Shukabum
