/* Class: Account
 * --------------
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 * -------------
 * Class representing a student or a staff account in the university system.
 *
 * In the project, this class should be expanded to
 * include necessary methods and attributes.
 * */
#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>
#include <vector>

class Course;

const std::string NO_SIGNUPS = "No signups found on this course.";
const std::string SIGNED_UP = "Signed up on the course.";
const std::string COMPLETED = "Course completed.";
const std::string GRADUATED = "Graduated, all courses completed.";

class Account
{
public:
    /**
     * @brief Account constructor
     * @param full_name as "firstname lastname"
     * @param account_number
     * @param duplicates tells the number of full namesakes
     * @param university_suffix is the e-mail suffix e.g. "tuni.fi"
     */
    Account(const std::string& full_name, int account_number, int duplicates,
            const std::string& university_suffix);

    /**
     * @brief Account destructor
     */
    ~Account();

    /**
     * @brief print account info on one line
     */
    void print() const;

    /**
     * @brief get_email
     * @return email linked to this account
     */
    std::string get_email() const;

    /**
     * @brief get_full_name
     * @return full name of this account
     */
    std::string get_full_name() const;

    /**
     * @brief add_current_course
     * @param course that has been signed up
     * @return false if student have already completed the
     * course and an error message, and true if the course
     * can be registered
     */
    bool add_current_course(Course* new_course);

    /**
     * @brief add_finished_course
     * @param course that has been completed
     */

    void add_finished_course(Course* course);

    /**
     * @brief get_account_number
     * @return
     */
    int get_account_number() const;

    /**
     * @brief get_finished_course
     * @return all of the completed courses
     */
    std::vector<Course*> get_finished_course();

    /**
     * @brief get_current_course
     * @return all courses that have not been completed
     */
    std::vector<Course*> get_current_course();

    /**
     * @brief move all current course to completed course
     */
    void graduation();

    /**
     * @brief already_graduated
     * @return graduate status
     */
    bool already_graduated();

private:
    std::string full_name_;
    std::string last_name_;
    std::string first_name_;
    std::string email_;
    const int account_number_;

    // a vector that contains all completed courses of an account
    std::vector<Course*> finished_course_;

    // a vector that contains all current courses of an account
    std::vector<Course*> current_course_;

    // a boolean value that shows graduation status
    bool graduated_ = false;
};

#endif // ACCOUNT_HH


