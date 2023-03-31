#pragma once

#include <string>
#include <vector>
#include "Colors.h"

struct
{
	std::vector<std::string> entries1, entries2;
	const int length = 90;
} OutputTool;

template <typename... T>
void Print(T... args)
{
	((std::cout << args << " "), ...);
	std::cout << endl;
}

void PrintInfo(std::string info_line)
{
	std::cout << OutputColor.green << "INFO: " << OutputColor.reset << info_line << endl;
}

void PrintSimpleSeparator(std::string left_edge = "|", 
		std::string body = "-", 
		std::string right_edge = "|")
{
	std::cout << left_edge;
	for (int i = 0; i < OutputTool.length - left_edge.length() - right_edge.length(); i++) std::cout << body;
	std::cout << right_edge << std::endl;
	std::cout << OutputColor.reset;
}

void PrintSeparator(std::string text, 
	std::string color = OutputColor.bold_cyan,
	std::string left_edge = "//", 
	std::string body = "-", 
	std::string right_edge = "//")
{
	std::cout << left_edge;
	for (int i = 0; i < (OutputTool.length - text.length())/2 - left_edge.length() - right_edge.length() - 1; i++) std::cout << body;
	std::cout << right_edge << color << " " << text << " " << OutputColor.reset << left_edge;
	for (int i = 0; i < OutputTool.length - OutputTool.length/2 -text.length()/2. - left_edge.length() - right_edge.length() - 1; i++) std::cout << body;
	std::cout << right_edge << std::endl;
}

void AddBoxEntry(std::string entry1, std::string entry2)
{
	OutputTool.entries1.push_back(entry1);
	OutputTool.entries2.push_back(entry2);
}

void PrintEdgedLine(std::string entry1, std::string entry2,
	std::string left_edge = "|",
	std::string right_edge = "|")
{
	std::cout << left_edge << " " << entry1;
	int space_size = OutputTool.length - entry1.length() - entry2.length() - left_edge.length() - right_edge.length() - 2;
	for (int i = 0; i < space_size; i++) std::cout << " ";
	std::cout << entry2 << " " << right_edge << std::endl;
}

void PrintBox(std::string name = "INFO", 
	std::string color = OutputColor.green,
	std::string left_edge = "|", 
	std::string body = "=", 
	std::string right_edge = "|")
{
	if (OutputTool.entries1.size() == 0) std::cout << "Box cannot be written: number of entries1 is 0" << std::endl;
	
	PrintSimpleSeparator(left_edge, body, right_edge);
	PrintSeparator(name, color, left_edge, " ", right_edge);
	PrintSimpleSeparator(left_edge, body, right_edge);
	
	for (int i = 0; i < OutputTool.entries1.size(); i++)
	{
		PrintEdgedLine(OutputTool.entries1[i], OutputTool.entries2[i], 
			left_edge, right_edge);
	}
	
	PrintSimpleSeparator(left_edge, body, right_edge);

	OutputTool.entries1.clear();
	OutputTool.entries2.clear();
}

void PrintFuncPar(TF1 *func, std::string type, std::string arr_name)
{
	std::cout << type << " " << arr_name << "[" << to_string(func->GetNpar()) << "] = {";
	
	for (int i = 0; i < func->GetNpar(); i++)
	{
		std::cout << func->GetParameter(i);
		if (i != func->GetNpar() - 1) std::cout << ", ";
	}
	
	std::cout << "};" << std::endl;
}

template <typename T>
void PrintArr(T *arr, const int size, std::string name = "")
{
	if (name != "") std::cout << name << "[" << size << "] = ";

	std::cout << "{";
	for (int i = 0; i < size - 1; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[size-1] << "}";

	if (name != "") std::cout << ";";
	Print();
}
