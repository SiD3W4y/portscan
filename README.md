# Portscan

Portscan is a simple port scanner. It uses a noisy, sequential tcp connect method to detect if a port is open

## Build
```
cmake . && make
```

## Run
```
# Will scan ports 0-1024
./portscan <ip>
```
or
```
./portscan <ip> <maxport>
```
