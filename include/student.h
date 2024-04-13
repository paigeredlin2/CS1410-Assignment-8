#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>

class StudentGrades
{
private:
    // datamembers
    std::string id, letter_grade;
    double activities_grade, assignments_grade, discussions_grade, project_grade, exam_grade, total_grade;

public:
    // constructors of the class objects
    StudentGrades() {}
    StudentGrades(std::string eID, double ag, double asg, double dg, double pg, double eg) : id(eID), activities_grade(ag), assignments_grade(asg), discussions_grade(dg), project_grade(pg), exam_grade(eg) {}

    // setters and getters
    void setID(std::string eID) { this->id = eID; }
    std::string getID() { return this->id; }

    void setActivitiesG(double ag) { this->activities_grade = ag; }
    double getActivitesG() { return this->activities_grade; }

    void setAssignmentsG(double asg) { this->assignments_grade = asg; }
    double getAssignmentsG() { return this->assignments_grade; }

    void setDiscussionG(double dg) { this->discussions_grade = dg; }
    double getDiscussionG() { return this->discussions_grade; }

    void setProjectG(double pg) { this->project_grade = pg; }
    double getProjectG() { return this->project_grade; }

    void setExamG(double eg) { this->exam_grade = eg; }
    double getExamG() { return this->exam_grade; }

    // class methods
    const double finalGrade()
    {
        total_grade = (.1 * activities_grade) +
                      (.25 * assignments_grade) +
                      (.15 * discussions_grade) +
                      (.15 * project_grade) +
                      (.35 * exam_grade);
        return total_grade;
    }

    const std::string letterGrade()
    {
        if (total_grade >= 94.0)
        {
            letter_grade = "A";
        }
        else if (total_grade >= 90.0)
        {
            letter_grade = "A-";
        }
        else if (total_grade >= 87.0)
        {
            letter_grade = "B+";
        }
        else if (total_grade >= 80.0)
        {
            letter_grade = "B";
        }
        else if (total_grade >= 77.0)
        {
            letter_grade = "C+";
        }
        else if (total_grade >= 74.0)
        {
            letter_grade = "C";
        }
        else if (total_grade >= 70.0)
        {
            letter_grade = "D";
        }
        else
        {
            letter_grade = "F";
        }
        return letter_grade;
    }

    ~StudentGrades() {} // default destructor
};

#endif