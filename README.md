# Scheduler Simulation in C

A low-level scheduler simulation written from scratch in C.

This project exists to understand **how CPU scheduling works internally**
by designing and implementing it manually, rather than consuming tutorials
or relying on pre-built abstractions.

This is **not an operating system**.
It is a **user-space simulation** built to reason about scheduling decisions,
state transitions, and invariants that real kernels must maintain.

---

## Motivation

I deliberately chose to build this instead of following standard learning paths.

I noticed that:
- Tutorials felt passive and easy to forget
- Copy–pasting implementations taught syntax, not systems thinking
- Concepts only became clear once I **designed them, broke them, and fixed them**

Scheduling in particular appears simple at a high level, but quickly becomes
non-trivial once constraints like fairness, priority, and time slicing are introduced.

Instead of treating scheduling as theory, this project models it
**from first principles**, in C, where:
- all data structures are explicit
- all state transitions must be justified
- inefficiencies and flawed assumptions are immediately visible

The goal is **understanding**, not completeness or performance.

---

## Design philosophy

This project is built with a few intentional constraints:

- **Pure C**
  - No object-oriented abstractions
  - No STL-style containers
  - Manual data-structure management

- **Invariant-driven design**
  - Runnable processes exist only in ready queues
  - Scheduling decisions never scan all processes
  - State transitions are explicit and event-driven

- **Iteration over polish**
  - Designs are rewritten when inefficiencies appear
  - Complexity is analyzed and reduced deliberately
  - Features are added only when the core model is stable

Parts of the project may look limited or unfinished.
That is intentional.

---

## What the project currently does

- Simulates **process scheduling** in user space
- Implements **round-robin scheduling with priorities**
- Models a basic **process lifecycle**:
  - READY
  - RUNNING
  - TERMINATED

- Uses:
  - Circular queues per priority level
  - Fixed time slices
  - Explicit enqueue and dequeue operations

- Tracks:
  - Execution order
  - Per-process progress
  - Completion and termination

The scheduler always selects the **highest-priority non-empty queue**
and runs one process for a time slice before making the next decision.

---

## What this project is not

- Not a kernel
- Not multithreaded
- Not optimized for real workloads
- Not a tutorial or framework clone

It does not aim to replicate Linux or any production scheduler.
It exists to build intuition about *why* schedulers are structured the way they are.

---

## Planned extensions

Possible future additions include:
- Blocked / waiting states
- Wake-up events
- Priority aging or starvation mitigation
- More explicit time and event modeling

These will only be added once existing invariants remain stable.

