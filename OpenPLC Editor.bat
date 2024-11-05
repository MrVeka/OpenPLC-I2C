@echo off
echo "Starting OpenPLC Editor..."
if exist .\new_editor\ (
  rmdir /s /q .\editor
  rmdir /s /q .\matiec\lib
  move .\new_editor .\editor
  move .\new_lib .\matiec\lib
)

SET "BASE_DIR=%~dp0"
SET "PYTHONHOME=%BASE_DIR%python"
SET "PATH=%PYTHONHOME%;%PATH%"
SET "PYTHONPATH=%BASE_DIR%libs"

start "" "%PYTHONHOME%\pythonw.exe" "%BASE_DIR%\editor\Beremiz.py"