#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "student.h"

using namespace std;

int main()
{
  // there will be 20 student objects so I should create an array to hold the memory space
  StudentGrades students[20];

  // these are the datamembers I will be able to read from the file
  string id;
  double ag, asg, dg, pg, eg;

  // read the file
  ifstream fin("grades.txt");

  // A vector to hold the 6 headings of the txt doc
  vector<string> headings(6);
  fin >> headings[0] >> headings[1] >> headings[2] >> headings[3] >> headings[4] >> headings[5]; // reading the 6 headings

  // now that I have read the headers I can read the data by line for each object and using the set methods to add values to the objects' datamembers

  // for StudentGrades object st in students array
  for (StudentGrades &st : students)
  {
    fin >> id >> ag >> asg >> dg >> pg >> eg;
    st = StudentGrades(id, ag, asg, dg, pg, eg);
  }

  fin.close();

  ofstream fout("processed-grades.txt");
  fout << setw(10) << left << headings[0]
       << setw(11) << right << headings[1]
       << setw(12) << right << headings[2]
       << setw(12) << right << headings[3]
       << setw(8) << right << headings[4]
       << setw(7) << right << headings[5]
       << setw(8) << right << "TOTAL"
       << setw(6) << right << "GRADE"
       << endl;
  for (StudentGrades &st : students)
  {
    fout << setw(10) << left << st.getID()
         << setw(11) << right << st.getActivitesG()
         << setw(12) << right << st.getAssignmentsG()
         << setw(12) << right << st.getDiscussionG()
         << setw(8) << right << st.getProjectG()
         << setw(7) << right << st.getExamG()
         << setw(8) << right << fixed << setprecision(2) << st.finalGrade()
         << setw(6) << right << st.letterGrade()
         << endl;
  }

  return 0;
}