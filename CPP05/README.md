## Exceptions: try / throw / catch basics

An exception is a way for code to signal "I can't continue normally"
without relying on a return value. Three keywords are involved:

- `throw`: raises an exception and immediately leaves the current function.
- `try`: wraps the code that might throw.
- `catch`: handles a specific exception type thrown inside the `try`.

### Generic shape
```cpp
try {
    // code that may throw
}
catch (const SomeException& e) {
    // runs only if SomeException (or a derived class) was thrown
}
```

### How it flows
1. `throw` executes and the rest of that function is skipped.
2. The program leaves scopes one by one (stack unwinding), destroying
   every fully constructed local object on the way.
3. The first matching `catch` handles it, then execution continues
   after the whole try/catch block.
4. If no `catch` matches, `std::terminate()` is called and the
   program aborts.

### Rules I learned
- **Catch by reference** (`const std::exception&`) to avoid slicing and keep
  the virtual `what()` working. `const` because we only read it.
- **Order matters:** handlers are checked top to bottom and the first match
  wins, so catch derived types before `std::exception`.
- **Scope:** an object declared inside `try { }` is not visible after it.
- **Constructors:** if one throws, the object doesn't exist and its
  destructor does not run.
- **`catch (...)`** matches any exception type, but gives no access to it.
- **Custom exceptions** derive from `std::exception` and override
  `what() const throw()` (C++98 syntax).
- **Check before modifying:** validating first means a failed call leaves
  the object unchanged.

## ex00: Bureaucrat

A `Bureaucrat` has a constant name and a grade from 1 (highest) to 150 (lowest).

### Design decisions
- **Invalid grades throw.** The constructor throws `GradeTooHighException`
  (grade < 1) or `GradeTooLowException` (grade > 150) instead of clamping,
  so every existing Bureaucrat is always valid.
- **Check, then modify.** `incrementGrade()` / `decrementGrade()` validate
  before changing `_grade`, so a failed call leaves the object unchanged.
- **Exceptions derive from `std::exception`** and override `what()`,
  so they can be caught as `std::exception&`.
- **Orthodox Canonical Form** is implemented. `operator=` copies only the
  grade because `_name` is `const`.

### Concepts learned
- Constructor throws -> no object, no destructor call.
- Catch by (const) reference to avoid slicing.
- Destruction order is the reverse of construction order.
- `T x = y;` is copy construction; `x = y;` is assignment.
- An uncaught exception calls `std::terminate`.

### Tests (main.cpp)
Valid creation, copy/assignment, invalid grades (200, -10),
and increment/decrement at the limits (1 and 150).