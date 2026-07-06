#!/usr/bin/env python3
"""
Makefile Validation Script
Validates that Makefiles follow the cross-platform template standards
"""

import os
import re
import sys
from pathlib import Path

class MakefileValidator:
    def __init__(self):
        self.required_sections = [
            "PLATFORM DETECTION AND CONFIGURATION",
            "COMPILER SETTINGS",
            "PROJECT STRUCTURE",
            "BUILD TARGETS",
            "DEVELOPMENT TARGETS",
            "HELPER TARGETS",
            "PHONY TARGETS"
        ]

        self.required_targets = [
            "all",
            "test",
            "run",
            "release",
            "debug",
            "clean",
            "help"
        ]

        self.required_variables = [
            "CC",
            "CXX",
            "RM",
            "MKDIR",
            "EXECUTABLE_EXT",
            "CFLAGS",
            "CXXFLAGS",
            "BUILD_DIR",
            "TARGET_DIR"
        ]

    def validate_makefile(self, makefile_path):
        """Validate a single Makefile against standards"""
        print(f"Validating: {makefile_path}")

        try:
            with open(makefile_path, 'r') as f:
                content = f.read()
        except FileNotFoundError:
            print(f"  ❌ Makefile not found: {makefile_path}")
            return False

        issues = []

        # Check required sections
        for section in self.required_sections:
            if f"# {section}" not in content:
                issues.append(f"Missing section: {section}")

        # Check required targets
        for target in self.required_targets:
            target_pattern = rf"^{target}:"
            if not re.search(target_pattern, content, re.MULTILINE):
                issues.append(f"Missing target: {target}")

        # Check required variables (handle both := and = assignments, and conditional definitions)
        for var in self.required_variables:
            # Look for variable definitions anywhere in the file, not just at line start
            var_pattern = rf"{var}\s*[:=]"
            if not re.search(var_pattern, content):
                issues.append(f"Missing variable: {var}")

        # Check for platform detection
        if "UNAME_S" not in content and "OS" not in content:
            issues.append("Missing platform detection (UNAME_S or OS)")

        # Check for cross-platform commands
        if "$(MKDIR)" not in content and "mkdir" not in content:
            issues.append("Not using $(MKDIR) for directory creation")
        if "$(RM)" not in content and "rm" not in content:
            issues.append("Not using $(RM) for file removal")

        # Check for proper directory structure
        if "bin" not in content and "BIN_DIR" not in content:
            issues.append("Missing bin directory references")
        if "build" not in content and "BUILD_DIR" not in content:
            issues.append("Missing build directory references")

        if issues:
            print(f"  ❌ Found {len(issues)} issues:")
            for issue in issues:
                print(f"    - {issue}")
            return False
        else:
            print("  ✅ Valid Makefile")
            return True

    def find_makefiles(self, root_dir="."):
        """Find all Makefiles in the repository"""
        makefiles = []
        for root, dirs, files in os.walk(root_dir):
            # Skip hidden directories
            dirs[:] = [d for d in dirs if not d.startswith('.')]

            for file in files:
                if file.lower() == "makefile":
                    makefiles.append(os.path.join(root, file))
        return makefiles

    def validate_all(self, root_dir="."):
        """Validate all Makefiles in the repository"""
        print("Makefile Validation Report")
        print("=" * 50)

        makefiles = self.find_makefiles(root_dir)

        if not makefiles:
            print("No Makefiles found in the repository")
            return True

        valid_count = 0
        total_count = len(makefiles)

        for makefile in makefiles:
            if self.validate_makefile(makefile):
                valid_count += 1
            print()

        print(f"Summary: {valid_count}/{total_count} Makefiles are valid")

        return valid_count == total_count

def main():
    validator = MakefileValidator()

    # Get root directory from command line or use current directory
    root_dir = sys.argv[1] if len(sys.argv) > 1 else "."

    if not os.path.exists(root_dir):
        print(f"Error: Directory '{root_dir}' does not exist")
        sys.exit(1)

    success = validator.validate_all(root_dir)
    sys.exit(0 if success else 1)

if __name__ == "__main__":
    main()