@echo off
cd /d C:\Users\62685\Desktop\vc
for /f "tokens=1-4 delims=/ " %%a in ("%DATE%") do (
    set y=%%c
    set m=%%a
    set d=%%b
)
for /f "tokens=1-2 delims=:." %%a in ("%TIME%") do (
    set h=%%a
    set min=%%b
)
set CURTIME=%y%-%m%-%d%_%h%-%min%

git add .
git commit -m "update at %CURTIME%"
git push
pause
