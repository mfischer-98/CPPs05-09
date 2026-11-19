# CPP Module 05 — Repetition and Exceptions

This module introduces **C++ exceptions** (`try`, `throw`, `catch`), custom exception classes inheriting from `std::exception`, abstract base classes (`AForm`), and polymorphic object creation through a simple factory (`Intern`)—all written in **C++98** following Orthodox Canonical Form.

---

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

---

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

---

## ex01: Form

Introduces a `Form` class with a constant name, a boolean `_signed` flag (default `false`), and constant grade requirements to sign and execute.

### Design decisions
- **`beSigned()` validates the bureaucrat's grade.** If the bureaucrat's grade is numerically greater than `_gradeToSign`, it throws `Form::GradeTooLowException`.
- **`Bureaucrat::signForm()` catches internally.** Instead of letting exceptions crash `main`, `signForm()` wraps `beSigned()` in `try/catch` and prints either `<bureaucrat> signed <form>` or `<bureaucrat> couldn't sign <form> because <reason>`.

---

## ex02: Concrete Forms & Abstract `AForm`

`Form` becomes an abstract base class (`AForm`) with three concrete implementations:
- **`ShrubberyCreationForm` (sign 145, exec 137):** Writes ASCII trees to `<target>_shrubbery`.
- **`RobotomyRequestForm` (sign 72, exec 45):** Makes drilling noises and succeeds 50% of the time (`rand()`).
- **`PresidentialPardonForm` (sign 25, exec 5):** Announces that `<target>` has been pardoned by Zaphod Beeblebrox.

### Design decisions
- **Shared validation in `AForm::execute()`.** Checking whether the form is signed (`FormNotSignedException`) and whether the executor's grade is sufficient (`GradeTooLowException`) happens once in the base class before calling a pure virtual hook (`executeAction()`).
- **Virtual destructor (`virtual ~AForm()`).** Essential whenever deleting derived forms through an `AForm*` pointer.

---

## ex03: Intern (`makeForm` & `switch` dispatch)

Implements an `Intern` class whose `makeForm(name, target)` method dynamically allocates and returns the matching `AForm*`, or prints an error and returns `NULL` if the name is unknown.

### How `switch` works & why it was used here
The subject forbids long `if / else if / else` chains. In C++98, `switch` only evaluates **integral types** (`int`, `char`, `enum`)—not `std::string`. To use `switch` cleanly:
1. Store the valid form names (`"presidential pardon"`, `"robotomy request"`, `"shrubbery creation"`) in a fixed array.
2. Loop through the array to find the matching index `i`.
3. If `i == 3`, print an error message to `std::cerr` and return `NULL` early.
4. Otherwise, pass `i` into `switch (i)` to instantiate and return the right derived form with `new`.

### What I learned across CPP05
- **Exceptions + Polymorphism:** Derived classes can throw specific exceptions and still be caught uniformly by base reference (`const std::exception&`).
- **Centralizing preconditions:** Putting signature and grade checks in `AForm::execute()` prevents duplicated validation across every concrete form.
- **`switch` limitations in C++98:** Strings cannot be switched on directly; mapping a string to an integer index first keeps dispatch flat and readable (an alternative is an array of member function pointers).
- **Caller ownership with `new`:** Returning `AForm*` from a factory transfers heap ownership to the caller—every valid pointer must be freed with `delete`, relying on `virtual ~AForm()` for proper cleanup.