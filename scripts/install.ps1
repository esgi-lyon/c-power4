# install choco
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
# tooling
choco install -y cygwin
choco install -y msys2
C:\msys64\usr\bin\env MSYSTEM=MINGW64 c:\msys64\usr\bin\bash -c 'pacman -Ss make findutils mingw-w64-x86_64-llvm'
