# 📦 push_swap

A sorting algorithm project written in C for 42 School. The goal is to sort a stack of integers using a limited set of operations, minimizing the number of moves required.

---

## 📖 Table of Contents

- [About](#about)
- [Usage](#usage)
- [Allowed Operations](#allowed-operations)
- [Compilation](#compilation)
- [Example](#example)
- [Structure](#structure)
- [Bonus](#bonus)
- [Author](#author)

---

## 📌 About

The **push_swap** program sorts a stack of integers using a restricted set of operations and outputs the list of moves needed to sort them in ascending order. The challenge is to minimize the total number of moves.

---

## ⚙️ Usage

```bash
./push_swap [list of integers]
````

### Example:

```bash
./push_swap 3 2 1
```

Output:

```
sa
rra
```

---

## 📋 Allowed Operations

| Operation | Description                      |
| --------- | -------------------------------- |
| `sa`      | Swap the first two elements of A |
| `sb`      | Swap the first two elements of B |
| `ss`      | `sa` and `sb` at the same time   |
| `pa`      | Push the top of B onto A         |
| `pb`      | Push the top of A onto B         |
| `ra`      | Rotate stack A up by one         |
| `rb`      | Rotate stack B up by one         |
| `rr`      | `ra` and `rb` at the same time   |
| `rra`     | Reverse rotate stack A           |
| `rrb`     | Reverse rotate stack B           |
| `rrr`     | `rra` and `rrb` at the same time |

---

## 🛠️ Compilation

To compile the project:

```bash
make
```

To clean object files:

```bash
make clean
```

To remove object files and binary:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

---

## 📊 Example

```bash
./push_swap 5 1 4 2 3
```

Sample Output:

```
pb
pb
sa
ra
pa
pa
ra
ra
```

---

## 📂 Structure

```
.
├── Makefile
├── push_swap.c
├── libft/         # Custom C library
├── includes/      # Header files
├── srcs/          # Project source files
└── README.md
```

---

## 🌟 Bonus

If implemented, the bonus includes a `checker` program which takes input and operations, verifying whether the result is correctly sorted.

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

Expected output:

```
OK
```

---

## 👤 Author

**Adeline Eminian**
GitHub: [@Adel2k](https://github.com/Adel2k)
