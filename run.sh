#!/bin/bash

# Exit on error
set -e

# Get the absolute path of the script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
echo $SCRIPT_DIR

echo "🔨 Building GameEngine..."

# Create the build directory if it doesn't exist
if [ ! -d "build" ]; then
    mkdir build
fi

# Move into the build directory
cd build

# Run CMake
cmake ..

# Compile the project
make -j$(nproc)

echo "✅ Build successful!"

# Copy the compiled Python module to the python/ directory
echo "📂 Copying game_engine module to python/..."
cp libgame_engine.so "$SCRIPT_DIR/python/"
mv "$SCRIPT_DIR/python/libgame_engine.so" "$SCRIPT_DIR/python/game_engine.so"

# Run the application
echo "🚀 Running GameEngine..."

#./GameEngine
python3 $SCRIPT_DIR/python/engine.py
