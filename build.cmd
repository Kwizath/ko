@echo off
setlocal enabledelayedexpansion

:: === Paths ===
set "CURRENT_PATH=%~dp0"
set "VENDOR_DIR=%CURRENT_PATH%src\vendor"
set "VSDEV_CMD=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"

echo.
echo ==========================================
echo   KO Vendor & Build Automation Script
echo ==========================================
echo.

:: === Check if VsDevCmd.bat exists ===
if not exist "%VSDEV_CMD%" (
    echo [ERROR] Visual Studio Developer Command Prompt not found.
    echo.
    echo Expected path:
    echo   "%VSDEV_CMD%"
    echo.
    echo Please verify your Visual Studio installation or update the path.
    echo.
    pause
    exit /b 1
)

:: === Vendor folder setup ===
if not exist "%VENDOR_DIR%" (
    echo [INFO] Vendor directory not found. Downloading vendor files...
    pushd "%CURRENT_PATH%"
    curl -L -O https://github.com/ko4life-net/ko-vendor/archive/refs/heads/master.zip
    if errorlevel 1 (
        echo [ERROR] Failed to download vendor package.
        pause
        exit /b 1
    )
    tar -xvf master.zip >nul
    del master.zip
    move ko-vendor-master "%VENDOR_DIR%" >nul
    popd
)

:: === Initialize VS build environment ===
call "%VSDEV_CMD%"

:: === Build process ===
pushd "%CURRENT_PATH%src"
if exist build (
    echo [INFO] Removing old build folder...
    rmdir /s /q build
)

echo [INFO] Starting build (Release configuration)...
msbuild All.sln -t:Clean -t:Build -p:Configuration=Release /m
if errorlevel 1 (
    echo.
    echo [ERROR] Build failed!
    popd
    pause
    exit /b 1
)

echo.
echo [SUCCESS] Build completed successfully.
popd
echo.
pause
exit /b 0
