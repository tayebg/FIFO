# FIFO — CPU Scheduling Simulator

A command-line program in C that implements the FIFO (First-In, First-Out) / FCFS (First-Come, First-Served) non-preemptive CPU scheduling algorithm. This project is designed for educational purposes, particularly for Operating Systems courses.

## Features
- Dynamic process allocation
- Arrival-time sorting
- Comprehensive metric calculation (completion time, turnaround time, waiting time, averages)

## Tech Stack
- C (standard C99/C11)
- Standard Library only (stdio.h, stdlib.h, string.h)

## Getting Started

### Prerequisites
- GCC or any standard C compiler

### Build
```bash
make
# or manually
gcc -Wall -Wextra fifo.c -o fifo
```

### Run
```bash
./fifo
# or fifo.exe on Windows
```

## How It Works
The FIFO/FCFS scheduling algorithm executes processes strictly in the order of their arrival. It is a non-preemptive policy. The simulator calculates key metrics for each process, including completion time, turnaround time, and waiting time, as well as the overall averages.

## Sample Usage
```
Entrer Le Nombre De Processus :
3
Entrer La Politique : 
FIFO
P[1] 
Temps d'arrive: 0
Temps d'execution: 5
P[2] 
...
```

## Contributing
Contributions are welcome. Please open an issue or submit a pull request if you have suggestions for improvements.

## License
This project is licensed under the MIT License.

## Author
[Tayeb Bekkouche](https://github.com/tayebg)
