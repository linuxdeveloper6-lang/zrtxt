# Zrtxt
## What is Zrtxt?
**Zrtxt** - quick and lightweight **text-editor**.
## What he can do?
**He can**:
- **Read file**.
- **Write to a file**.
- **Append to a file**.
- **Clean file**.
- **Create file**.
- **Search in file**.

## Build from source
### Dependencies
1. upk.
2. gcc.
### Building
```bash
git clone https://github.com/linuxdeveloper6-lang/zrtxt.git
cd zrtxt
make
sudo make install
```
### Removing
```bash
sudo make remove
```

## Example
### Read file
```bash
zrtxt -r <file>
```
### Write to a file
```bash
zrtxt -w <file>
```
### Append to a file
```bash
echo <text> | zrtxt -w <file>
```
### Clean file
```bash
zrtxt -c <file>
```
### Create file
```bash
zrtxt -n <file>
```
### Search in file
```bash
zrtxt -s <file> <text>
```
### License
This project is **licensed** under the **MIT** license, see [LICENSE](LICENSE).
