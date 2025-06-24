# Downtime
*A small tool written in C to replace the uptime command of Linux with a French format.*

Un petit outil écrit en C pour remplacer la commande uptime de Linux avec un format français.

## Utilisation
```
❯ downtime
8 heures, 23 minutes et 10 secondes

❯ downtime --long
0 jours, 8 heures, 23 minutes et 28 secondes

❯ downtime --since
24/06/2025 12:05:53

❯ downtime --raw
30240
```

## Installation
### Préréquis
Pour installer cet outil, il faut tout d'abord avoir :
- `git`
- `gcc`
- `make`

### Installation
Pour installer l'outil il suffit d'executer cette suite de commande :
```bash
git clone https://github.com/oriionn/downtime.git
cd downtime
make install
```

## Compiler
### Préréquis
Pour compiler cet outil, il faut tout d'abord avoir :
- `git`
- `gcc`
- `make`

### Compilation
Pour compiler l'outil il suffit d'executer cette suite de commande :
```bash
git clone https://github.com/oriionn/downtime.git
cd downtime
make build
```
