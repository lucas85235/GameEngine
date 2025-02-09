
# 🛠️ GameEngine - A Hybrid C++ & Python Game Engine

This is a simple game engine written in **C++** with **GLFW, OpenGL, and Pybind11** for Python integration.  
It provides a modular structure that allows Python to manage the **UI and high-level logic**, while C++ handles **graphics and performance-critical tasks**.

---

## 📁 Project Structure

```
/GameEngine
    /src
        /core
            Engine.cpp
            Engine.h
            Window.cpp
            Window.h
        main.cpp
        bindings.cpp    # Pybind11 bindings for Python
    /python
        engine.py       # Python UI
    /include
    /third_party
    /build
    CMakeLists.txt
    README.md
    build_and_run.sh   # Script to compile and run
```

- **`src/core/`** → Contains the core engine logic (Engine and Window classes).
- **`src/bindings.cpp`** → Pybind11 bindings that expose C++ functions to Python.
- **`python/engine.py`** → The UI and control logic implemented in Python.
- **`third_party/`** → External dependencies such as GLFW and Pybind11.
- **`build_and_run.sh`** → Automates the build and execution process.

---

## 🚀 How to Build and Run

### **1️⃣ Install Dependencies**
Before compiling, ensure you have the necessary dependencies.

### **🔹 Linux (Ubuntu/Debian)**
```bash
sudo apt update
sudo apt install cmake g++ libglfw3-dev libglew-dev libglm-dev libxi-dev libxkbcommon-dev libgl1-mesa-dev python3 python3-pip python3-tk
pip install pybind11
```

### **🔹 Arch Linux / Manjaro**
```bash
sudo pacman -S cmake glfw glew glm libxi xkbcommon mesa python python-pip tk
pip install pybind11
```

### **🔹 Fedora**
```bash
sudo dnf install cmake gcc-c++ glfw-devel glew-devel glm-devel libXi-devel libxkbcommon-devel mesa-libGL-devel python3 python3-pip python3-tkinter
pip install pybind11
```

### **🔹 Windows**
1. Install **CMake**, **MinGW-w64**, or **Visual Studio Build Tools**.
2. Install Python (from [python.org](https://www.python.org/downloads/)).
3. Install dependencies:
   ```bash
   pip install pybind11
   ```
4. Install GLFW manually (or use vcpkg).

---

### **2️⃣ Clone the Repository**
```bash
git clone https://github.com/yourusername/GameEngine.git
cd GameEngine
```

---

### **3️⃣ Build and Run the Engine**
Run the automated script to **compile and execute** the project:

```bash
./build_and_run.sh
```

Alternatively, if running manually:

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
cp game_engine.* ../python/
cd ..
python3 python/engine.py
```

---

## 🏗️ How It Works

The game engine follows a **hybrid architecture**, combining C++ and Python:

### **🔹 Core Engine (`src/core/`)**
- **Engine Class (`Engine.h/.cpp`)**
  - Manages the game loop.
  - Handles updates and rendering calls.

- **Window Class (`Window.h/.cpp`)**
  - Creates and manages the GLFW window.
  - Handles event polling and buffer swapping.

### **🔹 Python Integration (`src/bindings.cpp`)**
- Uses **Pybind11** to expose C++ functions to Python.
- Allows Python scripts to interact with the engine.

### **🔹 Python UI (`python/engine.py`)**
- Uses **Tkinter** for the graphical interface.
- Calls C++ functions through the Pybind11 module.
- Starts and stops the game engine using buttons.

---

## 📦 Future Expansions
- **Rendering System** → Integrate OpenGL/Vulkan for graphics.
- **Physics Engine** → Add Bullet or Box2D for physics.
- **Input Handling** → Capture keyboard/mouse events.
- **Entity-Component-System (ECS)** → Manage game objects efficiently.
- **Scripting API** → Allow full game scripting in Python.

---

## 🤝 Contributing
Feel free to contribute by submitting **pull requests** or opening **issues**. The goal is to create a fully functional and lightweight game engine.

---

## 📜 License
This project is licensed under the **MIT License**.

---

## 📧 Contact
If you have any questions or suggestions, reach out via lucas85235@gmail.com

---
