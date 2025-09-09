# Small Clinic Management System – OOP Assignment

## 📌 Overview
- `smallclinic.cpp` – A simple **Clinic Management System** built with **Object-Oriented Programming (OOP) in C++**.  
- The system manages:
  - **Patients** (regular & chronic)  
  - **Doctors**  
  - **Appointments**  
- Demonstrates **classes, objects, inheritance, encapsulation, and polymorphism**.  

---

## ⚙️ Build & Run Instructions

### On Linux / macOS / WSL:
```bash
g++ smallclinic.cpp -o clinic
./clinic
```

### On Windows (MinGW g++):
```bash
g++ smallclinic.cpp -o clinic.exe
clinic.exe
```

---

## 🤖 AI Disclosure
- Author: **Ly Tran Gia Khang – 24110098**  
- Used **ChatGPT** for brainstorming ideas (e.g., methods for Appointment, how to override virtual functions, and improving code readability).  
- All code has been **understood, tested, and personalized** before submission.  

---

## 📝 Reflection

During this assignment, I gained a deeper understanding of Object-Oriented Programming (OOP) concepts, especially inheritance and polymorphism. Designing the Patient base class and extending it with the ChronicPatient subclass helped me clearly see how inheritance allows us to avoid code duplication while still adapting behavior for different types of patients. Implementing virtual and overridden methods gave me practical experience in applying polymorphism to real-world scenarios.

At the same time, I also faced several challenges. The most difficult part was ensuring proper synchronization between the medicalHistory records of patients and the appointment objects. Although I implemented features like adding, canceling, and completing appointments, the way these changes are reflected in the patient’s history still feels incomplete and not fully polished. This highlighted the complexity of keeping data consistent across multiple classes in a real-world management system, and it is something I would like to improve further in the future.
