# 📁 Course 5 Projects Portfolio

Welcome to my programming repository for Course 5! This portfolio showcases interactive console applications developed to master core software engineering concepts in C++. The focus throughout these projects was on writing structured clean code, optimizing memory management, and practicing problem-solving paradigms.

---

## 🎮 Projects Overview & My Experience

### 1. 🛑 Rock, Paper, Scissors Game (`project 1 course 5`)
An interactive implementation of the classic game against a randomized computer AI.
* **Core Features:** Dynamic round tracking, score validation loops, and session results calculation.
* **What I Learned & Gained:** * Mastered functional decomposition by breaking the game logic into independent, reusable functions.
  * Deepened my understanding of game loops and keeping a structured data flow across local scopes.

### 2. 🧮 Advanced Math Quiz Game
A comprehensive math challenge application that dynamically auto-generates arithmetic questions based on user-selected difficulty and operation types.
* **Core Features:**
  * **Dynamic Configurations:** Supports Easy, Medium, Hard, and a fully randomized `Mix` difficulty mode.
  * **Operations:** Includes Addition, Subtraction, Multiplication, Division, and a randomized `Mix` operation mode.
  * **Interactive UI/UX:** Integrated with real-time Windows System colors (Green for correct answers, Red for wrong answers) and instant audio alerts (`\a`) to enhance player feedback.
* **What I Learned & Gained:**
  * Advanced utilization of composite data types (`structs`) and custom tracking systems (`enums`) to bundle complex data pipelines together.
  * Gained a solid grasp of back-end memory management principles by utilizing **Pass-by-Reference (`&`)** to eliminate redundant object copying and optimize system memory.

---

## 🧠 Technical Challenges & Problem Solving (My Deep Thinking Journey)

As a back-end developer, encountering bugs is part of the process, but solving them through deep engineering thought was the most rewarding part of this course:

1. **The Naming Collision & Scope Trap (The Visual Studio Compiler Challenge):**
   * *The Problem:* While building the Math Quiz, the compiler threw a critical redefinition error (`error C2365`) pointing at the word `div` inside my operation Enum, and `mix` which was duplicated across both the Level and Operation enums. C++ was getting confused between my custom variables and its built-in global mathematical functions.
   * *The Solution:* After deep analysis of global versus local scope mechanics in C++, I realized I needed clear structural naming conventions. I refactored the names to unique identifiers: `DivOP`, `mixLevel`, and `MixOperation`. This successfully bypassed naming collisions and restored stable compiler behavior.

2. **Data Pipeline Restrictions:**
   * *The Problem:* Game statistics and final scoring results were getting trapped and erased within localized function scopes upon completion.
   * *The Solution:* I restructured the function signatures to alter their return types directly to custom objects (`stQuizz`), bridging the data pipeline seamlessly into the final presentation wrapper (`PrintQuizResults`).

---

## 🛠️ Skills & Technologies Applied
* **Language:** C++
* **IDE:** Visual Studio 2022
* **Back-End Concepts:** Object Pass-by-Reference, Scope Isolation, Input Validation Layouts, Pseudo-Random Generation Systems, Struct-to-Function Pipelines, and Compile-Time Error Debugging.

---

## 🚀 How to Run
1. Clone this repository locally.
2. Open the desired folder and launch the `.sln` file via **Visual Studio 2022**.
3. Press `Ctrl + F5` to compile and run the application.