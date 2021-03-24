# C power4 game

[![semantic-release](https://img.shields.io/badge/%20%20%F0%9F%93%A6%F0%9F%9A%80-semantic--release-e10079.svg)](https://github.com/semantic-release/semantic-release)
[![Package a binary](https://github.com/esgi-lyon/c-power4/actions/workflows/ci.yml/badge.svg)](https://github.com/esgi-lyon/c-power4/actions/workflows/ci.yml)

# Archi

On entre les input des utilisateurs, il peuvent seulement introduire un nouveau pion sur les colonnes. On compte dans des `caches` le nombre de pions de chaque couleurs qui se succèdes. Si un joueur joue sur une ligne de pion, on reset ce cache.

# run

- Follow this for auto build on save [answer](https://stackoverflow.com/a/64583641/11132253)

- Or juste `make` from a shell

# Windows

> all commands from this project **cloned** folder

- On admin powershell ```pw .\scripts\install.ps1```
- From cygwin bash shell : `make`, project should build and execute
