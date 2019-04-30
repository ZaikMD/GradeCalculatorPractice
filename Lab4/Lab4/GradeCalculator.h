/*
Made by Zach Dubuc
Lab 4 converted into C++
April 30, 2019
*/
#pragma once
#include <string.h>
#include <iostream>



class GradeCalculator
{
public:
	GradeCalculator();
	~GradeCalculator();

	void getMarks();
	void calculateGrades();
	void displayGrades();

private:
	double m_Test;
	double m_Assignment;
	double m_Lab;
	double m_Midterm;
	double m_FinalExam;
	double m_FinalPractical;
	double m_Theory;
	double m_Practical;
	double m_FinalGrade;

	double checkInput(std::string input, double maxValue);
	void clearInput();
};
