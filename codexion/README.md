# Codexion

*This project has been created as part of the 42 curriculum by gasoares.*

---

## Description

**Codexion** is a concurrency simulation inspired by the classic dining philosophers problem.

Multiple coders (threads) compete for limited shared resources (USB dongles) in order to compile their code. Each coder must regularly compile to avoid burnout, while respecting strict timing constraints and fair resource scheduling.

The goal of the project is to design a robust multithreaded system using POSIX threads that:

* avoids deadlocks and starvation
* ensures fair access to resources
* respects precise timing constraints
* guarantees safe and synchronized logging

---

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./codexion number_of_coders time_to_burnout time_to_compile \
           time_to_debug time_to_refactor \
           number_of_compiles_required dongle_cooldown scheduler
```

### Example

```bash
./codexion 5 800 200 200 200 3 50 fifo
```

### Parameters

* `number_of_coders`: number of threads and dongles
* `time_to_burnout`: max time without compiling (ms)
* `time_to_compile`: duration of compilation (ms)
* `time_to_debug`: debugging time (ms)
* `time_to_refactor`: refactoring time (ms)
* `number_of_compiles_required`: optional stop condition
* `dongle_cooldown`: cooldown after release (ms)
* `scheduler`: `fifo` or `edf`

---

## Blocking cases handled

* **Deadlock prevention**
  Circular wait is avoided by enforcing an ordering strategy when acquiring dongles.

* **Starvation prevention**
  EDF scheduling ensures coders closest to burnout are prioritized.

* **Dongle cooldown**
  A dongle cannot be reused until its cooldown expires, preventing unrealistic reuse.

* **Burnout detection**
  A dedicated monitor thread continuously checks deadlines and stops the simulation within 10 ms of a burnout.

* **Log serialization**
  A mutex ensures logs are never interleaved or corrupted.

---

## Thread synchronization mechanisms

* **`pthread_mutex_t`**

  * Protects each dongle
  * Ensures exclusive access to shared resources
  * Used for log synchronization

* **`pthread_cond_t`**

  * Manages waiting queues for dongles
  * Enables efficient blocking instead of busy-waiting

* **Custom scheduling (FIFO / EDF)**

  * FIFO: first request served first
  * EDF: priority based on earliest burnout deadline

* **Race condition prevention**

  * All shared state (dongles, simulation status, timestamps) is protected by mutexes
  * Threads only access shared data inside critical sections

* **Monitor thread**

  * Independently checks coder deadlines
  * Safely communicates termination to all threads

---

## Resources

### Documentation

* POSIX Threads (pthreads)
* `man pthread_create`, `pthread_mutex_*`, `pthread_cond_*`
* `gettimeofday` for time management

### Concepts

* Dining Philosophers Problem
* Deadlocks & Coffman conditions
* Thread scheduling (FIFO vs EDF)

### AI usage

AI was used for:

* clarifying pthread behaviors and edge cases
* reviewing synchronization strategies
* improving documentation structure

All generated content was reviewed, tested, and fully understood before integration.

