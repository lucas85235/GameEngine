
# 🛠️ GameEngine - A Basic C++ Game Engine

This is a simple game engine written in C++ using GLFW and OpenGL. The project is structured to allow easy expansion, including rendering, input handling, resource management, and more.

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
        /graphics
            Renderer.cpp
            Renderer.h
        main.cpp
    /include
    /third_party
    /build
    CMakeLists.txt
    README.md
```

- **`src/core/`** → Contains the core engine logic (Engine and Window classes).
- **`src/graphics/`** → Responsible for rendering (future expansion).
- **`include/`** → Header files for external libraries.
- **`third_party/`** → Third-party dependencies like GLFW.
- **`build/`** → Compiled binaries and object files.
- **`CMakeLists.txt`** → Build configuration file for CMake.

---

## 🚀 How to Build and Run

### **1️⃣ Install Dependencies**
Before compiling, ensure you have the necessary dependencies.

#### **Linux (Ubuntu/Debian)**
```bash
sudo apt update
sudo apt install cmake g++ libglfw3-dev libglew-dev libglm-dev libxi-dev libxkbcommon-dev libgl1-mesa-dev
```

#### **Arch Linux / Manjaro**
```bash
sudo pacman -S cmake glfw glew glm libxi xkbcommon mesa
```

#### **Fedora**
```bash
sudo dnf install cmake gcc-c++ glfw-devel glew-devel glm-devel libXi-devel libxkbcommon-devel mesa-libGL-devel
```

---

### **2️⃣ Clone the Repository**
```bash
git clone https://github.com/yourusername/GameEngine.git
cd GameEngine
```

---

### **3️⃣ Build the Engine**
```bash
mkdir build
cd build
cmake ..
make
```

---

### **4️⃣ Run the Engine**
```bash
./GameEngine
```
If everything is set up correctly, a **window should open**.

---

## 🏗️ How It Works
The game engine follows a **modular architecture**:

- **Engine Class (`Engine.h/.cpp`)**  
  - Manages the game loop.
  - Handles updates and rendering calls.

- **Window Class (`Window.h/.cpp`)**  
  - Creates and manages the GLFW window.
  - Handles event polling and swapping buffers.

- **Renderer (Upcoming Feature)**  
  - Will handle rendering logic using OpenGL/Vulkan.

- **Future Expansions**  
  - Input Handling (Keyboard/Mouse)
  - Resource Management (Textures, Shaders, Models)
  - Entity-Component-System (ECS)
  - Physics Engine Integration
  - Scripting (Lua/Python)

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
