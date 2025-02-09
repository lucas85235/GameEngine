#!/bin/bash

# Exit on error
set -e

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

# Run the application
echo "🚀 Running GameEngine..."
./GameEngine
