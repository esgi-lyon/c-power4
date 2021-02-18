# C power4 game

[![semantic-release](https://img.shields.io/badge/%20%20%F0%9F%93%A6%F0%9F%9A%80-semantic--release-e10079.svg)](https://github.com/semantic-release/semantic-release)

# TODO

- [ ] CI to build project on mac / windows
- [ ] Release system for windows and mac

# run

- Follow this for auto build on save [answer](https://stackoverflow.com/a/64583641/11132253)

- Or juste `make` from a shell

# Windows
> all commands on powershell

```pw
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```
and
`choco install make llvm`
