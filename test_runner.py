import subprocess
import glob
import os
import pytest

TEST_DIR = "test"
CXX = "g++"
CXXFLAGS = ["-std=c++17", "-I."]


@pytest.mark.parametrize(
    "test_file", sorted(glob.glob(f"{TEST_DIR}/**/*.cpp", recursive=True))
)
def test_cpp_compile_and_run(test_file):
    """Compile and run each C++ test file."""
    basename = os.path.basename(test_file)
    output = f"/tmp/test_{os.path.splitext(basename)[0]}"

    compile_cmd = [CXX] + CXXFLAGS + [test_file, "-o", output]
    result = subprocess.run(compile_cmd, capture_output=True, text=True)

    assert result.returncode == 0, (
        f"Compilation failed for {test_file}:\n{result.stderr}"
    )

    run_result = subprocess.run([output], capture_output=True, text=True, timeout=30)
    assert run_result.returncode == 0, (
        f"Test failed for {test_file}:\n{run_result.stderr}\n{run_result.stdout}"
    )
