/*
Made by Zach Dubuc
Lab 4 converted into C++
April 30, 2019
*/
#include "pch.h"
#include "GradeCalculator.h"
#include <regex>

//Initial constructor
GradeCalculator::GradeCalculator()
{
	std::cout << "Welcome to the Grade Calculator" << std::endl;
	m_Test = -1;
	m_Assignment = -1;
	m_Lab = -1;
	m_Midterm = -1;
	m_FinalExam = -1;
	m_FinalPractical = -1;
	m_Theory = -1;
	m_Practical = -1;
	m_FinalGrade = -1;
}

//Deconstructor
GradeCalculator::~GradeCalculator()
{
	std::cout << "Object is being deleted" << std::endl;
}

//Get marks with ask the user to input the marks required for finding the total grade
void GradeCalculator::getMarks()
{
	//String for input
	std::string input;

	std::cout << "Please enter your marks: " << std::endl;

	//Test input
	std::cout << "Test out of 5%: " << std::endl;
	std::cin >> input;
	clearInput();
	m_Test = checkInput(input, 5);
	

	
	//Assignment input
	std::cout << "Assignment out of 20%: " << std::endl;
	std::cin >> input;
	clearInput();
	m_Assignment = checkInput(input, 20);

	//lab input
	std::cout << "Lab out of 15%: " << std::endl;
	std::cin >> input;
	clearInput();
	m_Lab = checkInput(input, 15);


	//Midterm input
	std::cout << "Midterm out of 20%: " << std::endl;
	std::cin >> input;
	clearInput();
	m_Midterm = checkInput(input, 20);

	//Final exam input
	std::cout << "Final Practical out of 10%: " << std::endl;
	std::cin >> input;
	clearInput();
	m_FinalPractical = checkInput(input, 10);

	//Final exam input
	std::cout << "Final Exam out of 30%: " << std::endl;
	std::cin >> input;
	clearInput();
	m_FinalExam = checkInput(input, 30);
}
//Calculate grades will add up all the final theory, practical and overall final grade
void GradeCalculator::calculateGrades()
{
	m_Theory = m_Midterm + m_Test + m_FinalExam;
	m_Practical = m_Lab + m_Assignment + m_FinalPractical;

	m_FinalGrade = m_Theory + m_Practical;
}
//Display grades will display the three final grades to the user
void GradeCalculator::displayGrades()
{
	std::cout << "Your Final Theory mark is: " << m_Theory << ", your final Practical mark: " << m_Practical << ", and your final Grade is: " << m_FinalGrade << std::endl;
}

//check input will check for valid user input using a Regex to check for a number being inputted, and a max Value to make sure the user doesn't input anything over the max grade allowed
double GradeCalculator::checkInput(std::string input, double maxValue)
{
	//Regular expression for type checking input
	std::regex reg("^[0-9]+([.]?[0-9]+)?$");
	double num = -1;

	//First while loop to check for a valid number
	while (0 > num || num > maxValue)
	{
		//Second while loop to check for a valid input using a regex
		while (!std::regex_match(input, reg))
		{
			std::cout << "Error, invalid input" << std::endl;
			std::cin >> input;
			clearInput();
		}

		//If we get here then the input must be valid, convert the string into a double
		num = std::stod(input);
		//Check for out of bounds
		if (0 > num || num > maxValue)
		{
			std::cout << "Mark out of range." << std::endl;
			std::cin >> input;
			clearInput();

		}
		//Number is valid, return it
		else
		{
			return num;
		}
		
	}
}
//Clear input just clears the input so we only take the first string the user inputs
void GradeCalculator::clearInput()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}


