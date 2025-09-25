#!/usr/bin/env python3
"""
Cross-platform compilation script for C and C++ algorithms
Works on macOS, Linux, and Windows
"""

import os
import sys
import subprocess
import platform
from pathlib import Path

def detect_compilers():
    """Detect available compilers on the system"""
    compilers = {
        'c': None,
        'cpp': None
    }

    # Check for C compilers
    for compiler in ['gcc', 'clang', 'cc']:
        try:
            subprocess.run([compiler, '--version'], capture_output=True, check=True)
            compilers['c'] = compiler
            break
        except (subprocess.CalledProcessError, FileNotFoundError):
            continue

    # Check for C++ compilers
    for compiler in ['g++', 'clang++', 'c++']:
        try:
            subprocess.run([compiler, '--version'], capture_output=True, check=True)
            compilers['cpp'] = compiler
            break
        except (subprocess.CalledProcessError, FileNotFoundError):
            continue

    return compilers

def get_platform_flags():
    """Get platform-specific compilation flags"""
    system = platform.system()

    if system == "Windows":
        return {
            'c_flags': ['-std=c99', '-Wall', '-O2'],
            'cpp_flags': ['-std=c++17', '-Wall', '-O2'],
            'executable_ext': '.exe'
        }
    else:
        return {
            'c_flags': ['-std=c99', '-Wall', '-O2'],
            'cpp_flags': ['-std=c++17', '-Wall', '-O2'],
            'executable_ext': ''
        }

def compile_file(source_file, compiler, flags, output_name):
    """Compile a single source file"""
    try:
        cmd = [compiler] + flags + ['-o', output_name, source_file]
        print(f"Compiling: {' '.join(cmd)}")

        result = subprocess.run(cmd, capture_output=True, text=True)

        if result.returncode == 0:
            print(f"✓ Successfully compiled {source_file} -> {output_name}")
            return True
        else:
            print(f"✗ Compilation failed for {source_file}")
            if result.stderr:
                print(f"Error: {result.stderr}")
            return False

    except Exception as e:
        print(f"✗ Error compiling {source_file}: {e}")
        return False

def main():
    print("Cross-Platform Algorithm Compiler")
    print("=" * 40)
    print(f"Platform: {platform.system()} {platform.release()}")
    print(f"Python: {sys.version.split()[0]}")
    print()

    # Detect compilers
    compilers = detect_compilers()
    print("Available compilers:")
    print(f"  C: {compilers['c'] or 'Not found'}")
    print(f"  C++: {compilers['cpp'] or 'Not found'}")
    print()

    if not compilers['c'] and not compilers['cpp']:
        print("Error: No suitable compilers found!")
        print("Please install gcc/g++ or clang/clang++")
        return 1

    # Get platform flags
    platform_flags = get_platform_flags()

    # Find source files
    current_dir = Path.cwd()
    c_files = list(current_dir.glob("*.c"))
    cpp_files = list(current_dir.glob("*.cpp"))

    if not c_files and not cpp_files:
        print("Error: No .c or .cpp files found in current directory!")
        return 1

    print(f"Found {len(c_files)} C file(s) and {len(cpp_files)} C++ file(s)")
    print()

    # Compile C files
    success_count = 0
    total_count = 0

    for c_file in c_files:
        if compilers['c']:
            total_count += 1
            output_name = c_file.stem + platform_flags['executable_ext']
            if compile_file(str(c_file), compilers['c'], platform_flags['c_flags'], output_name):
                success_count += 1
        else:
            print(f"Skipping {c_file.name}: No C compiler available")

    # Compile C++ files
    for cpp_file in cpp_files:
        if compilers['cpp']:
            total_count += 1
            output_name = cpp_file.stem + "_cpp" + platform_flags['executable_ext']
            if compile_file(str(cpp_file), compilers['cpp'], platform_flags['cpp_flags'], output_name):
                success_count += 1
        else:
            print(f"Skipping {cpp_file.name}: No C++ compiler available")

    print()
    print(f"Compilation summary: {success_count}/{total_count} files compiled successfully")

    if success_count > 0:
        print("\nTo run your programs:")
        if platform.system() == "Windows":
            print("  .\\program_name.exe")
        else:
            print("  ./program_name")

    return 0 if success_count == total_count else 1

if __name__ == "__main__":
    sys.exit(main())