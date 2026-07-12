# Compiler Optimization Techniques

A reference guide to GCC compiler optimization flags used in embedded systems development.

---

## Optimization Levels Overview

| Flag | Name | Focus |
|------|------|-------|
| `-O0` | No Optimization | Debugging ease |
| `-O1` | Basic Optimization | Minimal improvements |
| `-O2` | Standard Optimization | Balanced performance |
| `-O3` | Aggressive Optimization | Maximum speed |
| `-Os` | Size Optimization | Minimal binary size |
| `-Ofast` | Fast Optimization | Highest performance |

---

## `-O0` — No Optimization

> **Description:** The compiler generates code without any optimizations. It focuses on reducing the time required for compilation and simplifying debugging.

| | |
|---|---|
| ✅ **Pros** | Easy to debug; the generated machine code closely matches the source code. |
| ❌ **Cons** | The code may be slow and consume more memory, which is not ideal for embedded systems. |

---

## `-O1` — Basic Optimization

> **Description:** This level provides basic optimizations that do not significantly increase compilation time. It performs simple enhancements like eliminating redundant code and combining operations.

| | |
|---|---|
| ✅ **Pros** | Generally faster code execution with a slight increase in compilation time; still relatively easy to debug. |
| ❌ **Cons** | Limited improvements compared to higher optimization levels. |

---

## `-O2` — Standard Optimization

> **Description:** A balanced level that offers substantial performance improvements without extreme increases in compilation time. It includes all `-O1` optimizations and adds more aggressive optimizations like loop unrolling and inlining.

| | |
|---|---|
| ✅ **Pros** | Good trade-off between performance and compilation time; significantly improves execution speed and reduces code size. |
| ❌ **Cons** | Slightly harder to debug due to more complex transformations. |

---

## `-O3` — Aggressive Optimization

> **Description:** This level performs aggressive optimizations to maximize execution speed, including those in `-O2` and additional ones like aggressive inlining and vectorization.

| | |
|---|---|
| ✅ **Pros** | Maximizes performance, making it ideal for compute-intensive tasks. |
| ❌ **Cons** | Can increase code size and compilation time; harder to debug; may introduce subtle bugs or unexpected behaviors due to aggressive optimizations. |

---

## `-Os` — Size Optimization

> **Description:** Optimizes code size by enabling all `-O2` optimizations that do not increase the binary size and disables those that do. Useful for systems with strict memory constraints.

| | |
|---|---|
| ✅ **Pros** | Reduces code size significantly, making it suitable for memory-limited embedded systems. |
| ❌ **Cons** | May sacrifice some performance for size reduction; harder to debug compared to no optimization. |

---

## `-Ofast` — Fast Optimization

> **Description:** This level disregards strict compliance with language standards to prioritize performance. It includes all `-O3` optimizations and enables non-standard optimizations.

| | |
|---|---|
| ✅ **Pros** | Offers the highest performance boost. |
| ❌ **Cons** | May produce non-standard-compliant code; higher risk of bugs and undefined behavior; difficult to debug. |

---

## Optimization Level Comparison

```
Performance:  O0 ──── O1 ──── O2 ──── O3 ──── Ofast
               ↑                               ↑
             Slowest                         Fastest

Binary Size:  O0 ──── O1 ──── Os ──── O2 ──── O3
               ↑               ↑               ↑
             Larger         Smallest         Larger

Debug-ability: Ofast ─ O3 ─── O2 ─── O1 ──── O0
                 ↑                             ↑
              Hardest                        Easiest
```

---

> **💡 Tip for Embedded Systems:** Start with `-O2` for a balanced approach. Use `-Os` when flash/RAM is constrained. Avoid `-Ofast` in safety-critical systems due to undefined behavior risks.
