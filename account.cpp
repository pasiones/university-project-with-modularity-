#include "account.hh"
#include "course.hh"
#include "utils.hh"
#include <iostream>
#include <algorithm>
Account::Account(const std::string& full_name, int account_number,
                 int duplicates, const std::string& university_suffix):
    full_name_(full_name),
    last_name_(""),
    first_name_(""),
    account_number_(account_number)
{
    std::vector<std::string> name = Utils::split(full_name_, ' ');
    last_name_ = name.back();
    first_name_ = name.front();

    // Constructing e-mail address
    email_ = Utils::to_lower(first_name_);
    email_ += ".";
    if ( duplicates > 0 )
    {
        email_ += std::to_string(duplicates);
        email_ += ".";
    }
    email_ += Utils::to_lower(last_name_);
    email_ += "@";
    email_ += university_suffix;
}

Account::~Account()
{
}

void Account::print() const
{
    std::cout << account_number_ << ": "
              << first_name_ << " "
              << last_name_  << ", "
              << email_ << std::endl;
}

std::string Account::get_email() const
{
    return email_;
}

std::string Account::get_full_name() const
{
    return full_name_;
}

bool Account::add_current_course(Course* new_course)
{
    auto it = std::find(finished_course_.begin()
                        , finished_course_.end(),new_course);
    if (it != finished_course_.end())
    {
        std::cout << STUDENT_COMPLETED << std::endl;
        return false;
    }
    else
    {
        current_course_.push_back(new_course);
        return true;
    }

}

void Account::add_finished_course(Course* course)
{
    auto it = std::find(current_course_.begin()
                        , current_course_.end(), course);
    if (it != current_course_.end())
    {
        finished_course_.push_back(std::move(*it));
        current_course_.erase(it);
    }
}

int Account::get_account_number() const
{
    return account_number_;
}

std::vector<Course*> Account::get_finished_course()
{
    return finished_course_;
}

std::vector<Course*> Account::get_current_course()
{
    return current_course_;
}

void Account::graduation()
{
    graduated_ = true;
    for (auto& course : current_course_)
    {
        finished_course_.push_back(std::move(course));
    }
    current_course_.clear();
    std::cout << GRADUATED << std::endl;
}

bool Account::already_graduated()
{
    return graduated_;
}


