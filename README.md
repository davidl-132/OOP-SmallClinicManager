# Small Clinic Management System -- OOP Assignment

## 📌 Overview

-   `smallclinic.cpp` -- A **Clinic Management System** built with
    **Object-Oriented Programming (OOP) in C++**.\
-   The system manages:
    -   **Patients** (regular & chronic)\
    -   **Doctors**\
    -   **Appointments**\
    -   **Prescriptions**\
    -   **Staff** (with specialization for **Security Guards**)\
-   Demonstrates **encapsulation, inheritance, polymorphism, and
    abstraction** in a real-world scenario.

------------------------------------------------------------------------

## ⚙️ Build & Run Instructions

### On Linux / macOS / WSL:

``` bash
g++ smallclinic.cpp -o clinic
./clinic
```

### On Windows (MinGW g++):

``` bash
g++ smallclinic.cpp -o clinic.exe
clinic.exe
```

------------------------------------------------------------------------

## 🧩 Features

-   Register **Patients** (regular or chronic).\
-   Register **Doctors**.\
-   Schedule, cancel, and complete **Appointments**.\
-   Maintain **Medical History** for each patient.\
-   Create and manage **Prescriptions** with a list of medicines.\
-   View all prescriptions or prescriptions by patient.\
-   Register and manage **Staff**, including **Security Guards**.\
-   Security guards can maintain **activity logs**.\
-   Prevents **schedule conflicts** when booking appointments.

------------------------------------------------------------------------

## 🤖 AI Disclosure

-   Author: **Ly Tran Gia Khang -- 24110098**\
-   Used **ChatGPT** for:
    -   Brainstorming new class ideas (e.g., Prescription,
        SecurityGuard).\
    -   Understanding how to override virtual methods.\
    -   Suggestions for input validation and menu-driven structure.\
-   All code was **understood, tested, and customized** before
    submission.

------------------------------------------------------------------------

## 📝 Reflection

This project helped me deepen my understanding of **OOP principles**.
Creating base classes like `Patient` and `Staff`, then extending them
into `ChronicPatient` and `SecurityGuard`, gave me practical experience
with **inheritance and polymorphism**. Overriding virtual methods, such
as `scheduleAppointment()` and `getRole()`, demonstrated how different
object types can share an interface but behave differently.

One major challenge was ensuring **data consistency** across multiple
classes, especially when canceling or completing appointments while
keeping patient medical history accurate. Designing the **Prescription**
class also highlighted how to manage dynamic collections (lists of
medicines) in a structured way.

Although the system works, I see opportunities for improvement in:\
- Expanding staff roles beyond security guards.\
- Enhancing data persistence (e.g., saving to files or database).\
- Refining error handling for better user experience.

This assignment not only improved my coding skills but also taught me
how to design **scalable, real-world OOP applications**.
