# Quicksort Pivot Analysis

This repository contains my individual mini-project for a systems-level performance analysis course. The project evaluates the performance of quicksort implementations with different pivot selection strategies, focusing on how low-level factors influence runtime beyond simple algorithmic complexity.

The analysis examines how different pivoting strategies affect:

* Compiler optimization and generated assembly

* Branch predictability during partitioning

* Memory access patterns and cache behavior

* Sensitivity to input characteristics (random, sorted, reverse-sorted, etc.)

Multiple quicksort variations were implemented in C and tested on large inputs to produce measurable performance differences. Experiments were conducted on x86-64 Linux using standard timing and profiling tools such as high-resolution timers and perf.

The accompanying report details the experimental methodology, results, and insights into how pivot choice interacts with modern CPU architecture and compiler optimizations.
