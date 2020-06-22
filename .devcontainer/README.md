# Devcontainer notes.
## Update scons build to use python3
- `sudo nano /usr/bin/scons`
- edit shebang to `#!/usr/bin/python3`

## Build engine (from repo root)
`scons -j8 platform=x11`

## Build and copy export templates (from repo root)
```
mkdir -p ~/.local/share/godot/templates/3.2.2.rc
scons -j8 platform=x11 tools=no target=release bits=64
cp ./bin/godot.x11.tools.64 $HOME/.local/share/godot/templates/3.2.2.rc/linux_x11_64_release
scons -j8 platform=x11 tools=no target=release_debug bits=64
cp ./bin/godot.x11.opt.debug.64 $HOME/.local/share/godot/templates/3.2.2.rc/linux_x11_64_debug
```
