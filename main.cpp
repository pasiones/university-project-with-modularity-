/* University
 *
 * The program consists of classes Account, Course, University, Cli, and Utils module
 * as well as the main program module. The main program module is very simple. It just starts
 * the command line interpreter (CLI) that goes on until the QUIT command is given by the user.
 *
 * The program contains the module Utils that is not a class but a namespace. It provides the
 * utility function split
 *
 * The class Account describes persons: students and teachers (staff). These persons are not
 * separated at all. When a new person (account) is added, they get an account number (that can
 * be called a student number in the case of a student). Account numbers are running numbers such
 * that the first person added gets the number 111111. Besides the account number, each person has
 * a name and contact information. For each new account, the program generates automatically an
 * e-mail address with the suffix tuni.fi such that accounts with the same name have different e-mail addresses.
 * An account has a vector containing current signups for courses and another vector containing passed courses.
 * This is essential especially for students, but also teachers can have on-going and passed courses.
 *
 * The class Course describes a course. From each course, you must know its code, name, credit points,
 * and course staff (there can be several of them). By default, all courses give five credit points.
 * It is possible to add staff and students for a course, as well as print course data.
 *
 * The class University describes a university (in general, there can be several of them,
 * but in this program, we need only one). The class contains information about all the
 * courses and persons in the university. As said earlier, a person can be a student or a teacher.
 * For this data, the class has map structures that are added with new elements based on user-given
 * commands. It is possible for students to sign up for courses and complete (pass) courses.
 *
 * The valid commands are:
 *
 * 1) QUIT - The program terminates with the return value EXIT_SUCCESS without printing anything.
 * The command takes no parameters, but if such are given, they will be ignored.
 *
 * 2) NEW_ACCOUNT <full name> - The command adds students and staff to the university.
 * In each case, the added person is equipped with an account number (which can be called
 * a student number in the case of a student). The first person added gets the number 111111,
 * the second one gets 111112, and so on. (The account number will be used as a parameter for
 * other commands.) The command generates a new, unique e-mail address automatically for a new account.
 *
 * 3) PRINT_ACCOUNT <account number> - The command prints information about the given person.
 *
 * 4) PRINT_ACCOUNTS - The command prints information about all persons, ordered according
 * to their account numbers.
 *
 * 5) NEW_COURSE <code> <name> - The command creates a new course. By default,
 * all courses are worth of five study points (5 ects).
 *
 * 6) ADD_STAFF <code> <account number> - The command adds the given teacher for the given course.
 *
 * 7) PRINT_COURSE <code> - The command prints information about the given course: name, code, and teachers.
 * The teachers of the course are printed in the same order in which they have been added.
 *
 * 8) PRINT_COURSES - The command prints all the courses in the university according to their codes.
 *
 * 9) HELP - If the user gives no parameter for the command, it prints all available commands with their acronyms.
 *
 * 10) READ_FROM <file> - The command reads other commands with their parameters from the given file,
 * which makes testing the program easier.
 *
 * 11) SIGN_UP <code> <student number> - The command signs up the given student for the given course.
 *
 * 12) COMPLETE <code> <student number> - The command gives credit for the given student from the given course.
 *
 * 13) PRINT_STUDY_STATE <student number> - The command prints the study state of the given student: signups for courses
 * (current courses), passed courses, and the total credits of the passed courses. Current courses are printed in the
 * same order in which the student has signed up for them. Similarly, the passed courses are printed in the same order
 * in which the student has passed them.
 *
 * 14) PRINT_COMPLETED <student number> - The command prints the courses completed by the given student and the
 * total credits of them. Courses are printed in the same order in which the student has passed them.
 *
 * 15) PRINT_SIGNUPS <code> - The command prints students signed up for the given course.
 * Students are printed in the order they have signed up for the course.
 *
 * 16) GRADUATE <student number> - The command makes the given student graduated from the university.
 * Then all their courses become completed, and they cannot sign up for any courses.
 * The command makes current courses completed in the order, the student has signed up for them.
 *
 * After the program has done the neccessary behaviour of the user's command, it will print the prompt
 * again until the user enters the command "QUIT".
 *
 * Program authors:
 * Name: Dat Minh Lam
 * Student number: 151395774 (Dat Minh Lam)
 * UserID: vhdala (Dat Minh Lam)
 * E-Mail: datminh.lam@tuni.fi
 *
 * Notes about the program and it's implementation (if any):
 *
 */
//#include "utils.hh"
#include "cli.hh"
#include "university.hh"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>

const std::string PROMPT = "Uni> ";


int main()
{
    University* university = new University("tuni.fi");
    Cli cli(university, PROMPT);
    while ( cli.exec() ){}

    delete university;
    return EXIT_SUCCESS;
}

