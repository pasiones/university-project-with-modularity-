#include "course.hh"
#include <iostream>
#include <algorithm>
Course::Course(const std::string& code, const std::string& name, int credits):
    course_code_(code), name_(name), credits_(credits)
{
}

Course::~Course()
{
}

void Course::print_info(bool print_new_line)
{
    std::cout << course_code_ << " : " << name_;
    if ( print_new_line )
    {
        std::cout << std::endl;
    }
}

void Course::print_long_info()
{
    std::cout << "* Course name: " << name_ << std::endl
              << "* Code: " << course_code_ << std::endl;
    print_staff();
}

void Course::print_staff()
{
    std::cout << "* Staff: " << std::endl;
    for (auto member : course_staff_ )
    {
        member->print();
    }
}

void Course::print_student()
{
    for (auto member : all_students_ )
    {
        member->print();
    }
}

void Course::add_staff(Account *new_staff_member)
{
    // Checking if account is already a staff member
    for ( unsigned int i = 0; i < course_staff_.size(); ++i )
    {
        if ( course_staff_.at(i) == new_staff_member )
        {
            std::cout << STAFF_EXISTS << std::endl;
            return;
        }
    }

    course_staff_.push_back(new_staff_member);
    std::cout << STAFF_ADDED << std::endl;
}

void Course::add_student(Account *new_student_member)
{
    // Checking if account is already a student member
    for ( unsigned int i = 0; i < course_student_.size(); ++i )
    {
        if ( course_student_.at(i) == new_student_member )
        {
            std::cout << STUDENT_EXISTS << std::endl;
            return;
        }
    }

    course_student_.push_back(new_student_member);
    all_students_.push_back(new_student_member);
    std::cout << SIGNED_UP << std::endl;
}

bool Course::complete_course(Account *current_student_member)
{
    //Checking if the student is in the course or not
    auto it = std::find(course_student_.begin(), course_student_.end(),
                        current_student_member);
    if (it == course_student_.end()) {
        std::cout << NO_SIGNUPS << std::endl;
        return false;
    }
    course_student_.erase(it);
    std::cout << COMPLETED << std::endl;
    return true;
}


const std::string Course::get_code() const
{
    return course_code_;
}

int Course::get_credits() const
{
    return credits_;
}




