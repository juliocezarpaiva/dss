# DEEP SEED SOLUTIONS’ 2022 RECRUITMENT PROGRAM

To run the program, make sure to run the compiler with the tags "-lstdc++" and "-lm"

To compile:
```
gcc main.cpp -o dss -lstdc++ -lm 
```
To run:
```
./dss
```

## Anotações

Production Unit (1) --> (N) Pipeline

Pipeline (1) --> (1) Manifold

Manifold (1) --> (N) Spool

Spool (1) --> (1) Weel


Existem diferentes Models, usados para calcular o diâmetro mínimo de cada Pipeline. Cada Model possui uma equação.
Cada empresa cliente pode usar mais de um Model para calcular o diametro do Pipeline.
É esperado que se possa adicionar mais Models ao longo do tempo.

Elaborar um programa que consiga, a partir de um Manifold, Spools e Weels já existentes, calcular, dado o Model, o diâmetro mínimo do Pipeline.

### Well
Name, diameter (pol.)

### Spool
Name, cost (dolár), diameter (pol.)

### Manifold
Name, connected Wells, connected Spools, Subsea Pipeline Diameter (a ser calculado)

### Model
Name, Subsea Pipeline Diameter

